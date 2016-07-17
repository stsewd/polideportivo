#include "clientesrv.h"
#include "tools.h"

ClienteSrv::ClienteSrv()
{

}

Cliente ClienteSrv::add(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono)
{
    validarCedula(cedula);
    validarVacio(nombre);
    validarVacio(apellido);
    validarVacio(direccion);
    validarTelefono(telefono);

    Cliente cliente(cedula, nombre, apellido, direccion, telefono);
    dataBase.add(cliente);

    return cliente;
}

Cliente ClienteSrv::mod(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono)
{
    Cliente cliente = get(cedula);

    validarVacio(nombre);
    validarVacio(apellido);
    validarVacio(direccion);
    validarTelefono(telefono);

    cliente.nombre = nombre;
    cliente.apellido = apellido;
    cliente.direccion = direccion;
    cliente.telefono = telefono;

    dataBase.mod(cliente);

    return cliente;
}
