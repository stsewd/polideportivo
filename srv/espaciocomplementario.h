#ifndef ESPACIOCOIMPLEMENTARIO_H
#define ESPACIOCOIMPLEMENTARIO_H

#include <string>

#include "espacio.h"

class TipoEspacioComplementario {
    std::string nombre;
};

class EspacioComplementario : public Espacio {
    TipoEspacioComplementario tipo;
public:
    EspacioComplementario();
    EspacioComplementario(int id, std::string nombre, std::string descripcion, double precioPorhora, int capacidad, Estado estado, Horario horario, TipoEspacioComplementario TipoEspacio);
    ~EspacioComplementario();
};

#endif // ESPACIOCOIMPLEMENTARIO_H
