#include <string>
#include <sstream>
#include "taskparser.h"

TaskParser::TaskParser(const std::string &task_str) 
                    : task_stream(task_str),
                      start_range(0),
                      end_range(0),
                      partition_rows(0),
                      column(0) {
    task_stream >> this->start_range;
    task_stream >> this->end_range;
    task_stream >> this->partition_rows;
    task_stream >> this->column;
    task_stream >> this->op;
}

int TaskParser::get_start_range() {
    return this->start_range;
}

int TaskParser::get_end_range() {
    return this->end_range;
}

int TaskParser::get_partition_rows() {
    return this->partition_rows;
}

int TaskParser::get_column() {
    return this->column;
}

std::string TaskParser::get_op() {
    return this->op;
}
