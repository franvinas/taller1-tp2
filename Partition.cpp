#include "Partition.h"
#include <utility>

Partition::Partition(const unsigned short int *data, 
                     const int &rows, const int &columns, const int &column)
                    : rows(rows), 
                      columns(columns), 
                      current_row(0), 
                      column(column) {
    for (int i = 0; i < rows * columns; i++)
        this->data.push_back(data[i]);
}

Partition::Partition(Partition&& other) 
                    : data(std::move(other.data)),
                    rows(other.rows), 
                    columns(other.columns),
                    current_row(other.current_row),
                    column(other.column) {}

Partition& Partition::operator=(Partition&& other) {
    if (this == &other)
        return *this;

    this->data = std::move(other.data);
    this->data = other.data;
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
