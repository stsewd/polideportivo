#ifndef SOCIODAO_H
#define SOCIODAO_H

#include <string>
#include <vector>
#include <ctime>

#include "../srv/socio.h"
#include "conexiondb.h"
#include "../srv/tools.h"

class socioDAO
{
public:
    socioDAO();
    ConexionDB* dataBase;
    Socio add(Socio& socio);
    Socio mod(Socio& socio);
    void del(std::string cedula);
    Socio get(std::string cedula);
    std::vector<Socio> get();
    void modEsActivo(std::string cedula, bool estado);
};

#endif // SOCIODAO_H
