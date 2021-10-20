#ifndef PARTITION_METADATA_H
#define PARTITION_METADATA_H

class PartitionMetadata {
private:
    int from_row;
    int to_row;
    int column;

public:
    PartitionMetadata(int from_row, int to_row, int column);
    int get_from_row();
    int get_to_row();
    int get_column();
};

#endif
