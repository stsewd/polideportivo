#include "reserva.h"

Reserva::Reserva()
{

}

Reserva::Reserva(Cliente& cliente, Espacio& espacio, time_t fechaReservacion, time_t fechaFinReservacion)
{
    this->cliente = &cliente;
    this->espacio = &espacio;
    this->fechaReservacion = fechaReservacion;
    this->fechaFinReservacion = fechaFinReservacion;
    this->fechaReserva = time(nullptr);
}

Reserva::~Reserva()
{

}
