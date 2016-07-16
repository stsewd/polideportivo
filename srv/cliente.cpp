#include "cliente.h"

Cliente::Cliente()
{

}

Cliente::Cliente (
        std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono):
    Persona(cedula, nombre, apellido, direccion,telefono)
{

}

Cliente::~Cliente()
{

}
