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
    // doc.Clear();
    doc.InsertRow<std::string>(-1, {"ID", "Task", "Created", "Done"});
    // doc.InsertRow<std::string>(0, {"a", "b", "c", "d"});
    // doc.InsertRow<std::string>(1, {"a", "b", "c", "d"});
    // doc.InsertRow<std::string>(2, {"a", "b", "c", "d"});
    // doc.InsertRow<std::string>(3, {"a", "b", "c", "d"});
    doc.Save();

    for (size_t i = 0; i < m_data.size(); i++)
    {
        const TaskData &row = m_data[i];
        std::cout << "Saving row: " << row.id << ","
        << row.task << ","
        << row.created << ","
        << row.done << std::endl;

        // doc.InsertRow<TaskData>(i);
        doc.SetCell<unsigned long>("ID", i, row.id);
        doc.SetCell<std::string>("Task", i, row.task);
        doc.SetCell<std::string>("Created", i, row.created);
        doc.SetCell<unsigned long>("Done", i, row.done);
    }

    doc.Save();
}