#ifndef RESERVA_H
#define RESERVA_H

#include <ctime>

#include "cliente.h"
#include "espacio.h"

class Reserva {
public:
    Cliente* cliente;
    Espacio* espacio;
    time_t fechaReservacion;
    time_t fechaReserva;
    time_t fechaFinReservacion;
public:
    Reserva();
    Reserva(Cliente& cliente, Espacio& espacio, time_t fechaReservacion, time_t fechaFinReservacion);
    ~Reserva();
};

#endif // RESERVA_H
