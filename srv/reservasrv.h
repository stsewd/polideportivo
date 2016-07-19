#ifndef RESERVASRV_H
#define RESERVASRV_H

#include "../dao/reservadao.h"

class ReservaSrv
{
public:
    ReservaSrv();

    reservadao dataBase;

    Reserva add(std::string cedulaCliente, std::string nombreEspacio, time_t fechaReservacion, time_t fechaFinReservacion);
    Reserva mod(std::string cedulaCliente, std::string nombreEspacio, time_t fechaReservacion, time_t fechaFinReservacion,
                std::string nuevoEspacio, time_t nuevaFechaReservacion, time_t nuevaFechaFinReservacion
    );

    void del(std::string cedula, std::string nombreEspacio, time_t fechaReservacion, time_t fechaFinReservacion);
    Reserva get(std::string cedula, std::string nombreEspacio, time_t fechaReservacion, time_t fechaFinReservacion);
    std::vector<Reserva> get(std::string cedulaCliente);
    std::vector<Reserva> get(time_t fecha);
    std::vector<Reserva> get(std::string cedulaCliente, time_t fecha);
    std::vector<Reserva> get(time_t fechaInicial, time_t fechaFinal);
    std::vector<Reserva> get(std::string cedulaCliente, time_t fechaInicial, time_t fechaFinal);
    std::vector<Reserva> get();

private:
    Espacio* getEspacio(std::string nombreEspacio);
};

#endif // RESERVASRV_H
