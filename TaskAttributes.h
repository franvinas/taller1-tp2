#ifndef TASK_ATTRIBUTES_H
#define TASK_ATTRIBUTES_H

#include <string>
#include <sstream>
#include "partitionmetadata.h"

class TaskAttributes {
private:
    int start_range;
    int end_range;
    int partition_rows;
    int column;
    int current_row;
    std::string op;

public:
    explicit TaskAttributes(const std::string &task_str);
    TaskAttributes(const TaskAttributes &other);
    std::string get_op() const;
    bool done();
    PartitionMetadata new_partition_metadata();
};

#endif
