#pragma once

#include "TaskData.hpp"
#include "CSVFile.hpp"

class Todo
{
public:
    Todo(StoreInterface<TaskData> &store);
    uint32_t AppendRow(TaskData &row);
    void Save() const;
    bool RemoveItem(uint32_t id);
    bool MarkAsComplete(uint32_t id);
    void PrintRow(uint32_t id);
    void PrintAll();

private:
    Todo() = delete;
    StoreInterface<TaskData> &m_store;
    AllTasks &m_data;

    uint32_t GetNextID() const;
};
