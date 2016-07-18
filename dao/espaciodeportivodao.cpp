#include "espaciodeportivodao.h"


EspacioDeportivoDAO::EspacioDeportivoDAO()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");

}

EspacioDeportivo EspacioDeportivoDAO::add(EspacioDeportivo &espacio)
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
        dataBase->statement->execute("INSERT INTO EspacioDeportivo values('" + espacio.nombre + "', "+espacio.tipo+"')");
    }catch(...){
        throw "No se puede ingresar el Espacio Deportivo";
    }
}

EspacioDeportivo EspacioDeportivoDAO::mod(EspacioDeportivo &espacio)
{

}

void EspacioDeportivoDAO::del(std::__cxx11::string nombre)
{

}

EspacioDeportivo EspacioDeportivoDAO::get(std::__cxx11::string nombre)
{

}

std::vector<EspacioDeportivo> EspacioDeportivoDAO::get()
{

}
