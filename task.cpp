#include "task.h"
#include "operation.h"
#include <string>
#include <iostream>


Task::Task(const std::string &op_str, const int column)
            : op_str(op_str), column(column) {
    this->op = create_operation();
}

Operation * Task::create_operation() const {
    // Este es el único lugar de este tp donde tiene sentido retornar puntero, ya que estás usando un polimorfismo.
    // En el resto del TP repasá que no lo estés haciendo porque no tiene sentido.
    if (op_str == "sum")
        return new Sum();

    if (op_str == "mean")
        return new Mean();

    if (op_str == "min")
        return new Min();
    
    return new Max();

    // Acá te conviene agregar el if del "max" y tirar alguna exception si viene otra cosa
}

void Task::apply(Partition &partition) {
    while (!partition.end()) {
        this->op->apply(partition.next());
    }
}

void Task::print_result() {
    this->op->print_result();
}

Task::~Task() {
    delete this->op;
}
