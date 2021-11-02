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

Sum::Sum() {
    this->partial_result = 0;
}

void Sum::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->partial_result += val;
}

Mean::Mean(): sum(0), n(0) {
    this->partial_result = 0;
}

void Mean::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->sum += val;
    this->n += 1;
}

std::string Mean::get_result() {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::string result;
    result.clear();
    if (this->result_returned) return result;

    this->result_returned = true;
    result = std::to_string(this->sum) + "/" + std::to_string(this->n);
    return result;
}

Min::Min() {
    this->partial_result = -1;
}

void Min::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->partial_result = std::min(this->partial_result, val);
}

Max::Max() {
    this->partial_result = 0;
}

void Max::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(mutex);
    this->partial_result = std::max(this->partial_result, val);
}
