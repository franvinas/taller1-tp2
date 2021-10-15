#ifndef TASK_H
#define TASK_H

#include <string>
#include "operation.h"
#include "partition.h"

class Task {
private:
    std::string op_str;
    int column;
    Operation *op;
    Operation *create_operation() const;

public:
    explicit Task(const std::string &op_str, const int column);
    void apply(Partition &partition);
    void print_result();
    ~Task();
};

#endif
