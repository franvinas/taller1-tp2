#ifndef OP_SUM_H
#define OP_SUM_H

#include "Operation.h"

class Sum: public Operation {
public:
    Sum();
    virtual void apply(const unsigned short int val) override;
};

#endif
