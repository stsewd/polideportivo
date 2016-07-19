#include "empleadodao.h"

EmpleadoDAO::EmpleadoDAO()
{

    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

Empleado EmpleadoDAO::add(Empleado &empleado)
{
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where cedula = '"+empleado.cedula+"'");
        if(dataBase->resultset->rowsCount() == 0){
            dataBase->statement->execute("INSERT INTO Persona values('"+empleado.cedula+"','"+empleado.nombre+"','"+empleado.apellido+"','"+empleado.direccion+"','"+empleado.telefono+"')");
        }

        std::string esAdministrador = empleado.esAdministrador ? "1" : "0";

        dataBase->statement->execute("INSERT INTO Empleado values('" + empleado.cedula + "','" + empleado.clave + "','" + esAdministrador + "')");

    }catch(...){
        throw std::string("No se puedo ingresar el empleado");
    }
    return empleado;
}

Empleado EmpleadoDAO::mod(Empleado &empleado)
{
    try{
        std::string consul= "UPDATE Persona SET nombre='"+empleado.nombre+"',apellido = '"+empleado.apellido+"', direccion = '"+
                empleado.direccion+"', telefono = '"+empleado.telefono+"' WHERE cedula='"+empleado.cedula+"'";
        dataBase->statement->execute(consul);

    }catch(...){
        throw std::string("No se puede modificar");
    }

    return empleado;
}

void EmpleadoDAO::del(std::string cedula)
{
    try{
        dataBase->statement->execute("DELETE FROM Empleado where idEmpleado='"+cedula+"'");
    }catch(...){
        throw std::string("No se puede eliminar");
    }
}

Empleado EmpleadoDAO::get(std::string cedula)
{
    Empleado empleado;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("select * from Persona P, Empleado C where C.idEmpleado='" + cedula + "' and P.cedula = C.idEmpleado ");
        if (dataBase->resultset->next()){
            empleado.cedula = dataBase->resultset->getString(1);
            empleado.nombre = dataBase->resultset->getString(2);
            empleado.apellido= dataBase->resultset->getString(3);
            empleado.direccion= dataBase->resultset->getString(4);
            empleado.telefono= dataBase->resultset->getString(5);
            empleado.clave = dataBase->resultset->getString(7);
            empleado.esAdministrador = dataBase->resultset->getString(8) == "1";
        } else {
            throw std::string("Usuario no existe");
        }
    }catch(...){
        throw std::string("No se puede extraer el empleado");
    }
    return empleado;
}

std::vector<Empleado> EmpleadoDAO::get()
{
    Empleado empleado;
    std::vector<Empleado> empleados;
    bool esAdministrador = false;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("select * from Persona P, Empleado C where P.cedula = C.idEmpleado ");
        while(dataBase->resultset->next()){
            empleado.cedula = dataBase->resultset->getString(1);
            empleado.nombre = dataBase->resultset->getString(2);
            empleado.apellido= dataBase->resultset->getString(3);
            empleado.direccion= dataBase->resultset->getString(4);
            empleado.telefono= dataBase->resultset->getString(5);
            empleado.clave = dataBase->resultset->getString(7);
            empleado.esAdministrador = dataBase->resultset->getString(8) == "1";
            empleados.push_back(empleado);
        }
    }catch(...){
        throw std::string("No se puede extraer el empleado");
    }

    return empleados;

}

void EmpleadoDAO::modClave(std::string cedula, std::string clave)
{
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where cedula = '"+cedula+"'");
        dataBase->statement->execute("UPDATE Empleado SET clave = '"+ clave +"' where idEmpleado='"+cedula+"'");

    }catch(...){
        throw std::string("No se puedo modificar la clave del empleado");
    }
}

void EmpleadoDAO::modIsAdministrador(std::__cxx11::string cedula, bool clave)
{
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where cedula = '"+cedula+"'");
        std::string esAdministrador = clave ? "1" : "0";
        dataBase->statement->execute("UPDATE Empleado SET esAdministrador = '"+ esAdministrador +"' where idEmpleado='"+cedula+"'");

    }catch(...){
        throw std::string("No se puedo modificar la clave del empleado");
    }
}
