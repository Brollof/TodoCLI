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

bool Todo::RemoveItem(uint32_t id)
{
    int32_t index = -1;
    auto &data = m_store.GetData();

    for (uint32_t i = 0; i < data.size(); i++)
    {
        if (id == data[i].id)
        {
            index = i;
            break;
        }
    }

    if (index >= 0)
    {
        data.erase(data.begin() + index);
        m_store.Save();
        return true;
    }

    return false;
}

bool Todo::MarkAsComplete(uint32_t id)
{
    auto data = m_store.GetData();
    for (TaskData &row : m_store.GetData())
    {
        if (id == row.id)
        {
            row.done = true;
            m_store.Save();
            return true;
        }
    }
    return false;
}
