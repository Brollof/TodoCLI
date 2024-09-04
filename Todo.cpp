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
    // doc.SetCell<unsigned long>("ID", row.id, row.id);
    // doc.SetCell<string>("Task", row.id, row.task);
    // doc.SetCell<string>("Created", row.id, row.created);
    // doc.SetCell<unsigned long>("Done", row.id, row.done);
    // doc.Save();
}


uint32_t Todo::GetNextID() const
{
    const auto &data = m_store.GetData();
    if (data.size() == 0)
    {
        return 0;
    }

    return data.back().id;
}
