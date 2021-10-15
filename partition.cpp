#include "partition.h"
#include <fstream>
#include <cstring>
#include <iostream>

Partition::Partition(const unsigned short int *data, int rows, int columns, int column)
                    : rows(rows), columns(columns), current_row(0), column(column) {
    int partition_size = rows * columns;
    this->data = new unsigned short int [partition_size];
    if (this->data == NULL) {
        std::cout << "Error al alocar memoria en el heap\n";
        return;
    }
    
    std::memcpy(this->data, data, partition_size * sizeof(unsigned short int));
}

bool Partition::end() {
        return current_row >= rows;
}

unsigned short int Partition::next() {
    int idx = current_row * columns + column;
    current_row++;
    return data[idx];
}

Partition::~Partition() {
    delete [] this->data;
}
