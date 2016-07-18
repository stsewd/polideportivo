#include "sociodao.h"

socioDAO::socioDAO()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

Socio socioDAO::add(Socio &socio)
{
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where cedula = '"+socio.cedula+"'");
        if(dataBase->resultset->rowsCount() == 0){
            dataBase->statement->execute("INSERT INTO Persona values('"+socio.cedula+"','"+socio.nombre+"','"+socio.apellido+"','"+socio.direccion+"','"+socio.telefono+"')");
        }



         std::string esActivo= socio.estaActivo ? "1" : "0";
        dataBase->statement->execute("INSERT INTO Socio values('"+socio.cedula+"', '"+ socio.fechaIngreso +"','"+esActivo+"')");
    }catch(...){
        throw "No se puedo ingresar el socio";
    }
    return socio;
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
