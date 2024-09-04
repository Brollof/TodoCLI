#include <iostream>
#include <string>
#include <vector>

#include "libs/CLI11/CLI11.hpp"
#include "TaskData.hpp"
#include "CSVFile.hpp"
#include "Todo.hpp"

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
    Todo todoList(csv);

    if (*add && !task_desc.empty())
    {
        TaskData row = {task_desc, "22:02", false};
        todoList.AppendRow(row);
        todoList.Save();
    }
    else if (*list)
    {
        auto &data = csv.GetData();
        cout << "LIST" << endl;
        print_table(data);
    }

    return 0;
}

