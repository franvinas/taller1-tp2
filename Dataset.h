#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <fstream>
#include <mutex>
#include "Partition.h"
#include "PartitionMetadata.h"

class Dataset {
private:
    std::ifstream dataset;
    int columns;
    std::mutex mutex;
    void swap_endianness(unsigned short int *array, int size);

public:
    Dataset(const std::string &dataset_name,
            const int &columns);
    Partition read_partition(PartitionMetadata partitionMetadata);
    
    ~Dataset();
};

#endif
