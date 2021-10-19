#include "taskqueue.h"
#include "taskattributes.h"
#include <string>
#include <iostream>

TaskQueue::TaskQueue() {}

Task TaskQueue::get_new_task() {
    TaskAttributes taskAttributtes(task_str);
    
    return Task(taskAttributtes);
}

bool TaskQueue::read_task() {
    return !(std::getline(std::cin, task_str));
}
