#ifndef RESERVA_H
#define RESERVA_H

#include <ctime>

#include "cliente.h"
#include "espacio.h"

class Reserva {
    Cliente* cliente;
    Espacio* espacio;
    time_t fechaReservacion;
    time_t fechaReserva;
public:
    Reserva();
};

#endif // RESERVA_H
