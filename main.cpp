#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "CLI11.hpp"
#include "rapidcsv/src/rapidcsv.h"

using namespace std;
namespace fs = std::filesystem;

#define CSV_FILENAME "todo.csv"

using Labels = vector<string>;

struct Data
{
    Data(uint32_t id_, string task_, string created_, bool done_)
    : id(id_), task(task_), created(created_), done(done_) {}
    uint32_t id;
    string task;
    string created;
    bool done;
};

class Storer
{
public:
    virtual void AppendRow(const Data &row) = 0;
    virtual uint32_t GetNextID() const = 0;
    virtual ~Storer() {};

protected:
    vector<Data> m_data;
    uint32_t m_next_id;
};

class CSVFile : public Storer
{
public:
    CSVFile(const string &filename) : m_filename(filename)
    {
        // Create file if it doesn't exist
        if (fs::exists(m_filename) == false)
        {
            ofstream output(m_filename);
        }

        cout << "csv file: " << m_filename << endl;

        rapidcsv::Document doc(m_filename);

        for (size_t i = 0; i < doc.GetRowCount(); i++)
        {
            unsigned long id = doc.GetCell<unsigned long>("ID", i);
            string task = doc.GetCell<string>("Task", i);
            string created = doc.GetCell<string>("Created", i);
            unsigned long done = doc.GetCell<unsigned long>("Done", i);
            m_data.push_back({static_cast<uint32_t>(id), task, created, static_cast<bool>(done)});
        }

        m_next_id = m_data.back().id + 1;
    }

    void AppendRow(const Data &row) override
    {
        rapidcsv::Document doc(m_filename);
        doc.SetCell<unsigned long>("ID", row.id, row.id);
        doc.SetCell<string>("Task", row.id, row.task);
        doc.SetCell<string>("Created", row.id, row.created);
        doc.SetCell<unsigned long>("Done", row.id, row.done);
        doc.Save();
    }

    uint32_t GetNextID() const override
    {
        return m_next_id;
    }

    vector<Data> &GetData()
    {
        return m_data;
    }

    static const Labels GetLabels()
    {
        return {"ID", "Task", "Created", "Done"};
    }

private:
    CSVFile() = delete;
    const string m_filename;
};

static void print_table(const vector<Data> &data)
{
    for (const string &lab : CSVFile::GetLabels())
    {
        cout << lab << "       ";
    }

    cout << endl;

    for (const auto &row : data)
    {
        cout << row.id << "   " <<
        row.task << "   " <<
        row.created << "   " <<
        row.done << endl;
    }
}

int main(int argc, char** argv)
{
    CLI::App app{"App description"};
    app.require_subcommand();

    string task_desc = "";
    uint32_t num = -1;

    CLI::App *add = app.add_subcommand("add", "add a new task");
    add->add_option("task", task_desc)->required();

    CLI::App *list = app.add_subcommand("list", "show undone tasks");
    list->add_flag("--all", "show all tasks");

    CLI::App *complete = app.add_subcommand("complete", "complete task");
    complete->add_option("ID", num, "task ID")->required();


    CLI11_PARSE(app, argc, argv);

    CSVFile csv(CSV_FILENAME);

    if (*add && !task_desc.empty())
    {
        csv.AppendRow({csv.GetNextID(), task_desc, "22:02", false});
    }
    else if (*list)
    {
        auto &data = csv.GetData();
        cout << "LIST" << endl;
        print_table(data);
    }





    return 0;
}

