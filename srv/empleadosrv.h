#ifndef EMPLEADOSRV_H
#define EMPLEADOSRV_H

#include <vector>

#include "empleado.h"
#include "../dao/empleadodao.h"

class EmpleadoSrv
{
public:
    EmpleadoDAO dataBase;

    EmpleadoSrv();

    Empleado add(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
                 std::string telefono, std::string clave, bool esAdministrador
    );

    Empleado mod(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
                 std::string telefono
    );

    void modClave(std::string cedula, std::string clave);

    void modIsAdministrador(std::string cedula, bool esAdministrador);

    void del(std::string cedula);

    Empleado get(std::string cedula);

    std::vector<Empleado> get();
};

#endif // EMPLEADOSRV_H
