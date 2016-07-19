#include "espacio.h"

Espacio::Espacio()
{
}

Espacio::Espacio(std::string nombre, std::string descripcion, double precioPorhora,
                 int capacidad, Estado estado, Horario horario
                )
{

}

Espacio::~Espacio()
{

}

std::string Hora::getHora()
{
    std::string ret = std::to_string(this->hora) +":"+ std::to_string(this->minuto) + ":00";
    return (ret);

}
