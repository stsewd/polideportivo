#include "persona.h"

Persona::Persona()
{

}
Persona::Persona(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono)
{
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->direccion = direccion;
    this->telefono = telefono;
}

Persona::~Persona()
{

}
