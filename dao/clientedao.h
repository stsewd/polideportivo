#ifndef CLIENTEDAO_H
#define CLIENTEDAO_H

#include <string>
#include <vector>
#include "conexiondb.h"
#include "../srv/cliente.h"

class ClienteDAO
{
public:
    ClienteDAO();
    ConexionDB* dataBase;

    Cliente add(Cliente& cliente);
    Cliente mod(Cliente& cliente);
    void del(std::string cedula);
    Cliente get(std::string cedula);
    std::vector<Cliente> get();
};

#endif // CLIENTEDAO_H
