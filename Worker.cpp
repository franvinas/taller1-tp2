#include "Worker.h"
#include "PartitionMetadata.h"
#include "Task.h"

Worker::Worker(TaskQueue &taskQueue, Dataset &dataset) 
                : taskQueue(taskQueue),
                dataset(dataset) {}

void Worker::run() {
    while (!taskQueue.empty()) {
        Task &task = taskQueue.front();
        
        if (task.apply(dataset)) {
            task.print_result(); 
        } 
    }
}
