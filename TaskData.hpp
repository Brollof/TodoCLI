#pragma once

#include <string>

struct TaskData
{
    TaskData(std::string task_, std::string created_, bool done_, uint32_t id_ = 0)
    : id(id_), task(task_), created(created_), done(done_) {}
    uint32_t id;
    std::string task;
    std::string created;
    bool done;
};
