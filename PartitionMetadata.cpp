#include "PartitionMetadata.h"

PartitionMetadata::PartitionMetadata(int from_row, int to_row, int column) 
                                    : from_row(from_row),
                                    to_row(to_row),
                                    column(column) {}

int PartitionMetadata::get_from_row() {
    return this->from_row;
}

int PartitionMetadata::get_to_row() {
    return this->to_row;
}

int PartitionMetadata::get_column() {
    return this->column;
}
