#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include "Task.h"
#include "Dataset.h"
#include <string>
#include <mutex>
#include <deque>

class TaskQueue {
private:
    std::deque<std::string> task_str_queue;
    std::deque<Task> task_queue;
    size_t current_task;
    std::mutex mutex;
public:
    TaskQueue();
    // Task get_new_task();
    Task &front();
    bool empty();
    // void pop();
    void apply_front(Dataset &dataset);
    // int read_task();
};

#endif
