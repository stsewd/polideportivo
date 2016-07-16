#ifndef ESPACIOCOIMPLEMENTARIO_H
#define ESPACIOCOIMPLEMENTARIO_H

#include "espacio.h"

class TipoEspacioComplementario {
    std::string nombre;
};

class EspacioComplementario : public Espacio {
    TipoEspacioComplementario tipo;
public:
    EspacioComplementario();
};

#endif // ESPACIOCOIMPLEMENTARIO_H
