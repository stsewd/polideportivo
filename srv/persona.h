#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
public:
    std::string nombre;
    std::string apellido;
    std::string cedula;
    std::string direccion;
    std::string telefono;

    Persona();
    Persona(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono);
    ~Persona();
};

#endif // PERSONA_H
