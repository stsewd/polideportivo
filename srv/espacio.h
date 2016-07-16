#ifndef ESPACIO_H
#define ESPACIO_H

#include <string>

enum class Estado {
    libre,
    ocupado,
    reservado,
    mantenimiento
};

class Hora {
    int hora;
    int minuto;
};

class Horario {
    Hora entrada;
    Hora salida;
};

class Espacio {
    int id;
    std::string nombre;
    std::string descripcion;
    double precioPorhora;
    int capacidad;
    Estado estado;
    Horario horario;
public:
    Espacio();
};

#endif // ESPACIO_H