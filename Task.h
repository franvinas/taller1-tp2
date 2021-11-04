#ifndef TASK_H
#define TASK_H

#include "Operation.h"
#include "TaskAttributes.h"
#include "Dataset.h"
#include <string>

class Task {
private:
    TaskAttributes attributes;
    Operation *op;
    Operation *create_operation(const std::string &op_str) const;

public:
    /*
     *  Constructor
     */
    explicit Task(const std::string &task_str);
    /*
     *  Constructor por copia
     */
    Task(const Task&) = delete;
    /*
     *  Asignacion por copia
     */
    Task& operator=(const Task&) = delete;
    /*
     *  Constructor por movimiento
     */
    Task(Task&& other);
    /*
     *  Asignacion por movimiento
     */
    Task& operator=(Task&& other);
    /*
     *  Aplica la operacion que corresponde sobre la siguiente particion
     */
    bool apply(Dataset &dataset);
    /*
     *  Imprime el resultado de la operacion
     */
    std::string get_result();
    /*
     *  Devuelve true si ya se 'pidieron' todas las particiones
     *  sino devuelve false
     */
    bool done();
    /*
     *  Destructor
     */
    ~Task();
};

#endif
