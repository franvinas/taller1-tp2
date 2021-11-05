#ifndef PARTITION_METADATA_H
#define PARTITION_METADATA_H

class PartitionMetadata {
private:
    int from_row;
    int to_row;
    int column;
    bool empty;

public:
    /*
     *  Constructor
     */
    PartitionMetadata();
    /*
     *  Constructor
     */
    PartitionMetadata(const int from_row, 
                      const int to_row, 
                      const int column);
    /*
     *  Constructor por copia
     */
    PartitionMetadata(const PartitionMetadata&) = delete;
    /*
     *  Asignacion por copia
     */
    PartitionMetadata& operator=(const PartitionMetadata&) = delete;
    /*
     *  Constructor por movimiento
     */
    PartitionMetadata(PartitionMetadata&& other);
    /*
     *  Devuelve numero de la fila inicial de la particion
     */
    int get_from_row() const;
    /*
     *  Devuelve numero de la fila final de la particion
     */
    int get_to_row() const;
    /*
     *  Devuelve numero de la columna donde se aplican las operaciones
     */
    int get_column() const;
    /*
     *  Devuelve true si es una particion vacia, false si no
     */
    bool is_empty() const;
};

#endif
