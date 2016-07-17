#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

#include "persona.h"

class Empleado : public Persona {
public:
    std::string clave;
    bool esAdministrador;

    Empleado();
    Empleado(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono, std::string clave, bool esAdministrador);
    ~Empleado();
};

#endif // EMPLEADO_H
