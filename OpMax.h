#ifndef OP_MAX_H
#define OP_MAX_H

#include "Operation.h"

class Max: public Operation {
public:
    /*
     *  Constructor
     */
    Max();
    /*
     *  Guarda en partial_result el maximo entre el resultado parcial y val
     */
    virtual void apply(const unsigned short int val) override;
};

#endif
