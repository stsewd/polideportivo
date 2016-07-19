#include "reservadao.h"

reservadao::reservadao()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
    espacioComplementariodao = new EspacioComplementarioDAO();
    espacioDeportivodao = new EspacioDeportivoDAO();
    clientedao = new ClienteDAO();
}

Reserva reservadao::add(Reserva reserva)
{
    try{
        dataBase->statement->execute("INSERT INTO Reserva values('" + reserva.cliente->cedula + "', '" +
                                     reserva.espacio->nombre + "', ' " + getFecha(&(reserva.fechaReservacion)) +"', '"+
                                     getFecha(&(reserva.fechaReserva))+")");
    }catch(...){
        throw "No se puede agregar la reserva";
    }
}

Reserva reservadao::mod(Reserva reserva)
{

}

void reservadao::del(std::string cedula, std::string nombreEspacio, time_t fechaReservacion)
{
    try{
        dataBase->statement->execute("DELETE FROM Reserva where idCliente='" + cedula +"' and idEspacio='"+
                                     nombreEspacio + "' and fechaReservacion='" + getFecha(&(fechaReservacion)) + "')");
    }catch(...){
        throw  "No se pudo eliminar";
    }
}

std::vector<Reserva> reservadao::get(std::string cedulaCliente)
{
    //sacar la reserva
    //sacar el cliente
    //sacar el espacio
    //llenar el objeto reserva
    //incluir a un vector de reservas
    Reserva reserva;
    Espacio espacio;
    std::vector<Reserva> reservas;
    try{
        ClienteDAO clienteDAO;
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Polideportivo.Reserva where idCliente='" + cedulaCliente+ "'");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            if(espacioDeportivo != NULL){
                espacio = (espacio) espacioDeportivo;
            }else{
                EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                espacio = (espacio) espacioComplementario;
            }
             //como se puede obtener los espacios sin saber que tipo es//
            Cliente cliente = clienteDAO.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
            Espacio espacio; //como se puede obtener los espacios sin saber que tipo es//
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw "No se encuentra";
    }
    return reservas;
}

std::vector<Reserva> reservadao::get(time_t fecha)
{
    ClienteDAO clienteDAO;
    Reserva reserva;
    Espacio espacio;
    std::vector<Reserva> reservas;
    time_t aux = fecha+3600*24;
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Reserva WHERE ('" + getFecha(&fecha) +
                                                              "' <= fechaReservacion AND fechaReservacion <= '"+getFecha(&aux)+"')");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
             //como se puede obtener los espacios sin saber que tipo es//
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            if(espacioDeportivo != NULL){
                espacio = (espacio) espacioDeportivo;
            }else{
                EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                espacio = (espacio) espacioComplementario;
            }
            Cliente cliente = clienteDAO.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
            Espacio espacio; //como se puede obtener los espacios sin saber que tipo es//
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw "No se encuentra";
    }
    return reservas;
}

std::vector<Reserva> reservadao::get(std::string cedulaCliente, time_t fecha)
{
    ClienteDAO clienteDAO;
    Reserva reserva;
    Espacio espacio;
    std::vector<Reserva> reservas;
    time_t aux = fecha+3600*24;
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Reserva WHERE ('" + getFecha(&fecha) +
                                                              "' <= fechaReservacion AND fechaReservacion <= '"+getFecha(&aux)+"') and idCliente='"+cedulaCliente+"'");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
             //como se puede obtener los espacios sin saber que tipo es//
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            if(espacioDeportivo != NULL){
                espacio = (espacio) espacioDeportivo;
            }else{
                EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                espacio = (espacio) espacioComplementario;
            }
            Cliente cliente = clienteDAO.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
            Espacio espacio; //como se puede obtener los espacios sin saber que tipo es//
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw "No se encuentra";
    }
    return reservas;
}

std::vector<Reserva> reservadao::get(time_t fechaInicial, time_t fechaFinal)
{
    ClienteDAO clienteDAO;
    Reserva reserva;
    Espacio espacio;
    std::vector<Reserva> reservas;
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Reserva WHERE ('" + getFecha(&fechaInicial) +
                                                              "' <= fechaReservacion AND fechaReservacion <= '"+getFecha(&fechaFinal)+"')");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
             //como se puede obtener los espacios sin saber que tipo es//
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            if(espacioDeportivo != NULL){
                espacio = (espacio) espacioDeportivo;
            }else{
                EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                espacio = (espacio) espacioComplementario;
            }
            reserva.cliente = cliente;
            reserva.espacio = espacio;
            Cliente cliente = clienteDAO.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
            Espacio espacio; //como se puede obtener los espacios sin saber que tipo es//
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw "No se encuentra";
    }
    return reservas;
}

std::vector<Reserva> reservadao::get(std::string cedulaCliente, time_t fechaInicial, time_t fechaFinal)
{
    ClienteDAO clienteDAO;
    Reserva reserva;
    Espacio espacio;
    std::vector<Reserva> reservas;
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Reserva WHERE ('" + getFecha(&fechaInicial) +
                                                              "' <= fechaReservacion AND fechaReservacion <= '"+getFecha(&fechaFinal)+"') and idCliente='"+cedulaCliente+"'");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
             //como se puede obtener los espacios sin saber que tipo es//
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            if(espacioDeportivo != NULL){
                espacio = (espacio) espacioDeportivo;
            }else{
                EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                espacio = (espacio) espacioComplementario;
            }
            reserva.cliente = cliente;
            reserva.espacio = espacio;
            Cliente cliente = clienteDAO.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
            Espacio espacio; //como se puede obtener los espacios sin saber que tipo es//
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw "No se encuentra";
    }
    return reservas;
}

std::vector<Reserva> reservadao::get()
{
    ClienteDAO clienteDAO;
    Reserva reserva;
    Espacio espacio;
    std::vector<Reserva> reservas;
    try{
        dataBase->resultset=dataBase->statement->executeQuery("SELECT * FROM Reserva ");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
             //como se puede obtener los espacios sin saber que tipo es//
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            if(espacioDeportivo != NULL){
                espacio = (espacio) espacioDeportivo;
            }else{
                EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                espacio = (espacio) espacioComplementario;
            }
            reserva.cliente = cliente;
            reserva.espacio = espacio;
            Cliente cliente = clienteDAO.get(dataBase->resultset->getString(0)); //cliente puede salir de aca y ponerse una linea mas arriba
            Espacio espacio; //como se puede obtener los espacios sin saber que tipo es//
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw "No se encuentra";
    }
    return reservas;

}
