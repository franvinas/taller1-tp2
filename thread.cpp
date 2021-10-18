#include <iostream>
#include <thread>
#include "thread.h"

// This template method catches exceptions (they can't be caught from main)
void Thread::runExpecting() {
    try {
        run();
    } catch(const std::exception &e) {
        std::cerr << "Exception caught in a thread: '" 
                  << e.what() << "'" << std::endl;
    } catch(...) {
        std::cerr << "Unknown error caught in thread" << std::endl;
    }
}

void Thread::start() {
    t = std::thread(&Thread::runExpecting, this);
}

void Thread::join() {
    t.join();
}

Thread::Thread(Thread &&other) : t(std::move(other.t)) {}

Thread& Thread::operator=(Thread&& other) {
    if (this == &other)
        return *this;
    
    this->t = std::move(other.t);

    return *this;
}


void PartitionThread::run() {
    task.apply(*partition);
}

PartitionThread::PartitionThread(Partition *partition, Task &task) :
    partition(partition),
    task(task) {
}

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

PartitionThread::~PartitionThread() {
    delete this->partition;
}
