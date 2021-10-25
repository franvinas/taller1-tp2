#include "Task.h"
#include "Partition.h"
#include <string>
#include <iostream>
#include <utility>

Task::Task(const std::string &task_str)
            : attributes(task_str) {
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

bool Task::apply(Dataset &dataset) {
    this->mutex.lock();
    if (this->done()) return true;
    PartitionMetadata pMetadata = this->new_partition_metadata();
    Partition partition(dataset.read_partition(pMetadata));
    this->mutex.unlock();
    while (!partition.end()) {
        unsigned short int n = partition.next();
        this->op->apply(n);
    }
    this->attributes.partition_done();
    return this->done();
}

void Task::print_result() {
    if (this->done())
        this->op->print_result();
}

bool Task::done() const {
    return this->attributes.done();
}

PartitionMetadata Task::new_partition_metadata() {
    return this->attributes.new_partition_metadata();
}

Task::~Task() {
    delete this->op;
}
