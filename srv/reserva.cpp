#include "reserva.h"

Reserva::Reserva()
{

}

Reserva::Reserva(Cliente& cliente, Espacio& espacio, time_t fechaReservacion)
{
    this->cliente = cliente;
    this->espacio = espacio;
    this->fechaReservacion = fechaReservacion;
    this->fechaReserva = time(nullptr);
}

Reserva::~Reserva()
{

}
