#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "task.h"

// void print_partition(unsigned short int *partition, 
//                         int partition_rows, 
//                         int columns) {
//     std::cout << "--------\n";
//     for (int i = 0; i < partition_rows; i++) {
//         for (int j = 0; j < columns; j++)
//             std::cout << partition[i * columns + j] << " ";
//         std::cout << "\n";
//     }
//     std::cout << "--------\n";
//     // for (int i = 0; i < columns; i++)
//     //     std::cout << row[i] << " ";
//     // std::cout << "\n";
// }

void swap_endianness(unsigned short int *array, int size) {
    for (int i = 0; i < size; i++)
        array[i] = array[i] >> 8 | array[i] << 8;
}

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
    int start_range, end_range, partition_rows, column;
    std::string op;
    
    if (argc != 4) {
        printf("Error en la cantidad de argumentos\n");
        printf("Para ejecutar:\n");
        printf("./tp <dataset> <columns> <workers>\n");
        return -1;
    }

    columns = atoi(argv[2]);
    // workers = atoi(argv[3]);    
    
    while (std::getline(std::cin, task_str)) {
        std::ifstream dataset(argv[1], std::ios::in | std::ios::binary);
        if (!dataset.is_open()) {
            std::cout << "Error al abrir el archivo dataset\n";
            return 1;
        }
        parse_task(task_str, start_range, end_range, 
                   partition_rows, column, op);

        Task task(op);
        
        dataset.seekg(start_range * columns * sizeof(unsigned short int));

        unsigned int partition_size = columns * partition_rows;
        unsigned short int *partition = new unsigned short int [partition_size];
        int current_row = start_range;
        int bytes_to_read = std::min(end_range - current_row, partition_rows) 
                            * columns * sizeof(unsigned short int);

        dataset.read((char *) partition, bytes_to_read);
        int elements_read = dataset.gcount() / sizeof(unsigned short int);
        
        while (elements_read > 0 && current_row < end_range) {
            swap_endianness(partition, elements_read);
            
            task.apply(partition, columns, elements_read / columns, column);
            current_row += partition_rows;
            bytes_to_read = std::min(end_range - current_row, partition_rows) 
                            * columns * sizeof(unsigned short int);
            dataset.read((char *) partition, bytes_to_read);
            elements_read = dataset.gcount() / sizeof(unsigned short int);
        }
        task.print_result();
        delete partition;
        dataset.close();
    }
    
    return 0;
}
