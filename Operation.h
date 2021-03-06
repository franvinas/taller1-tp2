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
    explicit Operation(unsigned short int partial_result);
    /*
     *  Aplica la operacion que corresponde entre el resultado parcial y val
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
