#ifndef CLIENTEDAO_H
#define CLIENTEDAO_H

#include <string>
#include <vector>
#include "conexiondb.h"
#include "../srv/cliente.h"

class clienteDAO
{
public:
    clienteDAO();
    ConexionDB* dataBase;

    Cliente add(Cliente& espacio);
    Cliente mod(Cliente& espacio);
    void del(std::string cedula);
    Cliente get(std::string cedula);
    std::vector<Cliente> get();
};

#endif // CLIENTEDAO_H
