#include "Todo.hpp"

Todo::Todo(StoreInterface<TaskData> &store) : m_store(store)
{
}


void Todo::AppendRow(TaskData &row)
{
    row.id = GetNextID();
    m_store.GetData().push_back(row);
}

void Todo::Save() const
{
    m_store.Save();
}


uint32_t Todo::GetNextID() const
{
    const auto &data = m_store.GetData();
    if (data.size() == 0)
    {
        return 0;
    }

    return data.back().id + 1;
}
