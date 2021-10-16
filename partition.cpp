#include "partition.h"
#include <fstream>
#include <cstring>
#include <iostream>

Partition::Partition(const unsigned short int *data, 
                     int rows, int columns, int column)
                    : rows(rows), columns(columns), 
                      current_row(0), column(column) {
    int partition_size = rows * columns;
    this->data = new unsigned short int [partition_size];
    if (this->data == NULL) {
        std::cout << "Error al alocar memoria en el heap\n";
        return;
    }
    
    std::memcpy(this->data, data, partition_size * sizeof(unsigned short int));
}

Partition Partition::operator=(const Partition &other) {
    if (this == &other)
        return *this;

    if (this->data)
        delete [] this->data;

    this->rows = other.rows;
    this->columns = other.columns;
    this->current_row = other.current_row;
    this->column = other.column;
    this->data = new unsigned short int [rows * columns];
    int bytes_to_copy = rows * columns * sizeof(unsigned short int);
    std::memcpy(this->data, other.data, bytes_to_copy);

    return *this;
}

Partition::Partition(const Partition &other) {
    this->rows = other.rows;
    this->columns = other.columns;
    this->current_row = other.current_row;
    this->column = other.column;
    this->data = new unsigned short int [rows * columns];
    int bytes_to_copy = rows * columns * sizeof(unsigned short int);
    std::memcpy(this->data, other.data, bytes_to_copy);
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
