#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>

#include "persona.h"

class Administrador : public Persona {
    std::string clave;
public:
    Administrador();
};

#endif // ADMINISTRADOR_H
