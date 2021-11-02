#include "Operation.h"
#include <iostream>
#include <algorithm>

Operation::Operation() : partial_result(0), result_printed(false) {}

void Operation::print_result() {
    std::lock_guard<std::mutex> lock(this->mutex);
    if (!this->result_printed) {
        std::cout << this->partial_result << "\n";
        this->result_printed = true;
    }
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

void Mean::print_result() {
    std::lock_guard<std::mutex> lock(this->mutex);
    if (!this->result_printed) {
        std::cout << this->sum << "/" << this->n << "\n";
        this->result_printed = true;
    }
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
