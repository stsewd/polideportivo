#ifndef ADMINISTRADORDAO_H
#define ADMINISTRADORDAO_H

#include <string>
#include <vector>

#include "../srv/empleado.h"
#include "conexiondb.h"

class EmpleadoDAO
{
public:
    EmpleadoDAO();
    ConexionDB* dataBase;

    Empleado add(Empleado& empleado);
    Empleado mod(Empleado& empleado);
    void del(std::string cedula);
    Empleado get(std::string cedula);
    std::vector<Empleado> get();
    void modClave(std::string cedula, std::string clave);
    void modIsAdministrador(std::string cedula, bool clave);
};

#endif // ADMINISTRADORDAO_H
