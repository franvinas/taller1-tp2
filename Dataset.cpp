#include "Dataset.h"
#include <iostream>
#include <string>

Dataset::Dataset(const std::string &dataset_name, 
                 const int &columns) 
                 : dataset(std::ifstream(dataset_name, 
                           std::ios::in | std::ios::binary)),
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
    unsigned short int *partition_data = new unsigned short int[partition_size];
    if (partition_data == NULL) {
        std::cerr << "Error al alocar memoria\n";
        throw -1;
    }
    this->dataset.read((char *) partition_data, 
                        partition_size * sizeof(unsigned short int));
    int elements_read = this->dataset.gcount() / sizeof(unsigned short int);
    swap_endianness(partition_data, elements_read);
    int partition_real_rows = elements_read / columns;
    Partition partition(partition_data,
                        partition_real_rows,
                        columns,
                        column);
    delete [] partition_data;

    return partition;
}

void Dataset::swap_endianness(unsigned short int *array, const int &n) const {
    for (int i = 0; i < n; i++)
        array[i] = array[i] >> 8 | array[i] << 8;
}

Dataset::~Dataset() {
    this->dataset.close();
}
