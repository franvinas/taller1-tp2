#ifndef TASK_H
#define TASK_H

#include <string>
#include "operation.h"

class Task {
private:
    std::string op_str;
    Operation *op;
    Operation *create_operation() const;

public:
    explicit Task(std::string &op_str);
    void apply(unsigned short int *partition, 
               int columns, 
               int partition_rows, 
               int column);
    void print_result();
    ~Task();
};

#endif
