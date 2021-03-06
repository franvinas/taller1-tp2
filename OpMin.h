#ifndef OP_MIN_H
#define OP_MIN_H

#include "Operation.h"

class Min: public Operation {
public:
    /*
     *  Constructor
     */
    Min();
    /*
     *  Guarda en partial_result el minimo entre el resultado parcial y val
     */
    virtual void apply(const unsigned short int val) override;
};

#endif
