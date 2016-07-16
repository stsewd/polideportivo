#ifndef SOCIO_H
#define SOCIO_H

#include <ctime>

#include "cliente.h"

class Socio : public Cliente {
    time_t fechaIngreso;
    bool estaActivo;
public:
    Socio();
    Socio(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono, time_t fechaIngreso, bool estaActivo);
    ~Socio();
};

#endif // SOCIO_H
