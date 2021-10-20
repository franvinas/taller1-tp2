#include "taskqueue.h"
#include "taskattributes.h"
#include <string>
#include <iostream>

TaskQueue::TaskQueue() {}

Task TaskQueue::get_new_task() {
    return Task(task_str);
}

bool TaskQueue::read_task() {
    return !(std::getline(std::cin, task_str));
}
