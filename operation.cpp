#include "operation.h"
#include <iostream>


void Operation::print_result() {
    std::cout << this->a << "\n";
}

Operation::~Operation() {}

Sum::Sum() {
    this->a = 0;
}

void Sum::apply(unsigned short int b) {
    this->a += b;
}

Mean::Mean(): sum(0), n(0) {
    this->a = 0;
}

void Mean::apply(unsigned short int b) {
    this->sum += b;
    this->n += 1;
}

void Mean::print_result() {
    std::cout << this->sum << "/" << this->n << "\n";
}

Min::Min() {
    this->a = -1;
}

void Min::apply(unsigned short int b) {
    this->a = this->a < b ? this->a : b;
}

Max::Max() {
    this->a = 0;
}

void Max::apply(unsigned short int b) {
    this->a = this->a > b ? this->a : b;
}
