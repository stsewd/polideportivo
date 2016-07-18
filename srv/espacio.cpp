#include "espacio.h"

Espacio::Espacio()
{
}

Espacio::Espacio(std::string nombre, std::string descripcion, double precioPorhora,
                 int capacidad, Estado estado, Horario horario
                )
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->precioPorhora = precioPorhora;
    this->capacidad = capacidad;
    this->estado = estado;
    this->horario = horario;
}

Espacio::~Espacio()
{

}
