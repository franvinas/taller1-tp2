#include "Worker.h"

Worker::Worker(TaskQueue &taskQueue, Dataset &dataset, ResultsMonitor &results) 
                : taskQueue(taskQueue),
                dataset(dataset),
                results(results) {}

void Worker::run() {
    while (!taskQueue.done()) {
        Task &task = taskQueue.front();
        
        if (task.apply(dataset)) {
            std::string result = task.get_result();
            if (!result.empty())
                results.add_result(result);
        } 
    }
}
