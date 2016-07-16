#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
    std::string nombre;
    std::string apellido;
    std::string cedula;
    std::string direccion;
    std::string telefono;
public:
    Persona();
    Persona(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono);
    ~Persona();
};

#endif // PERSONA_H
