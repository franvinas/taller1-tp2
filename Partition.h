#ifndef PARTITION_H
#define PARTITION_H

#include <string>
#include <vector>

class Partition {
private:
    // unsigned short int * data;
    std::vector<unsigned short int> data;
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
};

#endif
