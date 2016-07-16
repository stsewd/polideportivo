#ifndef ESPACIOCOIMPLEMENTARIO_H
#define ESPACIOCOIMPLEMENTARIO_H

#include <string>

#include "espacio.h"

class TipoEspacioComplementario {
public:
    std::string nombre;
    TipoEspacioComplementario(){}
    TipoEspacioComplementario(std::string nombre){
        this->nombre = nombre;
    }
};

class EspacioComplementario : public Espacio {
public:
    TipoEspacioComplementario tipo;
    EspacioComplementario();
    EspacioComplementario(std::string nombre, std::string descripcion, double precioPorhora,
                          int capacidad, Estado estado, Horario horario, TipoEspacioComplementario TipoEspacio
    );

    ~EspacioComplementario();
};

#endif // ESPACIOCOIMPLEMENTARIO_H
