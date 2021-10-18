#ifndef PARTITION_THREAD_H
#define PARTITION_THREAD_H

#include "thread.h"
#include "task.h"
#include "partition.h"

/*
 *  PartitionThread hereda de Thread e implementa run().
 */
class PartitionThread: public Thread {
private:
    Partition *partition;
    Task &task;
    
protected:
    void run() override;

public:
    PartitionThread(Partition *partition, Task &task);

    PartitionThread(PartitionThread&& other);

    PartitionThread& operator=(PartitionThread&& other);

    ~PartitionThread();
};

#endif
