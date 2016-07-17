#ifndef SOCIOSRV_H
#define SOCIOSRV_H

#include "socio.h"
#include "../dao/sociodao.h"

class SocioSrv
{
public:
    socioDAO dataBase;

    SocioSrv();

    Socio add(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
              std::string telefono
    );

    Socio mod(std::string cedula, std::string nombre, std::string apellido, std::string direccion,
              std::string telefono, bool estaActivo
    );

    void del(std::string cedula);
    Socio get(std::string cedula);
    std::vector<Socio> get();
};

#endif // SOCIOSRV_H
