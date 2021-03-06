#include "TaskAttributes.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <math.h>
#include <string>
#include <algorithm>

/***********************
    Metodos publicos
************************/

TaskAttributes::TaskAttributes(const std::string &task_str) 
                               : start_range(0),
                                 end_range(0),
                                 partition_rows(0),
                                 column(0),
                                 current_row(0),
                                 total_partitions(0),
                                 partitions_done(0) {
    std::stringstream task_stream(task_str);
    task_stream >> this->start_range;
    task_stream >> this->end_range;
    task_stream >> this->partition_rows;
    task_stream >> this->column;
    task_stream >> this->op;
    this->current_row = this->start_range;
    this->total_partitions = ceil((end_range - start_range) / partition_rows);
}

TaskAttributes::TaskAttributes(TaskAttributes &&other) 
                    : start_range(std::move(other.start_range)),
                        end_range(std::move(other.end_range)),
                        partition_rows(std::move(other.partition_rows)),
                        column(std::move(other.column)),
                        current_row(std::move(other.current_row)),
                        op(std::move(other.op)),
                        total_partitions(std::move(other.total_partitions)),
                        partitions_done(std::move(other.partitions_done)) {}

TaskAttributes& TaskAttributes::operator=(TaskAttributes&& other) {
    if (this == &other)
        return *this;
    this->start_range = std::move(other.start_range);
    this->end_range = std::move(other.end_range);
    this->partition_rows = std::move(other.partition_rows);
    this->column = std::move(other.column);
    this->current_row = std::move(other.current_row);
    this->op = std::move(other.op);
    this->total_partitions = std::move(other.total_partitions);
    this->partitions_done = std::move(other.partitions_done);

    return *this;
}

std::string TaskAttributes::get_op() const {
    return this->op;
}

bool TaskAttributes::done() {
    std::lock_guard<std::mutex> lock(this->mutex);
    return current_row >= end_range;
}

PartitionMetadata TaskAttributes::new_partition_metadata() {
    std::lock_guard<std::mutex> lock(this->mutex);
    if (current_row >= end_range) {
        std::cerr << "No hay mas particiones\n";
        throw std::runtime_error("No hay mas particiones");
    }
    
    int to_row = std::min(current_row + partition_rows, end_range);
    int from_row = this->current_row;
    this->current_row += partition_rows;
    
    return PartitionMetadata(from_row, to_row, this->column);
}

void TaskAttributes::partition_done() {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->partitions_done++;
}
