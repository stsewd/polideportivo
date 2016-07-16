#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"

class Empleado : public Persona {
    std::string clave;
    bool esAdministrador;
public:
    Empleado();
};

#endif // EMPLEADO_H
