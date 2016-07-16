#ifndef ESPACIODEPORTIVO_H
#define ESPACIODEPORTIVO_H

#include <string>

#include "espacio.h"

class TipoEspacioDeportivo {
public:
    std::string nombre;
    TipoEspacioDeportivo();
    TipoEspacioDeportivo(std::string nombre) {
        this->nombre = nombre;
    }
};

class EspacioDeportivo : public Espacio {
public:
    TipoEspacioDeportivo tipo;
    EspacioDeportivo();
    EspacioDeportivo(std::string nombre, std::string descripcion, double precioPorhora, int capacidad,Estado estado, Horario horario, TipoEspacioDeportivo TipoEspacio);
    ~EspacioDeportivo();
};

#endif // ESPACIODEPORTIVO_H
