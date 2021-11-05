#include "PartitionMetadata.h"
#include <utility>

/***********************
    Metodos publicos
************************/

PartitionMetadata::PartitionMetadata(const int from_row, 
                                     const int to_row, 
                                     const int column) 
                                    : from_row(from_row),
                                      to_row(to_row),
                                      column(column),
                                      empty(false) {}

PartitionMetadata::PartitionMetadata() : from_row(0),
                                         to_row(0),
                                         column(0),
                                         empty(true) {}

PartitionMetadata::PartitionMetadata(PartitionMetadata&& other) 
                                    : from_row(std::move(other.from_row)),
                                      to_row(std::move(other.to_row)),
                                      column(std::move(other.column)),
                                      empty(std::move(other.empty)) {}

int PartitionMetadata::get_from_row() const {
    return this->from_row;
}

int PartitionMetadata::get_to_row() const {
    return this->to_row;
}

int PartitionMetadata::get_column() const {
    return this->column;
}

bool PartitionMetadata::is_empty() const {
    return this->empty;
}
