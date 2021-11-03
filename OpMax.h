#ifndef OP_MAX_H
#define OP_MAX_H

#include "Operation.h"

class Max: public Operation {
public:
    Max();
    virtual void apply(const unsigned short int val) override;
};

#endif
