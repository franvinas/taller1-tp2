#ifndef OP_MEAN_H
#define OP_MEAN_H

#include "Operation.h"
#include <string>

class Mean: public Operation {
private:
    unsigned short int sum;
    unsigned short int n;
public:
    /*
     *  Constructor
     */
    Mean();
    /*
     *  Guarda la suma entre el resultado parcial y va. E incrementa el 
     *  contador para luego poder calcular el promedio.
     */
    virtual void apply(const unsigned short int val) override;
    /*
     *  Imprime el resultado (solo si todavia no fue impreso).
     *  Se imprime el resultado en fracciones.
     */
    virtual std::string get_result() override;
};

#endif
