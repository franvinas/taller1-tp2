#include <iostream>
#include <string>
#include <deque>
#include <optional>
#include "Task.h"
#include "Dataset.h"
#include "PartitionThread.h"
#include "TaskQueue.h"

int main(int argc, const char *argv[]) {
    if (argc != 4) {
        std::cout << "Error en la cantidad de argumentos\n";
        std::cout << "Para ejecutar:\n";
        std::cout << "./tp <dataset> <columns> <workers>\n";
        return -1;
    }

    std::string file_name = argv[1];

    int columns = atoi(argv[2]);
    // int workers = atoi(argv[3]);    
    
    TaskQueue taskQueue;
    
    while (!taskQueue.read_task()) {
        Task task = std::move(taskQueue.get_new_task());

        Dataset dataset(file_name, columns);
        
        std::deque<PartitionThread> thread_queue;
        while (!task.done()) {
            PartitionMetadata pMetadata = task.new_partition_metadata();
            Partition partition = std::move(dataset.read_partition(pMetadata));
            PartitionThread partition_thread(partition, task);
            thread_queue.push_back(std::move(partition_thread));
            thread_queue.back().start();
        }
        
        while (!thread_queue.empty()) {
            thread_queue.front().join();
            thread_queue.pop_front();
        }

        task.print_result();
    }
    
    return 0;
}
