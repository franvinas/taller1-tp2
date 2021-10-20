#include <iostream>
#include <string>
#include <deque>
#include <optional>
#include "task.h"
#include "dataset.h"
#include "partitionthread.h"
#include "taskqueue.h"

int main(int argc, const char *argv[]) {
    int columns = 0;
    // int workers = 0;
    std::string task_str;

    if (argc != 4) {
        std::cout << "Error en la cantidad de argumentos\n";
        std::cout << "Para ejecutar:\n";
        std::cout << "./tp <dataset> <columns> <workers>\n";
        return -1;
    }

    std::string file_name = argv[1];

    columns = atoi(argv[2]);
    // workers = atoi(argv[3]);    
    
    TaskQueue taskQueue;
    // Task task;
    while ( !taskQueue.read_task() ) {

        Task task = std::move(taskQueue.get_new_task());

        Dataset dataset(file_name, columns);
        
        std::deque<PartitionThread> thread_queue;
        while (!task.done()) {
            PartitionMetadata partitionMetadata = task.new_partition_metadata();
            Partition partition = std::move(dataset.read_partition(partitionMetadata));
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
