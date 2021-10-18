/* ************************************************************************* *
 * SPAWN - CUARTA TECNICA: template method (The Java way)
 * ************************************************************************* */

// Poné una documentación acorde y aclará que usás nuestra clase Thread

#include <iostream>
#include <thread>
#include "task.h"
#include "dataset.h"
#include "partition.h"

/**
 * @brief      Abstract class wrapping a thread. It catches exceptions in order
 *             to avoid crashes with confusing messages.
 *             
 *             User should extend this class and implement the run() method with
 *             the behavior to be executed in a new thread.
 */
class Thread {
private:
    std::thread t;

    // This template method catches exceptions (they can't be caught from main)
    void runExpecting();

protected:
    virtual void run() = 0;

public:
    /**
     * @brief      Starts a thread with the behavior of the method run().
     */
    void start();

    /**
     * @brief      Waits the thread to finish.
     */
    void join();
    Thread() {}

    Thread(Thread &&other);

    Thread& operator=(Thread&& other);

    virtual ~Thread() = default;
};


// Esto movelo a otro archivo
/*
 *  PartitionThread hereda de Thread e implementa run().
 */
class PartitionThread: public Thread {
private:
    // Mejor recibir esta partition por movimiento
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
