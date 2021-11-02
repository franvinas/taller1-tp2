#ifndef RESULTS_MONITOR_H
#define RESULTS_MONITOR_H

#include <vector>
#include <string>
#include <mutex>

class ResultsMonitor {
private:
    std::vector<std::string> results;
    std::mutex mutex;

public:
    void add_result(std::string &result);
    void print_results();
};

#endif
