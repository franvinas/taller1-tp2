#include "Task.h"
#include "Partition.h"
#include "OpSum.h"
#include "OpMean.h"
#include "OpMin.h"
#include "OpMax.h"
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

    throw std::runtime_error("Comando desconocido");
}

bool Task::apply(Dataset &dataset) {
    PartitionMetadata pMetadata = this->attributes.new_partition_metadata();
    if (pMetadata.is_empty()) return true;
    Partition partition(dataset.read_partition(pMetadata));
    while (!partition.end()) {
        unsigned short int n = partition.next();
        this->op->apply(n);
    }
    this->attributes.partition_done();
    return this->done();
}

std::string Task::get_result() {
    return this->op->get_result();
}

bool Task::done() const {
    return this->attributes.done();
}

Task::~Task() {
    delete this->op;
}
