#include "espaciodeportivo.h"

TipoEspacioDeportivo::TipoEspacioDeportivo(){
}

EspacioDeportivo::EspacioDeportivo()
{
}

EspacioDeportivo::EspacioDeportivo(
        std::string nombre, std::string descripcion, double precioPorHora, int capacidad,
        Estado estado, Horario horario, TipoEspacioDeportivo tipoEspacio):
    Espacio(nombre, descripcion, precioPorHora, capacidad, estado, horario)
{
    this->tipo = tipoEspacio;
}

EspacioDeportivo::~EspacioDeportivo()
{

}
