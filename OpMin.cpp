#include "OpMin.h"
#include <algorithm>

Min::Min() {
    this->partial_result = -1;
}

void Min::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->partial_result = std::min(this->partial_result, val);
}

