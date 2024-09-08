#include "Todo.hpp"
#include "Printer.hpp"

Todo::Todo(StoreInterface<TaskData> &store) :
    m_store(store), m_data(m_store.GetData())
{

}

uint32_t Todo::AppendRow(TaskData &row)
{
    row.id = GetNextID();
    m_data.push_back(row);
    return row.id;
}

void Todo::Save() const
{
    m_store.Save();
}

uint32_t Todo::GetNextID() const
{
    if (m_data.size() == 0)
    {
        return 0;
    }

    return m_data.back().id + 1;
}

bool Todo::RemoveItem(uint32_t id)
{
    int32_t index = -1;

    for (uint32_t i = 0; i < m_data.size(); i++)
    {
        if (id == m_data[i].id)
        {
            index = i;
            break;
        }
    }

    if (index >= 0)
    {
        m_data.erase(m_data.begin() + index);
        m_store.Save();
        return true;
    }

    return false;
}

bool Todo::MarkAsComplete(uint32_t id)
{
    for (TaskData &row : m_data)
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

void Todo::PrintRow(uint32_t id)
{
    Printer::Row(m_data, id);
}

void Todo::PrintAll()
{
    Printer::All(m_data);
}
