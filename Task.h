#ifndef TASK_H
#define TASK_H

#include <string>
#include "Operation.h"
#include "Partition.h"
#include "TaskAttributes.h"
#include "PartitionMetadata.h"

class Task {
private:
    TaskAttributes attributes;
    Operation *op;
    Operation *create_operation(const std::string &op_str) const;

public:
    explicit Task(const std::string &task_str);
    Task(Task&& other);
    Task& operator=(Task&& other);
    void apply(Partition &partition);
    void print_result();
    bool done();
    PartitionMetadata new_partition_metadata();
    ~Task();
};

#endif
