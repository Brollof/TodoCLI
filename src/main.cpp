#include <iostream>
#include <string>

#include "CLI11/CLI11.hpp"
#include "TaskData.hpp"
#include "CSVFile.hpp"
#include "Todo.hpp"
#include "Time.hpp"

#define CSV_FILENAME "todo.csv"

using namespace std;

int main(int argc, char** argv)
{
    CLI::App app{"App description"};
    app.require_subcommand();

    string taskDesc = "";
    uint32_t id = 0;

    CLI::App *add = app.add_subcommand("add", "add a new task");
    add->add_option("task", taskDesc)->required();

    CLI::App *list = app.add_subcommand("list", "show undone tasks");

    CLI::App *complete = app.add_subcommand("complete", "complete task");
    complete->add_option("ID", id, "task ID")->required();

    CLI::App *del = app.add_subcommand("delete", "delete a task");
    del->add_option("ID", id, "task ID")->required();

    CLI11_PARSE(app, argc, argv);

    CSVFile csv(CSV_FILENAME);
    Todo todoList(csv);

    if (*add)
    {
        TaskData row = {taskDesc, Time::GetNow(), false};
        uint32_t id = todoList.AppendRow(row);
        todoList.Save();
        todoList.PrintRow(id);
    }
    else if (*complete)
    {
        if (todoList.MarkAsComplete(id))
        {
            todoList.PrintRow(id);
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
            todoList.PrintAll();
        }
        else
        {
            cout << "Couldn't delete task with ID = " << id << "." << endl;
        }
    }
    else if (*list)
    {
        todoList.PrintAll();
    }

    return 0;
}
