#include "PartitionThread.h"
#include <utility>

PartitionThread::PartitionThread(Partition &partition, Task &task) 
                                : partition(std::move(partition)),
                                task(task) {}

PartitionThread::PartitionThread(PartitionThread&& other) 
                                 : Thread(std::move(other)), 
                                 partition(std::move(other.partition)), 
                                 task(other.task) {}

PartitionThread& PartitionThread::operator=(PartitionThread&& other) {
    if (this == &other)
        return *this;

    Thread::operator=(std::move(other));
    this->partition = std::move(other.partition);
    this->task = std::move(other.task);

    return *this;
}

void PartitionThread::run() {
    task.apply(partition);
}

