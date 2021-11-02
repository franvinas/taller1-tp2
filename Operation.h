#ifndef OPERATION_H
#define OPERATION_H

#include <mutex>
// las operaciones posibles son sum, mean, min y max.

class Operation {
protected:
    unsigned short int partial_result;
    bool result_printed;
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
    virtual void print_result();
    /*
     *  Destructor
     */
    virtual ~Operation();
};

class Sum: public Operation {
public:
    Sum();
    virtual void apply(const unsigned short int val) override;
};

class Mean: public Operation {
private:
    unsigned short int sum;
    unsigned short int n;
public:
    Mean();
    virtual void apply(const unsigned short int val) override;
    virtual void print_result() override;
};

class Min: public Operation {
public:
    Min();
    virtual void apply(const unsigned short int val) override;
};

class Max: public Operation {
public:
    Max();
    virtual void apply(const unsigned short int val) override;
};

#endif
