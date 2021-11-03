#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include "Task.h"
#include <mutex>
#include <deque>
#include <condition_variable>

class TaskQueue {
private:
    std::deque<Task> task_queue;
    size_t current_task;
    bool closed;
    std::condition_variable cv;
    std::mutex mutex;
    bool empty();
    void close();

public:
    /*
     *  Constructor
     */
    TaskQueue();
    /*
     *  Devuelve una referencia al primer Task con particiones a analizar
     */
    Task &front();
    /*
     *  Devuelve true si ya se analizaron todos los Tasks con todas
     *  sus particiones.
     *  Sino devuelve false.
     */
    bool done();
    /*
     *  Lee de entrada estandar las tareas a realizar y las encola como
     *   instancias de Task en task_queue.
     */
    void read_tasks();
};

#endif
