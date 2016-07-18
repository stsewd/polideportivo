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
public:
    int hora;
    int minuto;

    std::string getHora();
};

class Horario {
public:
    Hora entrada;
    Hora salida;


};

class Espacio {
public:
    std::string nombre;
    std::string descripcion;
    double precioPorhora;
    int capacidad;
    Estado estado;
    Horario horario;
public:
    Espacio();
    Espacio(std::string nombre, std::string descripcion, double precioPorhora, int capacidad, Estado estado, Horario horario);
    ~Espacio();
};

#endif // ESPACIO_H
