#ifndef ESPACIODEPORTIVO_H
#define ESPACIODEPORTIVO_H

#include <string>

#include "espacio.h"

class TipoEspacioDeportivo {
    std::string nombre;
};

class EspacioDeportivo : public Espacio {
    TipoEspacioDeportivo tipo;
public:
    EspacioDeportivo();
    EspacioDeportivo(int id, std::string nombre, std::string descripcion, double precioPorhora, int capacidad,Estado estado, Horario horario, TipoEspacioDeportivo TipoEspacio);
    ~EspacioDeportivo();
};

#endif // ESPACIODEPORTIVO_H
