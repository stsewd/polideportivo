#include "socio.h"

Socio::Socio()
{

}

Socio::Socio(
        std::string cedula, std::string nombre, std::string apellido, std::string direccion,
        std::string telefono):
    Cliente(cedula, nombre, apellido, direccion,telefono)
{
    // ok, sin constructor
}

Socio::~Socio()
{

}
