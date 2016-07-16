#include "espaciodeportivo.h"

EspacioDeportivo::EspacioDeportivo()
{
}

EspacioDeportivo::EspacioDeportivo(
        int id, std::string nombre, std::string descripcion, double precioPorhora, int capacidad,
        Estado estado, Horario horario, TipoEspacioDeportivo TipoEspacio):
    Espacio(id, nombre, descripcion, precioPorhora, capacidad, estado, horario)
{

}

EspacioDeportivo::~EspacioDeportivo()
{

}
