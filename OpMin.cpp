#include "OpMin.h"
#include <algorithm>

/***********************
    Metodos publicos
************************/

Min::Min() : Operation(-1) {}

void Min::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->partial_result = std::min(this->partial_result, val);
}

