#ifndef WORKER_H
#define WORKER_H

#include "Thread.h"
#include "TaskQueue.h"
#include "Dataset.h"
#include "ResultsMonitor.h"

/*
 *  Worker hereda de Thread e implementa run().
 *  Todas las instancias Worker tienen una referencia a la taskQueue y
 *  al dataset. Notar que tanto el taskQueue como el dataset son los 
 *  mismos para todas los Workers.
 */
class Worker: public Thread {
private:
    TaskQueue &taskQueue;
    Dataset &dataset;
    ResultsMonitor &results;
    
protected:
    /*
     *  Se busca por el siguiente Task que no fue analizado completamente
     *  y se aplica la operacion correspondiente para dicho Task en la
     *  siguiente particion. Una vez que ya fueron analizados todos los
     *  Tasks la funcion retorna.
     */
    void run() override;

public:
    /*
     *  Constructor
     */
    Worker(TaskQueue &taskQueue, Dataset &dataset, ResultsMonitor &results);
};

#endif
