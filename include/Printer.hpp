#pragma once

#include <cstdint>

#include "tabulate/tabulate.hpp"
#include "TaskData.hpp"

class Printer
{
public:
    static void All(const AllTasks &data);
    static void Row(const AllTasks &data, uint32_t id);

private:
    Printer() = delete;
    static void AddRow(tabulate::Table &tab, const TaskData &row);
};
