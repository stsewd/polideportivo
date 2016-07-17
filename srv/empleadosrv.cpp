#include "empleadosrv.h"
#include "empleado.h"
#include "tools.h"

EmpleadoSrv::EmpleadoSrv()
{

}

Empleado EmpleadoSrv::add(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
                          std::string telefono, std::string clave, bool esAdministrador
                        )
{
    validarCedula(cedula);
    validarString(nombre);
    validarString(apellido);
    validarString(direccion);
    validarTelefono(telefono);
    validarString(clave);

    Empleado empleado(cedula, nombre, apellido, direccion, telefono, clave, esAdministrador);
    dataBase.add(empleado);

    return empleado;
}

Empleado EmpleadoSrv::mod(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
                          std::string telefono
                        )
{
    Empleado empleado = get(cedula);

    validarString(nombre);
    validarString(apellido);
    validarString(direccion);
    validarTelefono(telefono);

    empleado.nombre = nombre;
    empleado.apellido = apellido;
    empleado.direccion = direccion;
    empleado.telefono = telefono;

    dataBase.mod(empleado);

    return empleado;
}

void EmpleadoSrv::modClave(std::string cedula, std::string clave)
{
    dataBase.modClave(cedula, clave);
}

void EmpleadoSrv::modIsAdministrador(std::string cedula, bool esAdministrador)
{
    dataBase.modIsAdministrador(cedula, esAdministrador);
}

void EmpleadoSrv::del(std::string cedula)
{
    dataBase.del(cedula);
}

Empleado EmpleadoSrv::get(std::string cedula)
{
    return dataBase.get(cedula);
}

std::vector<Empleado> EmpleadoSrv::get()
{
    return dataBase.get();
}
