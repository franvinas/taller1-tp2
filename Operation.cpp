#include "Operation.h"
#include <string>
#include <algorithm>

Operation::Operation() : partial_result(0), result_returned(false) {}

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
