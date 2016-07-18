#include "empleado.h"

Empleado::Empleado()
{

}

Empleado::Empleado(
        std::string cedula, std::string nombre, std::string apellido, std::string direccion,
        std::string telefono, std::string clave, bool esAdministrador):
    Persona(cedula, nombre, apellido, direccion,telefono)
{

}

Empleado::~Empleado()
{

}
