#include <string>
#include <sstream>
#include "taskattributes.h"

TaskAttributes::TaskAttributes(const std::string &task_str) 
                               : start_range(0),
                                 end_range(0),
                                 partition_rows(0),
                                 column(0) {
    std::stringstream task_stream(task_str);
    task_stream >> this->start_range;
    task_stream >> this->end_range;
    task_stream >> this->partition_rows;
    task_stream >> this->column;
    task_stream >> this->op;
}

TaskAttributes::TaskAttributes(const TaskAttributes &other) {
    this->start_range = std::move(other.start_range);
    this->end_range = std::move(other.end_range);
    this->partition_rows = std::move(other.partition_rows);
    this->column = std::move(other.column);
    this->op = std::move(other.op);
}

int TaskAttributes::get_start_range() const {
    return this->start_range;
}

int TaskAttributes::get_end_range() const {
    return this->end_range;
}

int TaskAttributes::get_partition_rows() const{
    return this->partition_rows;
}

int TaskAttributes::get_column() const {
    return this->column;
}

std::string TaskAttributes::get_op() const {
    return this->op;
}
