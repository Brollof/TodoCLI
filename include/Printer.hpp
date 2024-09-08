#pragma once

#include <cstdint>

#include "TaskData.hpp"

class Printer
{
public:
    static void All(const AllTasks &data);
    static void AllWithDone(const AllTasks &data);
    static void Row(const AllTasks &data, uint32_t id);
    static void RowWithDone(const AllTasks &data, uint32_t id);

private:
    Printer() = delete;
};
