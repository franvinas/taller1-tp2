#ifndef OP_SUM_H
#define OP_SUM_H

#include "Operation.h"

class Sum: public Operation {
public:
    /*
     *  Constructor
     */
    Sum();
    /*
     *  Guarda la suma entre el resultado parcial y val
     */
    virtual void apply(const unsigned short int val) override;
};

#endif
