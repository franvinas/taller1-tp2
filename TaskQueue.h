#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include "Task.h"
#include <string>

class TaskQueue {
private:
    std::string task_str;
public:
    TaskQueue();
    Task get_new_task();
    bool read_task();
};

#endif
