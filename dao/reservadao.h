#ifndef RESERVADAO_H
#define RESERVADAO_H

#include <string>
#include <vector>
#include <ctime>

#include "../srv/reserva.h"
#include "conexiondb.h"
#include "../srv/tools.h"
#include "clientedao.h"
#include "../srv/cliente.h"
#include "../srv/espacio.h"
#include "espaciocomplementariodao.h"
#include "espaciodeportivodao.h"

class reservadao
{
public:
    reservadao();
    ConexionDB *dataBase;
    Reserva add(Reserva reserva);
    Reserva mod(Reserva reserva);
    void del(std::string cedula, std::string nombreEspacio, time_t fechaReservacion);
    std::vector<Reserva> get(std::string cedulaCliente);  //saca todas las reservas de un cliente especifico
    std::vector<Reserva> get(time_t fecha);             //saca las reservas de un dia o de un dia
    std::vector<Reserva> get(std::string cedulaCliente, time_t fecha);  //saca la reserva de un cliete de un dia especifico
    std::vector<Reserva> get(time_t fechaInicial, time_t fechaFinal);  //saca todas las reservas en la fecha indicada
    std::vector<Reserva> get(std::string cedulaCliente, time_t fechaInicial, time_t fechaFinal);  //saca las reservas de un cliente en unas fecha idicada
    std::vector<Reserva> get(); //saca todas las reservas
};

#endif // RESERVADAO_H
