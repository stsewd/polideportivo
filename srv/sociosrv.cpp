#include "sociosrv.h"
#include "tools.h"

SocioSrv::SocioSrv()
{

}

Socio SocioSrv::add(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
                    std::string telefono
                )
{
    validarCedula(cedula);
    validarString(nombre);
    validarString(apellido);
    validarString(direccion);
    validarTelefono(telefono);

    Socio socio(cedula, nombre, apellido, direccion, telefono);
    dataBase.add(socio);

    return socio;
}

Socio SocioSrv::mod(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
                    std::string telefono, bool estaActivo
                )
{
    Socio socio = get(cedula);

    validarString(nombre);
    validarString(apellido);
    validarString(direccion);
    validarTelefono(telefono);

    socio.nombre = nombre;
    socio.apellido = apellido;
    socio.direccion = direccion;
    socio.telefono = telefono;
    socio.estaActivo = estaActivo;

    dataBase.mod(socio);

    return socio;
}

void SocioSrv::del(std::string cedula)
{
    dataBase.del(cedula);
}

Socio SocioSrv::get(std::string cedula)
{
    return dataBase.get(cedula);
}

std::vector<Socio> SocioSrv::get()
{
    return dataBase.get();
}
