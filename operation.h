#ifndef OPERATION_H
#define OPERATION_H

#include <mutex>
// las operaciones posibles son sum, mean, min y max.

class Operation {
protected:
    unsigned short int a;
    std::mutex mutex;
public:
    virtual void apply(unsigned short int b) = 0;
    virtual void print_result();
    virtual ~Operation();
};

class Sum: public Operation {
public:
    Sum();
    virtual void apply(unsigned short int b) override;
};

class Mean: public Operation {
private:
    unsigned short int sum;
    unsigned short int n;
public:
    Mean();
    virtual void apply(unsigned short int b) override;
    virtual void print_result() override;
};

class Min: public Operation {
public:
    Min();
    virtual void apply(unsigned short int b) override;
};

class Max: public Operation {
public:
    Max();
    virtual void apply(unsigned short int b) override;
};

#endif
