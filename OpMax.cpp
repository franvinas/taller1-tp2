#include "OpMax.h"
#include <algorithm>

Max::Max() {
    this->partial_result = 0;
}

void Max::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(mutex);
    this->partial_result = std::max(this->partial_result, val);
}
