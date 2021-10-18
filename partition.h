#ifndef PARTITION_h
#define PARTITION_h

#include <string>

class Partition {
private:
    unsigned short int * data;
    int rows;
    int columns;
    int current_row;
    int column;

public:
    Partition(const unsigned short int *data,
              int rows,    
              int columns,
              int column);
    Partition(const Partition &other);
    
    Partition(Partition&& other);

    Partition& operator=(Partition&& other);
    
    bool end();
    unsigned short int next();
    ~Partition();
};

#endif
