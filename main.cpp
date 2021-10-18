#include <iostream>
#include <string>
#include <deque>
#include "task.h"
#include "dataset.h"
#include "partitionthread.h"
#include "taskparser.h"


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
    
    while (std::getline(std::cin, task_str)) {
        TaskParser parser(task_str);
        int start_range = parser.get_start_range();
        int end_range = parser.get_end_range();
        int partition_rows = parser.get_partition_rows();
        int column = parser.get_column();
        std::string op = parser.get_op();
        
        Task task(op, column);

        Dataset dataset(file_name,
                        partition_rows,
                        start_range,
                        end_range,
                        columns,
                        column);
        
        std::deque<PartitionThread> thread_queue;
        while (!dataset.eof()) {
            Partition *partition = dataset.read_partition();
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
