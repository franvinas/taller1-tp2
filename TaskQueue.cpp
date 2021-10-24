#include "TaskQueue.h"
#include <string>
#include <iostream>

TaskQueue::TaskQueue() : current_task(0) {}

// Task TaskQueue::get_new_task() {
//     std::lock_guard<std::mutex> lock(this->mutex);
//     if (this->task_str_queue.empty()) throw -1;

//     std::string task_str = this->task_str_queue.front();
    
//     this->task_str_queue.pop_front();
//     return Task(task_str);
// }

Task &TaskQueue::front() {
    std::lock_guard<std::mutex> lock(this->mutex);

    if (this->task_queue.empty()) {
        return this->task_queue.front();
    }
    
    while (this->task_queue.at(this->current_task).done()) {
        if (task_queue.size() == this->current_task + 1) break;
        this->current_task++;
    }
    return this->task_queue.at(this->current_task);
    // for (size_t i = 0; i < task_queue.size(); i++) {
    //     if (!this->task_queue.at(i).done()) return this->task_queue.at(i);
    // }
    // throw -1;
//    return this->task_queue.front();
}

// void TaskQueue::pop() {
//     if (this->task_queue.empty()) throw -1;
    
//     this->task_queue.pop_front();
// }

// bool TaskQueue::empty() {

// }

bool TaskQueue::empty() {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::string task_str;
    if (std::getline(std::cin, task_str)) {
        task_str_queue.push_back(task_str);
        task_queue.push_back(Task(task_str));
    }

    if (this->task_queue.size() <= this->current_task) return true;

    while (this->task_queue.at(this->current_task).done()) {
        this->current_task++;
        if (task_queue.size() == this->current_task) break;
    }
    return this->task_queue.size() <= this->current_task;
    // return task_queue.size();

    // for (size_t i = 0; i < task_queue.size(); i++) {
    //     if (!this->task_queue.at(i).done()) return 1;
    // }
    // return task_queue.size() - this->current_task;
}

// void TaskQueue::apply_front(Dataset &dataset) {
    
    
//     if (task_queue.front().partitions_left() == 0) {
//         task_queue.front().print_result();
//         task_queue.pop_front();
//     }
    
//     // if (task_queue.front().apply(dataset)) {
//     //     task_queue.front().print_result();
//     //     task_queue.pop_front();
//     // } 
// }
