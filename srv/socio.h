#ifndef SOCIO_H
#define SOCIO_H

#include <ctime>

#include "cliente.h"

class Socio : public Cliente {
    time_t fechaIngreso;
    bool estaActivo;
public:
    Socio();
};

#endif // SOCIO_H
