#include "OpSum.h"

/***********************
    Metodos publicos
************************/

Sum::Sum() : Operation(0) {}

void Sum::apply(const unsigned short int val) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->partial_result += val;
}
