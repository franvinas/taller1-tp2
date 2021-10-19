#ifndef TASK_ATTRIBUTES_H
#define TASK_ATTRIBUTES_H

#include <string>
#include <sstream>

class TaskAttributes {
private:
    int start_range;
    int end_range;
    int partition_rows;
    int column;
    std::string op;

public:
    explicit TaskAttributes(const std::string &task_str);
    TaskAttributes(const TaskAttributes &other);
    int get_start_range() const;
    int get_end_range() const;
    int get_partition_rows() const;
    int get_column() const;
    std::string get_op() const;
};

#endif
