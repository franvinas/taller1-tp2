#include "ResultsMonitor.h"
#include <iostream>
#include <string>
#include <utility>

/***********************
    Metodos publicos
************************/

void ResultsMonitor::add_result(std::string &result) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->results.push_back(std::move(result));
}

void ResultsMonitor::print_results() {
    std::lock_guard<std::mutex> lock(this->mutex);
    for (std::string r : this->results)
        std::cout << r << "\n";
}
