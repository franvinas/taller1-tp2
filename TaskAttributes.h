#ifndef TASK_ATTRIBUTES_H
#define TASK_ATTRIBUTES_H

#include "PartitionMetadata.h"
#include <string>

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
    /*
     *  Constructor
     */
    explicit TaskAttributes(const std::string &task_str);
    /*
     *  Constructor por copia
     */
    TaskAttributes(const TaskAttributes &other);
    /*
     *  Devuelve un string con el nombre de la operacion
     */
    std::string get_op() const;
    /*
     *  Devuelve true si ya se 'pidieron' todas las particiones
     *  sino devuelve false
     */
    bool done() const;
    /*
     *  Aumenta en 1 el contador de particiones procesadas
     */
    void partition_done();
    /*
     *  Devuelve la metadata de la proxima particion a procesar
     */
    PartitionMetadata new_partition_metadata();
};

#endif
