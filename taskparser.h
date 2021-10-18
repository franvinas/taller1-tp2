#ifndef TASK_PARSER_H
#define TASK_PARSER_H

#include <string>
#include <sstream>

class TaskParser {
private:
    std::stringstream task_stream;
    int start_range;
    int end_range;
    int partition_rows;
    int column;
    std::string op;

public:
    explicit TaskParser(const std::string &task_str);
    int get_start_range();
    int get_end_range();
    int get_partition_rows();
    int get_column();
    std::string get_op();
};

#endif
