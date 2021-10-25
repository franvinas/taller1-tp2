#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include "Task.h"
#include <mutex>
#include <deque>

class TaskQueue {
private:
    std::deque<Task> task_queue;
    size_t current_task;
    std::mutex mutex;
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
    bool empty();
};

#endif
