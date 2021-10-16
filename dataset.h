#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <fstream>
#include "partition.h"

class Dataset {
private:
    std::ifstream dataset;
    int partition_rows;
    int current_row;
    int start_range;
    int end_range;
    int columns;
    int column;
    void swap_endianness(unsigned short int *array, int size);

public:
    Dataset(const std::string &dataset_name,
            const int partition_rows,
            const int start_range,
            const int end_range,
            const int columns,
            const int column);
    Partition read_partition();
    bool eof();
    
    ~Dataset();
};

#endif
