#include "PartitionMetadata.h"

PartitionMetadata::PartitionMetadata(const int &from_row, 
                                     const int &to_row, 
                                     const int &column) 
                                    : from_row(from_row),
                                      to_row(to_row),
                                      column(column) {}

int PartitionMetadata::get_from_row() const {
    return this->from_row;
}

int PartitionMetadata::get_to_row() const {
    return this->to_row;
}

int PartitionMetadata::get_column() const {
    return this->column;
}
