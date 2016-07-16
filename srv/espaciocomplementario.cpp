#include "espaciocomplementario.h"


EspacioComplementario::EspacioComplementario(){

}

EspacioComplementario::EspacioComplementario(
        std::string nombre, std::string descripcion, double precioPorhora, int capacidad,
        Estado estado, Horario horario, TipoEspacioComplementario TipoEspacio):
    Espacio(nombre, descripcion, precioPorhora, capacidad, estado, horario)
{

}

EspacioComplementario::~EspacioComplementario()
{

}

