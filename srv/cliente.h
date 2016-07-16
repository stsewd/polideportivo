#ifndef CLIENTE_H
#define CLIENTE_H

#include "persona.h"
#include <string>

class Cliente : public Persona {
public:
    Cliente();
    Cliente(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono);
    ~Cliente();
};

#endif // CLIENTE_H
