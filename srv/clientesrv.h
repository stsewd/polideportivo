#ifndef CLIENTESRV_H
#define CLIENTESRV_H

#include <string>

#include "../dao/clientedao.h"

class ClienteSrv
{
public:
    ClienteDAO dataBase;

    ClienteSrv();

    Cliente add(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono);
    Cliente mod(std::string cedula, std::string nombre, std::string apellido, std::string direccion, std::string telefono);
    void del(std::string cedula);
    Cliente get(std::string cedula);
    std::vector<Cliente> get();
};

#endif // CLIENTESRV_H
