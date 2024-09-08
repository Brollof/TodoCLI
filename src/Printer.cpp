#include "Printer.hpp"
#include "tabulate/tabulate.hpp"
#include "Time.hpp"

void Printer::Row(const AllTasks &data, uint32_t id)
{
    tabulate::Table tab;
    tab.add_row({"ID", "Task", "Created"});

    for (const auto &row : data)
    {
        if (id == row.id)
        {
            tab.add_row(
                {std::to_string(row.id),
                row.task,
                Time::GetTimeStringUntilNow(row.created)
            });
            break;
        }
    }

    std::cout << tab << std::endl;
}

void Printer::RowWithDone(const AllTasks &data, uint32_t id)
{
    tabulate::Table tab;
    tab.add_row({"ID", "Task", "Created", "Done"});

    for (const auto &row : data)
    {
        if (id == row.id)
        {
            tab.add_row(
                {std::to_string(row.id),
                row.task,
                Time::GetTimeStringUntilNow(row.created),
                row.done ? "true" : "false"
            });
            break;
        }
    }

    std::cout << tab << std::endl;
}

void Printer::All(const AllTasks &data)
{
    tabulate::Table tab;
    tab.add_row({"ID", "Task", "Created"});

    for (const auto &row : data)
    {
        tab.add_row(
            {std::to_string(row.id),
            row.task,
            Time::GetTimeStringUntilNow(row.created)
        });
    }

    std::cout << tab << std::endl;
}

void Printer::AllWithDone(const AllTasks &data)
{
    tabulate::Table tab;
    tab.add_row({"ID", "Task", "Created", "Done"});

    for (const auto &row : data)
    {
        tab.add_row(
            {std::to_string(row.id),
            row.task,
            Time::GetTimeStringUntilNow(row.created),
            row.done ? "true" : "false"
        });
    }

    std::cout << tab << std::endl;
}
