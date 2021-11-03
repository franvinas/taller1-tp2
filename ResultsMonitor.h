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
    /*
     *  Guarda el valor que recibe por parametro
     */
    void add_result(std::string &result);
    /*
     *  Imprime los resultados en el orden que fueron recibidos
     */
    void print_results();
};

#endif
