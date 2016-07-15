#ifndef ESPACIODEPORTIVO_H
#define ESPACIODEPORTIVO_H

#include "espacio.h"

class TipoEspacioDeportivo {
    std::string nombre;
};

class EspacioDeportivo : public Espacio {
    TipoEspacioDeportivo tipo;
public:
    EspacioDeportivo();
};

#endif // ESPACIODEPORTIVO_H
