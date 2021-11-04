#include "WorkersHub.h"
#include "Worker.h"
#include <utility>

WorkersHub::WorkersHub(int n_workers, 
                       TaskQueue &taskQueue,
                       Dataset &dataset,
                       ResultsMonitor &results) : n_workers(n_workers) {
    for (int i = 0; i < n_workers; i++)
        workers.push_back(std::move(Worker(taskQueue, dataset, results)));
}

void WorkersHub::start_all() {
    for (int i = 0; i < this->n_workers; i++)
        workers.at(i).start();
}

void WorkersHub::join_all() {
    for (int i = 0; i < n_workers; i++)
        workers.at(i).join();
}
