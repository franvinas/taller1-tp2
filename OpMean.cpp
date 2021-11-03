#include "OpMean.h"
#include <string>

Mean::Mean() : Operation(0), sum(0), n(0) {}

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
