#ifndef ESPACIODEPORTIVO_H
#define ESPACIODEPORTIVO_H


class TipoEspacioDeportivo {
    std::string nombre;
};

class EspacioDeportivo : public Espacio {
    TipoEspacioDeportivo tipo;
public:
    EspacioDeportivo();
};

#endif // ESPACIODEPORTIVO_H
