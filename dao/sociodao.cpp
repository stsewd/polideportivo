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
        //std::string fecha = getFecha(&socio.fechaIngreso);
        std::string esActivo= socio.estaActivo ? "1" : "0";
        dataBase->statement->execute("INSERT INTO Socio values('" + socio.cedula + "', '" + getFecha(&(socio.fechaIngreso)) +"','"+ esActivo + "')");
    }catch(...){
        throw std::string("No se puedo ingresar el socio");
    }
    return socio;
}

Socio socioDAO::mod(Socio &socio)
{
    try{
        std::string consul= "UPDATE Persona SET nombre='"+socio.nombre+"',apellido = '"+socio.apellido+"', direccion = '"+
                socio.direccion+"', telefono = '"+socio.telefono+"' WHERE cedula='"+socio.cedula+"'";
        dataBase->statement->execute(consul);
    }catch(...){
        throw std::string("No se puede modificar");
    }

    return socio;
}

void socioDAO::del(std::string cedula)
{
    try{
        dataBase->statement->execute("DELETE FROM socio where idSocio='"+cedula+"'");
    }catch(...){
        throw std::string("No se puede eliminar");
    }
}

Socio socioDAO::get(std::string cedula)
{
    Socio socio;
    bool esActivo;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("select * from Persona P, Socio C where C.idSocio='"+cedula+" and P.cedula = C.idSocio");
        //dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Socio where idSocio='"+cedula+"'");
        //dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where idSocio='"+cedula+"'");
        while(dataBase->resultset->next()){
            socio.cedula = dataBase->resultset->getString(1);
            socio.nombre = dataBase->resultset->getString(2);
            socio.apellido= dataBase->resultset->getString(3);
            socio.direccion= dataBase->resultset->getString(4);
            socio.telefono= dataBase->resultset->getString(5);
            socio.fechaIngreso = getFechaString(dataBase->resultset->getString(7));
            socio.estaActivo = dataBase->resultset->getString(8) == "1";

        }
    }catch(...){
        throw std::string("No se puede extraer el socio");
    }

    return socio;
}

std::vector<Socio> socioDAO::get()
{
    Socio socio;
    std::vector<Socio> socios;
    bool esActivo;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("select * from Persona P, Socio C where P.cedula = C.idSocio");
        //dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Socio where idSocio='"+cedula+"'");
        //dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where idSocio='"+cedula+"'");
        while(dataBase->resultset->next()){
            socio.cedula = dataBase->resultset->getString(1);
            socio.nombre = dataBase->resultset->getString(2);
            socio.apellido= dataBase->resultset->getString(3);
            socio.direccion= dataBase->resultset->getString(4);
            socio.telefono= dataBase->resultset->getString(5);
            socio.fechaIngreso = getFechaString(dataBase->resultset->getString(7));
            socio.estaActivo = dataBase->resultset->getString(8) == "1";

        }
    }catch(...){
        throw std::string("No se puede extraer el socio");
    }

    return socios;

}

void socioDAO::modEsActivo(std::string cedula, bool estado)
{
    try{
        std::string esActivo = estado ? "1" : "0";
        dataBase->statement->execute("UPDATE Socio SET estaActivo = '"+ esActivo +"' where idSocio='"+cedula+"'");
    }catch(...){
        throw std::string("No se peude cambiar el estado del socio");
    }

}
