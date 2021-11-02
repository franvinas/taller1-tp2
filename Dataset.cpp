#include "Dataset.h"
#include <iostream>
#include <string>
#include <vector>
#include <arpa/inet.h>

Dataset::Dataset(const std::string &dataset_name, 
                 const int columns) 
                 : dataset(dataset_name, std::ios::in | std::ios::binary),
                 columns(columns) {
    if (!this->dataset.is_open()) {
        std::cerr << "Error al abrir el archivo dataset\n";
        throw -1;
    }
}

Partition Dataset::read_partition(const PartitionMetadata &partitionMetadata) {
    std::lock_guard<std::mutex> lock(this->mutex);
    int from_row = partitionMetadata.get_from_row();
    int to_row = partitionMetadata.get_to_row();
    int column = partitionMetadata.get_column();
    dataset.seekg(from_row * columns * sizeof(unsigned short int));
    int partition_size = columns * (to_row - from_row);
 
    std::vector<unsigned short int> partition_data;
    unsigned short int val;
    int elements_read = 0;

    while (this->dataset.read((char *) &val, sizeof(unsigned short int))) {
        elements_read++;
        partition_data.push_back(ntohs(val));
        if (elements_read >= partition_size) break;
    }
   
    int partition_real_rows = elements_read / columns;
    Partition partition(partition_data,
                        partition_real_rows,
                        columns,
                        column);

    return partition;
}

Dataset::~Dataset() {
    this->dataset.close();
}
