#include "espaciocomplementariodao.h"


EspacioComplementarioDAO::EspacioComplementarioDAO()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

EspacioComplementario EspacioComplementarioDAO::add(EspacioComplementario &espacio)
{
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio WHERE nombre = '" + espacio.nombre);
        if(dataBase->resultset->rowsCount()==0){
            std::string fechaIngreso = getFecha(espacio.horario.entrada);
            std::string fechaSalida = getFecha(espacio.horario.salida);
            dataBase->statement->execute("INSERT INTO Espacio values('"+
                                         espacio.nombre + "', '" + espacio.descripcion + "', '" +
                                         espacio.precioPorhora + "', '" + espacio.capacidad + "', '" + espacio.estado +
                                         "', '" + fechaIngreso + "', '" + fechaSalida + "')");
        }
        dataBase->statement->execute("INSERT INTO EspacioComplementario values('" + espacio.nombre + "', "+espacio.tipo+"')");
    }catch(...){
        throw "No se puede ingresar el Espacio Complementario";
    }
    return espacio;
}

EspacioComplementario EspacioComplementarioDAO::mod(EspacioComplementario &espacio)
{
    try{
    std::string fechaIngreso = getFecha(espacio.horario.entrada);
    std::string fechaSalida = getFecha(espacio.horario.salida);
    std::string  consul = "UPDATE Espacio SET descripcion='" + espacio.descripcion + "', precioHora='" +
            espacio.precioPorhora+"', capacidad='" + espacio.capacidad + "', estado='"+espacio.estado+
            "', horarioEntrada='"+fechaIngreso+"', horarioSalida='"+fechaSalida+"' WHERE nombre='" +
            espacio.nombre + "'";
    dataBase->statement->execute(consul);
    }catch(...){
        throw "No se puede actualizar el espacio Complementario";
    }

    return espacio;
}

void EspacioComplementarioDAO::del(std::__cxx11::string nombre)
{
    try{
        dataBase->statement->execute("DELETE FROM EspacioComplementario WHERE idEspacioComplementario='"+nombre+"'");
    }catch(...){
        throw "No  se puede eliminar el espacio Complementario";
    }
}

EspacioComplementario EspacioComplementarioDAO::get(std::__cxx11::string nombre)
{
    EspacioComplementario espacio;
    try{
    dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio E, EspacioComplementario D WHERE D.idEspacioComplementario='" +nombre +
                                                          "' AND E.nombre = D.idEspacioComplementario");
    while(dataBase->resultset->next()){
        espacio.nombre = dataBase->resultset->getString(0);
        espacio.descripcion = dataBase->resultset->getString(1);
        double num = atof( dataBase->resultset->getString(2).c_str() );
        espacio.precioPorhora = num;
        espacio.capacidad = std::stoi(dataBase->resultset->getString(3).c_str());
        espacio.estado = dataBase->resultset->getString(4);
        espacio.horario.entrada=getFecha(dataBase->resultset->getString(4));
        espacio.horario.salida=getFecha(dataBase->resultset->getString(6));
        espacio.tipo=dataBase->resultset->getString(8);
    }
    }catch(...){
        throw "No  se puede obtener espacio complementario";
    }
    return espacio;
}

std::vector<EspacioComplementario> EspacioComplementarioDAO::get()
{
    EspacioComplementario espacio;
    std::vector<EspacioComplementario> espacios;
    try{
    dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio E, EspacioComplementario D WHERE D.idEspacioComplementario='" +nombre +
                                                          "' AND E.nombre = D.idEspacioComplementario");
    while(dataBase->resultset->next()){
        espacio.nombre = dataBase->resultset->getString(0);
        espacio.descripcion = dataBase->resultset->getString(1);
        double num = atof( dataBase->resultset->getString(2).c_str() );
        espacio.precioPorhora = num;
        espacio.capacidad = std::stoi(dataBase->resultset->getString(3).c_str());
        espacio.estado = dataBase->resultset->getString(4);
        espacio.horario.entrada=getFecha(dataBase->resultset->getString(4));
        espacio.horario.salida=getFecha(dataBase->resultset->getString(6));
        espacio.tipo=dataBase->resultset->getString(8);
        espacios.push_back(espacio);
    }
    }catch(...){
        throw "No  se puede obtener espacio complementario";
    }
    return espacios;
}

void EspacioComplementarioDAO::modTipo(std::__cxx11::string nombre, std::__cxx11::string tipo)
{
    try{
        dataBase->statement->execute("UPDATE FROM EspacioComplementario SET tipoEspacioComplementario='" + tipo +
                                     "' WHERE idEspacioComplementario='"+nombre+"'");
    }catch(...){
        throw "No  se puede actualizar el espacio complementario";
    }
}
