#include "task.h"
#include "operation.h"
#include <string>
#include <iostream>


Task::Task(const TaskAttributes &attributes)
            : attributes(std::move(attributes)) {
    try {
        this->op = create_operation(this->attributes.get_op());
    } catch(...) {
        std::cerr << "Excepcion: operacion no valida" << std::endl;
    }
}

Task::Task(Task&& other) 
            : attributes(std::move(other.attributes)),
              op(other.op) {
    other.op = nullptr;
}

Task& Task::operator=(Task&& other) {
    if (this == &other)
        return *this;

    this->attributes = std::move(other.attributes);
    this->op = other.op;
    other.op = nullptr;

    return *this;
}


Operation * Task::create_operation(const std::string &op_str) const {
    if (op_str == "sum")
        return new Sum();

    if (op_str == "mean")
        return new Mean();

    if (op_str == "min")
        return new Min();
    if (op_str == "max")
        return new Max();

    throw -1;
}

void Task::apply(Partition &partition) {
    while (!partition.end()) {
        unsigned short int n = partition.next();
        this->op->apply(n);
    }
}

void Task::print_result() {
    this->op->print_result();
}

const TaskAttributes &Task::get_attributes() const {
    return this->attributes;
}

Task::~Task() {
    delete this->op;
}
