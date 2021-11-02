#ifndef DATASET_H
#define DATASET_H

#include "PartitionMetadata.h"
#include "Partition.h"
#include <string>
#include <fstream>
#include <mutex>

class Dataset {
private:
    std::ifstream dataset;
    const int columns;
    std::mutex mutex;

public:
    /*
     *  Constructor
     */
    Dataset(const std::string &dataset_name, const int columns);
    /*
     *  Devuelve una instancia de tipo Partition segun 
     *  lo que indica partitionMetadata
     */
    Partition read_partition(const PartitionMetadata &partitionMetadata);
    /*
     *  Destructor
     */
    ~Dataset();
};

#endif
