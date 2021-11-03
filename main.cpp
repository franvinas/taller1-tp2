#include <iostream>
#include <string>
#include "Dataset.h"
#include "TaskQueue.h"
#include "WorkersHub.h"
#include "ResultsMonitor.h"

int main(int argc, const char *argv[]) {
    if (argc != 4) {
        std::cerr << "Error en la cantidad de argumentos\n"
        << "Para ejecutar:\n"
        << "./tp <dataset> <columns> <workers>\n";
        return 1;
    }

    std::string file_name = argv[1];

    int columns = atoi(argv[2]);
    int n_workers = atoi(argv[3]);    
    
    try {
        TaskQueue taskQueue;
        Dataset dataset(file_name, columns);
        ResultsMonitor results;

        WorkersHub workers(n_workers, taskQueue, dataset, results);

        workers.start_all();
        taskQueue.read_tasks();
        workers.join_all();
        results.print_results();        
    } catch(...) {
        return 1;
    } 
    
    return 0;
}
