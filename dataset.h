#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <fstream>
#include <mutex>
#include "partition.h"
#include "taskattributes.h"

class Dataset {
private:
    std::ifstream dataset;
    int partition_rows;
    int current_row;
    int start_range;
    int end_range;
    int columns;
    int column;
    std::mutex mutex;
    void swap_endianness(unsigned short int *array, int size);

public:
    Dataset(const std::string &dataset_name,
            const int &columns,
            const TaskAttributes &attributes);
    Partition read_partition();
    bool eof();
    
    ~Dataset();
};

#endif
