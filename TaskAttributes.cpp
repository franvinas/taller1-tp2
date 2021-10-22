#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include "TaskAttributes.h"

TaskAttributes::TaskAttributes(const std::string &task_str) 
                               : start_range(0),
                                 end_range(0),
                                 partition_rows(0),
                                 column(0),
                                 current_row(0) {
    std::stringstream task_stream(task_str);
    task_stream >> this->start_range;
    task_stream >> this->end_range;
    task_stream >> this->partition_rows;
    task_stream >> this->column;
    task_stream >> this->op;
    this->current_row = this->start_range;
}

TaskAttributes::TaskAttributes(const TaskAttributes &other) {
    this->start_range = std::move(other.start_range);
    this->end_range = std::move(other.end_range);
    this->partition_rows = std::move(other.partition_rows);
    this->column = std::move(other.column);
    this->current_row = std::move(other.current_row);
    this->op = std::move(other.op);
}

std::string TaskAttributes::get_op() const {
    return this->op;
}

bool TaskAttributes::done() {
    return current_row >= end_range;
}

PartitionMetadata TaskAttributes::new_partition_metadata() {
    if (current_row >= end_range) throw -1;
    
    int to_row = std::min(current_row + partition_rows, end_range);
    int from_row = this->current_row;
    this->current_row += partition_rows;
    
    return PartitionMetadata(from_row, to_row, this->column);
}
