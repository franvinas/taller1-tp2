#include <iostream>
#include <string>
#include <vector>
#include "Dataset.h"
#include "TaskQueue.h"
#include "Worker.h"
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
        std::vector<Worker> workers;
        ResultsMonitor results;

        for (int i = 0; i < n_workers; i++)
            workers.push_back(std::move(Worker(taskQueue, dataset, results)));

        for (int i = 0; i < n_workers; i++)
            workers.at(i).start();

        taskQueue.read_tasks();

        for (int i = 0; i < n_workers; i++)
            workers.at(i).join();
        
        results.print_results();
    } catch(...) {
        return 1;
    } 
    
    return 0;
}
