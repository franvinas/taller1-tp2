#ifndef WORKERS_HUB_H
#define WORKERS_HUB_H

#include "Worker.h"
#include <vector>

class WorkersHub {
protected:
    std::vector<Worker> workers;
    int n_workers;
public:
    /*
     *  Constructor
     */
    WorkersHub(int n_workers, 
               TaskQueue &taskQueue,
               Dataset &dataset,
               ResultsMonitor &ResultsMonitor);
    /*
     *  Inicia la ejecucion de todos los workers
     */
    void start_all();
    /*
     *  Se hace join() a cada worker
     */
    void join_all();
};

#endif
