#include "dataset.h"
#include <fstream>
#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include "taskattributes.h"

Dataset::Dataset(const std::string &dataset_name, 
                 const int &columns,
                 const TaskAttributes &attributes) 
                 : partition_rows(attributes.get_partition_rows()), 
                   current_row(attributes.get_start_range()),
                   start_range(attributes.get_start_range()),
                   end_range(attributes.get_end_range()),
                   columns(columns),
                   column(attributes.get_column()) {
    this->dataset = std::ifstream(dataset_name, 
                                 std::ios::in | std::ios::binary);
    if (!this->dataset.is_open()) {
        std::cout << "Error al abrir el archivo dataset\n";
    }

    dataset.seekg(start_range * columns * sizeof(unsigned short int));
}

Partition Dataset::read_partition() {
    std::lock_guard<std::mutex> lock(this->mutex);
    int bytes_to_read = std::min(end_range - current_row, partition_rows) 
                            * columns * sizeof(unsigned short int);
    int partition_size = columns * partition_rows;
    unsigned short int *partition_data = new unsigned short int[partition_size];
    if (partition_data == NULL) {
        std::cout << "Error al alocar memoria\n";
    }
    this->dataset.read((char *) partition_data, bytes_to_read);
    int elements_read = this->dataset.gcount() / sizeof(unsigned short int);
    swap_endianness(partition_data, elements_read);
    int partition_real_rows = elements_read / columns;
    current_row += partition_real_rows;
    Partition partition(partition_data, 
                        partition_real_rows,
                        columns, 
                        column);
    delete [] partition_data;

    return partition;
}

void Dataset::swap_endianness(unsigned short int *array, int size) {
    for (int i = 0; i < size; i++)
        array[i] = array[i] >> 8 | array[i] << 8;
}

bool Dataset::eof() {
    return current_row >= end_range;
}

Dataset::~Dataset() {
    this->dataset.close();
}
