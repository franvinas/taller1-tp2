#include "task.h"
#include "operation.h"
#include <string>
#include <iostream>


Task::Task(const std::string &op_str, const int column): op_str(op_str), column(column) {
    this->op = create_operation();
}

Operation * Task::create_operation() const {
    if (op_str == "sum")
        return new Sum();

    if (op_str == "mean")
        return new Mean();

    if (op_str == "min")
        return new Min();
    
    return new Max();
}

void Task::apply(Partition &partition) {
    
    while (!partition.end()) {
        this->op->apply(partition.next());
    }
    
    // for (int i = 0; i < partition_rows; i++) {
    //     int idx = i * columns + this->column;
    //     this->op->apply(partition[idx]);
    // }
}

void Task::print_result() {
    this->op->print_result();
}

Task::~Task() {
    delete this->op;
}
