#pragma once

#include <vector>

#include "StoreInterface.hpp"
#include "TaskData.hpp"

using Labels = std::vector<std::string>;
using AllTasks = std::vector<TaskData>;

class CSVFile : public StoreInterface<TaskData>
{
public:
    CSVFile(const std::string &filename);
    AllTasks &GetData() override;
    void Save() const override;

    static const Labels GetLabels()
    {
        return {"ID", "Task", "Created", "Done"};
    }

private:
    CSVFile() = delete;
    const std::string m_filename;
};