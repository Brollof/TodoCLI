#pragma once

#include "TaskData.hpp"
#include "CSVFile.hpp"

class Todo
{
public:
    Todo(StoreInterface<TaskData> &store);
    void AppendRow(TaskData &row);
    uint32_t GetNextID() const;
    void Save() const;
    bool RemoveItem(uint32_t id);
    bool MarkAsComplete(uint32_t id);

private:
    Todo() = delete;
    StoreInterface<TaskData> &m_store;
};