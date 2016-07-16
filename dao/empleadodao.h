#ifndef ADMINISTRADORDAO_H
#define ADMINISTRADORDAO_H

#include <string>
#include <vector>

#include "../srv/empleado.h"

class EmpleadoDAO
{
public:
    EmpleadoDAO();


    Empleado add(Empleado& espacio);
    Empleado mod(Empleado& espacio);
    void del(std::string cedula);
    Empleado get(std::string cedula);
    std::vector<Empleado> get();
};

#endif // ADMINISTRADORDAO_H
