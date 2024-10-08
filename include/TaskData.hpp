#pragma once

#include <string>
#include <vector>

struct TaskData;
using AllTasks = std::vector<TaskData>;

struct TaskData
{
    TaskData(std::string task_, uint32_t created_, bool done_, uint32_t id_ = 0)
    : task(task_), created(created_), done(done_), id(id_) {}
    std::string task;
    uint32_t created;
    bool done;
    uint32_t id;
};
