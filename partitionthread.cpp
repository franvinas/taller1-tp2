#include "partitionthread.h"

PartitionThread::PartitionThread(Partition *partition, Task &task) 
                                : partition(partition),
                                task(task) {}

PartitionThread::PartitionThread(PartitionThread&& other) 
                                 : Thread(std::move(other)), 
                                 partition(std::move(other.partition)), 
                                 task(other.task) {
    other.partition = nullptr;
}

PartitionThread& PartitionThread::operator=(PartitionThread&& other) {
    if (this == &other)
        return *this;

    Thread::operator=(std::move(other));
    this->partition = std::move(other.partition);
    this->task = std::move(other.task);

    other.partition = nullptr;

    return *this;
}

void PartitionThread::run() {
    task.apply(*partition);
}

PartitionThread::~PartitionThread() {
    delete this->partition;
}
