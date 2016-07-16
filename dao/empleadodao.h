#ifndef ADMINISTRADORDAO_H
#define ADMINISTRADORDAO_H

#include <string>
#include <vector>

#include "../srv/administrador.h"

class administradorDAO
{
public:
    administradorDAO();


    Administrador add(Administrador& espacio);
    Administrador mod(Administrador& espacio);
    void del(std::string cedula);
    Administrador get(std::string cedula);
    std::vector<Administrador> get();
};

#endif // ADMINISTRADORDAO_H
