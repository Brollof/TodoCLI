#include <iostream>
#include <string>
#include <vector>

#include "libs/CLI11/CLI11.hpp"
#include "TaskData.hpp"
#include "CSVFile.hpp"
#include "Todo.hpp"
#include "Time.hpp"

#define CSV_FILENAME "todo.csv"

using namespace std;

static void print_table(const vector<TaskData> &data)
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
        Time::GetTimeStringUntilNow(row.created) << "   " <<
        row.done << endl;
    }
}

int main(int argc, char** argv)
{
    CLI::App app{"App description"};
    app.require_subcommand();

    string taskDesc = "";
    uint32_t id = 0;

    CLI::App *add = app.add_subcommand("add", "add a new task");
    add->add_option("task", taskDesc)->required();

    CLI::App *list = app.add_subcommand("list", "show undone tasks");
    list->add_flag("--all", "show all tasks");

    CLI::App *complete = app.add_subcommand("complete", "complete task");
    complete->add_option("ID", id, "task ID")->required();

    CLI::App *del = app.add_subcommand("delete", "delete a task");
    del->add_option("ID", id, "task ID")->required();

    CLI11_PARSE(app, argc, argv);

    CSVFile csv(CSV_FILENAME);
    Todo todoList(csv);
    auto &data = csv.GetData();

    if (*add && !taskDesc.empty())
    {
        TaskData row = {taskDesc, Time::GetNow(), false};
        todoList.AppendRow(row);
        todoList.Save();
    }
    else if (*complete)
    {
        if (todoList.MarkAsComplete(id))
        {
            print_table(data);
        }
        else
        {
            cout << "Couldn't complete task with ID = " << id << "." << endl;
        }
    }
    else if (*del)
    {
        if (todoList.RemoveItem(id))
        {
            print_table(data);
        }
        else
        {
            cout << "Couldn't delete task with ID = " << id << "." << endl;
        }
    }
    else if (*list)
    {
        cout << "LIST" << endl;
        print_table(data);

        // From time point to epoch
        // const auto now = chrono::system_clock::now();
        // auto now_s = std::chrono::time_point_cast<std::chrono::seconds>(now);
        // uint32_t epoch_now = now_s.time_since_epoch().count();

        // uint32_t epoch_old = 1725304015;

        // auto tp_now = epoch_to_time_point(epoch_now);
        // cout << "Now: ";
        // print_time_point(tp_now);

        // auto tp_old = epoch_to_time_point(epoch_old);
        // cout << "Old: ";
        // print_time_point(tp_old);

        // GetTimeText(tp_old, tp_now);
    }

    return 0;
}

