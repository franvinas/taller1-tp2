#ifndef OP_MEAN_H
#define OP_MEAN_H

#include "Operation.h"
#include <string>

class Mean: public Operation {
private:
    unsigned short int sum;
    unsigned short int n;
public:
    Mean();
    virtual void apply(const unsigned short int val) override;
    virtual std::string get_result() override;
};

#endif
