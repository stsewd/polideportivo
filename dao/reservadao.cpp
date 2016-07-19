#include "reservadao.h"

reservadao::reservadao()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
    //espacioComplementariodao = new EspacioComplementarioDAO();
    //espacioDeportivodao = new EspacioComplementarioDAO();
    //clientedao = new ClienteDAO();
}

Reserva reservadao::add(Reserva reserva)
{
    try{
        dataBase->statement->execute("INSERT INTO Reserva values('" + reserva.cliente->cedula + "', '" +
                                     reserva.espacio->nombre + "', ' " + getFecha(&(reserva.fechaReservacion)) +"', '"+
                                     getFecha(&(reserva.fechaReserva))+ "', ' " + getFecha(&(reserva.fechaFinReservacion))+")");
    }catch(...){
        throw std::string("No se puede agregar la reserva");
    }
}

Reserva reservadao::mod(Reserva reserva)
{

}

void reservadao::del(std::string cedula, std::string nombreEspacio, time_t fechaReservacion, time_t fechafinReservacion)
{
    try{
        dataBase->statement->execute("DELETE FROM Reserva where idCliente='" + cedula +"' and idEspacio='"+
                                     nombreEspacio + "' and fechaReservacion='" + getFecha(&(fechaReservacion)) +
                                     "' and fechafinReservacion='"+getFecha(&(fechafinReservacion))+"')");
    }catch(...){
        throw  std::string("No se pudo eliminar");
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
            Cliente cliente = clientedao.get(dataBase->resultset->getString(0));
            try{
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            espacio = static_cast<Espacio> (espacioDeportivo);
            }catch(...){
                try{
                    EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                    espacio = static_cast<Espacio> (espacioComplementario);
                }catch(...){
                    throw std::string("No existe el espacio");
                }
            }
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reserva.fechaFinReservacion = getFechaString(dataBase->resultset->getString(4));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw std::string("No se encuentra");
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
            try{
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            espacio = static_cast<Espacio> (espacioDeportivo);
            }catch(...){
                try{
                    EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                    espacio = static_cast<Espacio> (espacioComplementario);
                }catch(...){
                    throw std::string("No existe el espacio");
                }
            }
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reserva.fechaFinReservacion = getFechaString(dataBase->resultset->getString(4));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw std::string("No se encuentra");
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
            try{
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            espacio = static_cast<Espacio> (espacioDeportivo);
            }catch(...){
                try{
                    EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                    espacio = static_cast<Espacio> (espacioComplementario);
                }catch(...){
                    throw std::string("No existe el espacio");
                }
            }
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reserva.fechaFinReservacion = getFechaString(dataBase->resultset->getString(4));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw std::string("No se encuentra");
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
            try{
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            espacio = static_cast<Espacio> (espacioDeportivo);
            }catch(...){
                try{
                    EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                    espacio = static_cast<Espacio> (espacioComplementario);
                }catch(...){
                    throw std::string("No existe el espacio");
                }
            }
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reserva.fechaFinReservacion = getFechaString(dataBase->resultset->getString(4));
            reservas.push_back(reserva);
            reservas.push_back(reserva);
        }
    }catch(...){
        throw std::string("No se encuentra");
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
            try{
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            espacio = static_cast<Espacio> (espacioDeportivo);
            }catch(...){
                try{
                    EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                    espacio = static_cast<Espacio> (espacioComplementario);
                }catch(...){
                    throw std::string("No existe el espacio");
                }
            }
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reserva.fechaFinReservacion = getFechaString(dataBase->resultset->getString(4));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw std::string("No se encuentra");
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
            try{
            EspacioDeportivo espacioDeportivo = espacioDeportivodao.get(dataBase->resultset->getString(1));
            espacio = static_cast<Espacio> (espacioDeportivo);
            }catch(...){
                try{
                    EspacioComplementario espacioComplementario = espacioComplementariodao.get(dataBase->resultset->getString(1));
                    espacio = static_cast<Espacio> (espacioComplementario);
                }catch(...){
                    throw std::string("No existe el espacio");
                }
            }
            reserva.cliente = &cliente;
            reserva.espacio = &espacio;
            reserva.fechaReservacion = getFechaString(dataBase->resultset->getString(2));
            reserva.fechaReserva = getFechaString(dataBase->resultset->getString(3));
            reserva.fechaFinReservacion = getFechaString(dataBase->resultset->getString(4));
            reservas.push_back(reserva);
        }
    }catch(...){
        throw std::string("No se encuentra");
    }
    return reservas;

}
