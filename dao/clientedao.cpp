#include "clientedao.h"

ClienteDAO::ClienteDAO()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

Cliente ClienteDAO::add(Cliente &cliente)
{
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where cedula = '"+cliente.cedula+"'");
        if(dataBase->resultset->rowsCount() == 0){
            dataBase->statement->execute("INSERT INTO Persona values('"+cliente.cedula+"','"+cliente.nombre+"','"+cliente.apellido+"','"+cliente.direccion+"','"+cliente.telefono+"')");
        }
        dataBase->statement->execute("INSERT INTO Cliente values('"+cliente.cedula+"')");
    }catch(...){
        throw "No se puedo ingresar el cliente";
    }
    return cliente;
}

Cliente ClienteDAO::mod(Cliente &cliente)
{
    try{
        std::string consul= "UPDATE Persona SET nombre='"+cliente.nombre+"',apellido = '"+cliente.apellido+"', direccion = '"+
                cliente.direccion+"', telefono = '"+cliente.telefono+"' WHERE cedula='"+cliente.cedula+"'";
        dataBase->statement->execute(consul);
    }catch(...){
        throw "No se puede modificar";
    }

    return cliente;
}

void ClienteDAO::del(std::string cedula)
{
    try{
        dataBase->statement->execute("DELETE FROM Cliente where idCliente='"+cedula+"'");
    }catch(...){
        throw "No se puede eliminar";
    }
}


Cliente ClienteDAO::get(std::string cedula)
{
    Cliente cliente;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("select * from Polideportivo.Persona P, Polideportivo.Cliente C where P.cedula = C.idCliente");
        //dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Cliente where idCliente='"+cedula+"'");
        //dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona where idCliente='"+cedula+"'");
        while(dataBase->resultset->next()){
            cliente.cedula = dataBase->resultset->getString(0);
            cliente.nombre = dataBase->resultset->getString(1);
            cliente.apellido= dataBase->resultset->getString(2);
            cliente.direccion= dataBase->resultset->getString(3);
            cliente.telefono= dataBase->resultset->getString(4);
        }
    }catch(...){
        throw "No se puede extraer el cliente";
    }

    return cliente;
}

std::vector<Cliente> ClienteDAO::get()
{
    std::vector<Cliente> clientes;
    Cliente cliente;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Persona P, Cliente C where P.cedula=C.idCliente");
        while(dataBase->resultset->next()){
            cliente.cedula = dataBase->resultset->getString(0);
            cliente.nombre = dataBase->resultset->getString(1);
            cliente.apellido = dataBase->resultset->getString(2);
            cliente.direccion = dataBase->resultset->getString(3);
            cliente.telefono = dataBase->resultset->getString(4);
            clientes.push_back(cliente);
        }
    }catch(...){
        throw "No se puede extraer la lista";
    }

    return clientes;
}
