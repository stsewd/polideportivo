#ifndef SOCIODAO_H
#define SOCIODAO_H

#include <string>
#include <vector>

#include "../srv/socio.h"

class socioDAO
{
public:
    socioDAO();

    Socio add(Socio& espacio);
    Socio mod(Socio& espacio);
    void del(std::string cedula);
    Socio get(std::string cedula);
    std::vector<Socio> get();
};

#endif // SOCIODAO_H
