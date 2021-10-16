#include <iostream>
#include <string>
#include "task.h"
#include "dataset.h"

void parse_task(const std::string &task, 
                int &start_range,
                int &end_range,
                int &partition_rows,
                int &column,
                std::string &op) {
    int i = 0, j = 0;
    j = task.find(" ", i);
    std::string aux_str = task.substr(i, j - i);
    start_range = stoi(aux_str);
    i = j + 1;
    j = task.find(" ", i);
    aux_str = task.substr(i, j - i);
    end_range = stoi(aux_str);
    i = j + 1;
    j = task.find(" ", i);
    aux_str = task.substr(i, j - i);
    partition_rows = stoi(aux_str);
    i = j + 1;
    j = task.find(" ", i);
    aux_str = task.substr(i, j - i);
    column = stoi(aux_str);
    i = j + 1;
    op = task.substr(i, -1);
}

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
        int start_range, end_range, partition_rows, column;
        std::string op;
        parse_task(task_str, start_range, end_range, 
                   partition_rows, column, op);
        
        Task task(op, column);

        Dataset dataset(file_name,
                        partition_rows,
                        start_range,
                        end_range,
                        columns,
                        column);
        
        while (!dataset.eof()) {
            Partition partition = dataset.read_partition();
            task.apply(partition);
        }

        task.print_result();
    }
    
    return 0;
}
