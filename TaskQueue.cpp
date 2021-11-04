#include "TaskQueue.h"
#include <string>
#include <iostream>

/***********************
    Metodos privados
************************/

bool TaskQueue::empty() {
    if (this->task_queue.size() <= this->current_task) return true;

    while (this->task_queue.at(this->current_task).done()) {
        this->current_task++;
        if (task_queue.size() == this->current_task) break;
    }
    return this->task_queue.size() <= this->current_task;
}

void TaskQueue::close() {
    std::unique_lock<std::mutex> Uniquelock(this->mutex);
    this->closed = true;
    this->cv.notify_all();
}

/***********************
    Metodos publicos
************************/

TaskQueue::TaskQueue() : current_task(0), closed(false) {}

Task &TaskQueue::front() {
    std::unique_lock<std::mutex> uniqueLock(this->mutex);
    while (this->empty() && !this->closed) {
        cv.wait(uniqueLock);
    }
    while (this->task_queue.at(this->current_task).done()) {
        this->current_task++;
        if (task_queue.size() == this->current_task) break;
    }
    return this->task_queue.at(this->current_task);
}

void TaskQueue::read_tasks() {
    std::string task_str;
    while (std::getline(std::cin, task_str)) {
        std::unique_lock<std::mutex> Uniquelock(this->mutex);
        task_queue.push_back(std::move(Task(task_str)));
        cv.notify_all();
    }
    this->close();
}

bool TaskQueue::done() {
    std::unique_lock<std::mutex> Uniquelock(this->mutex);
    return this->empty() && this->closed;
}
