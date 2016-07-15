#ifndef ESPACIOCOIMPLEMENTARIO_H
#define ESPACIOCOIMPLEMENTARIO_H

#include "espacio.h"

class TipoEspacioComplementario {
    std::string nombre;
};

class EspacioCoimplementario : public Espacio {
    TipoEspacioComplementario tipo;
public:
    EspacioCoimplementario();
};

#endif // ESPACIOCOIMPLEMENTARIO_H
