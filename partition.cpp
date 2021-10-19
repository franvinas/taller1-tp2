#include "partition.h"
#include <fstream>
#include <cstring>
#include <iostream>

Partition::Partition(const unsigned short int *data, 
                     int rows, int columns, int column)
                    : rows(rows), 
                      columns(columns), 
                      current_row(0), 
                      column(column) {
    int partition_size = rows * columns;
    this->data = new unsigned short int [partition_size];
    if (this->data == NULL) {
        std::cout << "Error al alocar memoria en el heap\n";
        return;
    }
    
    std::memcpy(this->data, data, partition_size * sizeof(unsigned short int));
}

Partition::Partition(Partition&& other) 
                    : data(other.data),
                    rows(other.rows), 
                    columns(other.columns),
                    current_row(other.current_row),
                    column(other.column) {
    other.data = nullptr;
}

Partition& Partition::operator=(Partition&& other) {
    if (this == &other)
        return *this;

    if (this->data)
        delete [] this->data;

    this->data = other.data;
    this->rows = other.rows;
    this->columns = other.columns;
    this->current_row = other.current_row;
    this->column = other.column;

    return *this;
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
