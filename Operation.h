#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <mutex>

class Operation {
protected:
    unsigned short int partial_result;
    bool result_returned;
    std::mutex mutex;
public:
    /*
     *  Constructor
     */
    Operation();
    /*
     *  Aplica la operacion que corresponde usando el valor de b
     */
    virtual void apply(const unsigned short int val) = 0;
    /*
     *  Imprime el resultado (solo si todavia no fue impreso)
     */
    virtual std::string get_result();
    /*
     *  Destructor
     */
    virtual ~Operation();
};

#endif
