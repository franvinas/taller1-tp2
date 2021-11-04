#include "Partition.h"
#include <utility>
#include <vector>

/***********************
    Metodos publicos
************************/

Partition::Partition(std::vector<unsigned short int> &data, 
                     const int rows, const int columns, const int column)
                    : data(std::move(data)),
                      rows(rows), 
                      columns(columns), 
                      current_row(0), 
                      column(column) {
}

Partition::Partition(Partition&& other) {
    this->data = std::move(other.data);
    this->rows = other.rows;
    this->columns = other.columns;
    this->current_row = other.current_row;
    this->column = other.column;
}

Partition& Partition::operator=(Partition&& other) {
    if (this == &other)
        return *this;

    this->data = std::move(other.data);
    this->rows = other.rows;
    this->columns = other.columns;
    this->current_row = other.current_row;
    this->column = other.column;

    return *this;
}

bool Partition::end() const {
    return current_row >= rows;
}

unsigned short int Partition::next() {
    int idx = current_row * columns + column;
    current_row++;
    return data.at(idx);
}
