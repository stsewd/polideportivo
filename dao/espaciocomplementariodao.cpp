#include "espaciocomplementariodao.h"



EspacioComplementarioDAO::EspacioComplementarioDAO()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

EspacioComplementario EspacioComplementarioDAO::add(EspacioComplementario espacio)
{
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio WHERE nombre = '" + espacio.nombre);
        if (dataBase->resultset->rowsCount()==0) {
            //std::string fechaIngreso = getFecha(espacio.horario.entrada);
            //std::string fechaSalida = getFecha(espacio.horario.salida);
            dataBase->statement->execute("INSERT INTO Espacio values('"+
                                         espacio.nombre + "', '" + espacio.descripcion + "', '" +
                                         std::to_string(espacio.precioPorhora) + "', '" + std::to_string(espacio.capacidad) + "', '" + estadoToString(espacio.estado) +
                                         "', '" + espacio.horario.entrada.getHora() + "', '" + espacio.horario.salida.getHora() + "')");
        }
        dataBase->statement->execute("INSERT INTO EspacioComplementario values('" + espacio.nombre + "', "+espacio.tipo.nombre+"')");
    }catch(...){
        throw std::string("No se puede ingresar el Espacio Complementario");
    }
    return espacio;
}

EspacioComplementario EspacioComplementarioDAO::mod(EspacioComplementario espacio)
{
    try{
    //std::string fechaIngreso = getFecha(espacio.horario.entrada);
    //std::string fechaSalida = getFecha(espacio.horario.salida);
    std::string  consul = "UPDATE Espacio SET descripcion='" + espacio.descripcion + "', precioHora='" +
            std::to_string(espacio.precioPorhora) + "', capacidad='" + std::to_string(espacio.capacidad) + "', estado='"+estadoToString(espacio.estado)+
            "', horarioEntrada='"+ espacio.horario.entrada.getHora() + "', horarioSalida='"+espacio.horario.salida.getHora() +"' WHERE nombre='" +
            espacio.nombre + "'";
    dataBase->statement->execute(consul);
    }catch(...){
        throw std::string("No se puede actualizar el espacio Complementario");
    }

    return espacio;
}

void EspacioComplementarioDAO::del(std::string nombre)
{
    try{
        dataBase->statement->execute("DELETE FROM EspacioComplementario WHERE idEspacioComplementario='"+nombre+"'");
    }catch(...){
        throw std::string("No  se puede eliminar el espacio Complementario");
    }
}

EspacioComplementario EspacioComplementarioDAO::get(std::string nombre)
{
    EspacioComplementario espacio;
    try{
    dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio E, EspacioComplementario D WHERE D.idEspacioComplementario='" +nombre +
                                                          "' AND E.nombre = D.idEspacioComplementario");
    while(dataBase->resultset->next()){
        espacio.nombre = dataBase->resultset->getString(1);
        espacio.descripcion = dataBase->resultset->getString(2);
        double num = atof( dataBase->resultset->getString(3).c_str() );
        espacio.precioPorhora = num;
        espacio.capacidad = std::stoi(dataBase->resultset->getString(4).c_str());
        espacio.estado = getEstado(dataBase->resultset->getString(5));
        espacio.horario = getHorario(dataBase->resultset->getString(6), dataBase->resultset->getString(7));
        espacio.tipo.nombre=dataBase->resultset->getString(9);
    }
    }catch(...){
        throw std::string("No  se puede obtener espacio complementario");
    }
    return espacio;
}

std::vector<EspacioComplementario> EspacioComplementarioDAO::get()
{
    EspacioComplementario espacio;
    std::vector<EspacioComplementario> espacios;
    try{
    dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Espacio E, EspacioComplementario D WHERE E.nombre = D.idEspacioComplementario");
    while(dataBase->resultset->next()){
        espacio.nombre = dataBase->resultset->getString(1);
        espacio.descripcion = dataBase->resultset->getString(2);
        double num = atof( dataBase->resultset->getString(3).c_str() );
        espacio.precioPorhora = num;
        espacio.capacidad = std::stoi(dataBase->resultset->getString(4).c_str());
        espacio.estado = getEstado(dataBase->resultset->getString(5));
        espacio.horario = getHorario(dataBase->resultset->getString(6), dataBase->resultset->getString(7));
        espacio.tipo.nombre = dataBase->resultset->getString(9);
        espacios.push_back(espacio);
    }
    }catch(...){
        throw std::string("No  se puede obtener espacio complementario");
    }
    return espacios;
}

void EspacioComplementarioDAO::modTipo(std::string nombre, std::string tipo)
{
    try{
        dataBase->statement->execute("UPDATE FROM EspacioComplementario SET tipoEspacioComplementario='" + tipo +
                                     "' WHERE idEspacioComplementario='"+nombre+"'");
    }catch(...){
        throw std::string("No  se puede actualizar el espacio complementario");
    }
}
