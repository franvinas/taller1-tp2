#include "Operation.h"
#include <string>
#include <algorithm>

Operation::Operation(unsigned short int partial_result) 
                    : partial_result(partial_result),
                      result_returned(false) {}

std::string Operation::get_result() {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::string result;
    result.clear();
    if (this->result_returned) return result;
    this->result_returned = true;
    result = std::to_string(this->partial_result);
    return result;
}

Operation::~Operation() {}
