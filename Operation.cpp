#include "Operation.h"
#include <iostream>

void Operation::print_result() {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::cout << this->a << "\n";
}

Operation::~Operation() {}

Sum::Sum() {
    this->a = 0;
}

void Sum::apply(const unsigned short int &b) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->a += b;
}

Mean::Mean(): sum(0), n(0) {
    this->a = 0;
}

void Mean::apply(const unsigned short int &b) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->sum += b;
    this->n += 1;
}

void Mean::print_result() {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::cout << this->sum << "/" << this->n << "\n";
}

Min::Min() {
    this->a = -1;
}

void Min::apply(const unsigned short int &b) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->a = this->a < b ? this->a : b;
}

Max::Max() {
    this->a = 0;
}

void Max::apply(const unsigned short int &b) {
    std::lock_guard<std::mutex> lock(mutex);
    this->a = this->a > b ? this->a : b;
}
