#include "espaciocomplementario.h"


EspacioComplementario::EspacioComplementario(){

}

EspacioComplementario::EspacioComplementario(
        int id, std::string nombre, std::string descripcion, double precioPorhora, int capacidad,
        Estado estado, Horario horario, TipoEspacioComplementario TipoEspacio):
    Espacio( id, nombre, descripcion, precioPorhora, capacidad, estado, horario)
{

}

EspacioComplementario::~EspacioComplementario()
{

}

