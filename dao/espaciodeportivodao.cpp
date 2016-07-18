#include "espaciodeportivodao.h"
#include <string>
#include "../srv/tools.h"

EspacioDeportivoDAO::EspacioDeportivoDAO()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");

}

EspacioDeportivo EspacioDeportivoDAO::add(EspacioDeportivo &espacio)
{
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio WHERE nombre = '" + espacio.nombre);
        if(dataBase->resultset->rowsCount()==0){
            //std::string fechaIngreso = getFecha(espacio.horario.entrada);
            //std::string fechaSalida = getFecha(espacio.horario.salida);
            dataBase->statement->execute("INSERT INTO Espacio values('"+
                                         espacio.nombre + "', '" + espacio.descripcion + "', '" +
                                         std::to_string(espacio.precioPorhora) + "', '" +
                                         std::to_string(espacio.capacidad) + "', '" + estadoToString(espacio.estado) +
                                         "', '" + espacio.horario.entrada.getHora() + "', '" + espacio.horario.salida.getHora() + "')"
            );
        }
        dataBase->statement->execute("INSERT INTO EspacioDeportivo values('" + espacio.nombre + "', " + espacio.tipo.nombre + "')");
    }catch(...){
        throw "No se puede ingresar el Espacio Deportivo";
    }
    return espacio;
}

EspacioDeportivo EspacioDeportivoDAO::mod(EspacioDeportivo &espacio)
{
    try{
    //std::string fechaIngreso = getFecha(espacio.horario.entrada);
    //std::string fechaSalida = getFecha(espacio.horario.salida);
    std::string  consul = "UPDATE Espacio SET descripcion='" + espacio.descripcion + "', precioHora='" +
            std::to_string(espacio.precioPorhora) + "', capacidad='" + std::to_string(espacio.capacidad) +
            "', estado='" + estadoToString(espacio.estado) +
            "', horarioEntrada='" + espacio.horario.entrada.getHora() + "', horarioSalida='" + espacio.horario.salida.getHora() +"' WHERE nombre='" +
            espacio.nombre +"'";
    dataBase->statement->execute(consul);
    }catch(...){
        throw "No se puede actualizar";
    }

    return espacio;
}

void EspacioDeportivoDAO::del(std::__cxx11::string nombre)
{
    try{
        dataBase->statement->execute("DELETE FROM EspacioDeportivo WHERE idEspacioDeportivo='"+nombre+"'");
    }catch(...){
        throw "No  se puede eliminar";
    }
}

EspacioDeportivo EspacioDeportivoDAO::get(std::__cxx11::string nombre)
{
    EspacioDeportivo espacio;
    try{
    dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio E, EspacioDeportivo D WHERE D.idEspacioDeportivo ='" +nombre +
                                                          "' AND E.nombre = D.idEspacioDeportivo");
    while(dataBase->resultset->next()){
        espacio.nombre = dataBase->resultset->getString(0);
        espacio.descripcion = dataBase->resultset->getString(1);
        double num = atof( dataBase->resultset->getString(2).c_str() );
        espacio.precioPorhora = num;
        espacio.capacidad = std::stoi(dataBase->resultset->getString(3).c_str());
        espacio.estado = getEstado(dataBase->resultset->getString(4).c_str());
        espacio.horario = getHorario(dataBase->resultset->getString(5), dataBase->resultset->getString(6));
        espacio.tipo.nombre = dataBase->resultset->getString(8);
    }
    }catch(...){
        throw "No  se puede obtener espacio deportivo";
    }
    return espacio;
}

std::vector<EspacioDeportivo> EspacioDeportivoDAO::get()
{
    EspacioDeportivo espacio;
    std::vector<EspacioDeportivo> espacios;
    try{
    dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio E, EspacioDeportivo D WHERE E.nombre = D.idEspacioDeportivo");
    while(dataBase->resultset->next()){
        espacio.nombre = dataBase->resultset->getString(0);
        espacio.descripcion = dataBase->resultset->getString(1);
        double num = atof( dataBase->resultset->getString(2).c_str() );
        espacio.precioPorhora = num;
        espacio.capacidad = std::stoi(dataBase->resultset->getString(3).c_str());
        espacio.estado = getEstado(dataBase->resultset->getString(4));
        espacio.horario = getHorario(dataBase->resultset->getString(5), dataBase->resultset->getString(6));
        espacio.tipo.nombre = dataBase->resultset->getString(8);
        espacios.push_back(espacio);
    }
    }catch(...){
        throw "No  se puede obtener la lista de espacio deportivos";
    }
    return espacios;
}

void EspacioDeportivoDAO::modTipo(std::string nombre, std::__cxx11::string tipo)
{
    try{
        dataBase->statement->execute("UPDATE FROM EspacioDeportivo SET tipoEspacioDeportivo='" + tipo +
                                     "' WHERE idEspacioDeportivo='"+nombre+"'");
    }catch(...){
        throw "No  se puede actualizar el espacio deportivo";
    }
}

