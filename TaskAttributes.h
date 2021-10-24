#ifndef TASK_ATTRIBUTES_H
#define TASK_ATTRIBUTES_H

#include <string>
#include <sstream>
#include <mutex>
#include "PartitionMetadata.h"

class TaskAttributes {
private:
    int start_range;
    int end_range;
    int partition_rows;
    int column;
    int current_row;
    std::string op;
    int total_partitions;
    int partitions_done;

public:
    explicit TaskAttributes(const std::string &task_str);
    TaskAttributes(const TaskAttributes &other);
    std::string get_op() const;
    bool done();
    void partition_done();
    PartitionMetadata new_partition_metadata();
};

#endif
