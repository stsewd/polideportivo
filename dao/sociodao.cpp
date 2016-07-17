#include "sociodao.h"

socioDAO::socioDAO()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

Socio socioDAO::add(Socio &socio)
{

}

Socio socioDAO::mod(Socio &socio)
{

}

void socioDAO::del(std::__cxx11::string cedula)
{

}

Socio socioDAO::get(std::__cxx11::string cedula)
{

}

std::vector<Socio> socioDAO::get()
{

}
