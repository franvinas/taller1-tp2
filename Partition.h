#ifndef PARTITION_H
#define PARTITION_H

#include <vector>

class Partition {
private:
    std::vector<unsigned short int> data;
    int rows;
    int columns;
    int current_row;
    int column;

public:
    /*
     *  Constructor
     */
    Partition(const unsigned short int *data,
              const int &rows,    
              const int &columns,
              const int &column);
    /*
     *  Constructor por movimiento
     */
    Partition(Partition&& other);
    /*
     *  Asignacion por movimiento
     */
    Partition& operator=(Partition&& other);
    /*
     *  Devuelve true si ya se iteró por todas las filas de la particion
     */
    bool end() const;
    /*
     *  Devuelve el proximo valor en la columna que corresponde
     */
    unsigned short int next();
};

#endif
