#include "Printer.hpp"
#include "Time.hpp"

void Printer::Row(const AllTasks &data, uint32_t id)
{
    tabulate::Table tab;
    tab.add_row({"ID", "Task", "Created", "Done"});

    for (const auto &row : data)
    {
        if (id == row.id)
        {
            Printer::AddRow(tab, row);
            break;
        }
    }

    std::cout << tab << std::endl;
}

void Printer::All(const AllTasks &data)
{
    tabulate::Table tab;
    tab.add_row({"ID", "Task", "Created", "Done"});

    for (const auto &row : data)
    {
        AddRow(tab, row);
    }

    std::cout << tab << std::endl;
}

void Printer::AddRow(tabulate::Table &tab, const TaskData &row)
{
    tab.add_row(
        {std::to_string(row.id),
        row.task,
        Time::GetTimeStringUntilNow(row.created),
        row.done ? "true" : "false"
    });
}
