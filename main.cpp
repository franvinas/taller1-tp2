#include <iostream>
#include <string>
#include <vector>
#include "Task.h"
#include "Dataset.h"
#include "TaskQueue.h"
#include "Worker.h"

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

        for (int i = 0; i < n_workers; i++)
            workers.push_back(std::move(Worker(taskQueue, dataset)));

        for (int i = 0; i < n_workers; i++)
            workers.at(i).start();

        for (int i = 0; i < n_workers; i++)
            workers.at(i).join();
    } catch(...) {
        return 1;
    } 
    
    return 0;
}
