#ifndef PARTITION_METADATA_H
#define PARTITION_METADATA_H

class PartitionMetadata {
private:
    int from_row;
    int to_row;
    int column;

public:
    /*
     *  Constructor
     */
    PartitionMetadata(const int from_row, 
                      const int to_row, 
                      const int column);
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
};

#endif
