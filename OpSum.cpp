#include "OpSum.h"

Sum::Sum() {
    this->partial_result = 0;
}

void Sum::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->partial_result += val;
}
