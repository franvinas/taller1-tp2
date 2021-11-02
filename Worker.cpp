#include "Worker.h"

Worker::Worker(TaskQueue &taskQueue, Dataset &dataset) 
                : taskQueue(taskQueue),
                dataset(dataset) {}

void Worker::run() {
    while (!taskQueue.done()) {
        Task &task = taskQueue.front();
        
        if (task.apply(dataset)) {
            task.print_result(); 
        } 
    }
}
