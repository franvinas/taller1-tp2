#ifndef OP_MIN_H
#define OP_MIN_H

#include "Operation.h"

class Min: public Operation {
public:
    Min();
    virtual void apply(const unsigned short int val) override;
};

#endif
