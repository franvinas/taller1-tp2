#include "TaskQueue.h"
#include <string>
#include <iostream>

TaskQueue::TaskQueue() : current_task(0) {}

Task &TaskQueue::front() {
    std::lock_guard<std::mutex> lock(this->mutex);

    if (this->task_queue.empty()) throw -1;
    
    while (this->task_queue.at(this->current_task).done()) {
        this->current_task++;
        if (task_queue.size() == this->current_task) break;
    }
    return this->task_queue.at(this->current_task);
}

bool TaskQueue::empty() {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::string task_str;
    if (std::getline(std::cin, task_str)) {
        task_queue.push_back(Task(task_str));
    }

    if (this->task_queue.size() <= this->current_task) return true;

    while (this->task_queue.at(this->current_task).done()) {
        this->current_task++;
        if (task_queue.size() == this->current_task) break;
    }
    return this->task_queue.size() <= this->current_task;
}
