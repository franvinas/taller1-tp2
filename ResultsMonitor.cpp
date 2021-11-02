#include "ResultsMonitor.h"
#include <iostream>

void ResultsMonitor::add_result(std::string &result) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->results.push_back(std::move(result));
}

void ResultsMonitor::print_results() {
    std::lock_guard<std::mutex> lock(this->mutex);
    for (size_t i = 0; i < this->results.size(); i++)
        std::cout << this->results.at(i) << "\n";
}
