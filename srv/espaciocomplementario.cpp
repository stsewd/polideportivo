#include "espaciocomplementario.h"


EspacioComplementario::EspacioComplementario(){

}

EspacioComplementario::EspacioComplementario(
        std::string nombre, std::string descripcion, double precioPorhora, int capacidad,
        Estado estado, Horario horario, TipoEspacioComplementario tipoEspacio):
    Espacio(nombre, descripcion, precioPorhora, capacidad, estado, horario)
{
    this->tipo = tipoEspacio;
}

EspacioComplementario::~EspacioComplementario()
{

}

