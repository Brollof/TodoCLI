#include <filesystem>
#include <fstream>
#include <iostream>

#include "CSVFile.hpp"
#include "rapidcsv/src/rapidcsv.h"

CSVFile::CSVFile(const std::string &filename) : m_filename(filename)
{
    // Create file if it doesn't exist
    if (std::filesystem::exists(m_filename) == false)
    {
        std::ofstream output(m_filename);
    }

    std::cout << "csv file: " << m_filename << std::endl;

    rapidcsv::Document doc(m_filename);

    for (size_t i = 0; i < doc.GetRowCount(); i++)
    {
        unsigned long id = doc.GetCell<unsigned long>("ID", i);
        std::string task = doc.GetCell<std::string>("Task", i);
        std::string created = doc.GetCell<std::string>("Created", i);
        unsigned long done = doc.GetCell<unsigned long>("Done", i);
        m_data.push_back({task, created, static_cast<bool>(done), static_cast<uint32_t>(id)});
    }
}

AllTasks &CSVFile::GetData()
{
    return m_data;
}

void CSVFile::Save() const
{
    rapidcsv::Document doc(m_filename);
    doc.Clear();
    doc.InsertRow<std::string>(-1, CSVFile::GetLabels());

    for (size_t i = 0; i < m_data.size(); i++)
    {
        const TaskData &row = m_data[i];

        const std::vector<std::string> line =
        {
            std::to_string(row.id),
            row.task,
            row.created,
            std::to_string(row.done)
        };

        doc.InsertRow<std::string>(i, line);
    }

    doc.Save();
}
