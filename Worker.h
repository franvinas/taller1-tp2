#ifndef WORKER_H
#define WORKER_H

#include "Thread.h"
#include "TaskQueue.h"
#include "Dataset.h"

/*
 *  Worker hereda de Thread e implementa run().
 */
class Worker: public Thread {
private:
    TaskQueue &taskQueue;
    Dataset &dataset;    
    
protected:
    void run() override;

public:
    Worker(TaskQueue &taskQueue, Dataset &dataset);

    // Worker(Worker&& other);

    // Worker& operator=(Worker&& other);

    // ~Worker();
};

#endif
