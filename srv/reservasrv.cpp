#include "reservasrv.h"
#include "tools.h"

Reserva ReservaSrv::add(std::string cedulaCliente, std::string nombreEspacio, time_t fechaReservacion, time_t fechaFinReservacion)
{
    validarCedula(cedulaCliente);
    validarString(nombreEspacio);
    validarFechas(fechaReservacion, fechaFinReservacion);

    ClienteDAO clienteDAO;

    Cliente cliente = clienteDAO.get(cedulaCliente);
    Espacio* espacio = getEspacio(nombreEspacio);

    Reserva reserva(cliente, *espacio, fechaReservacion, fechaFinReservacion);
    dataBase.add(reserva);

    return reserva;
}

Reserva ReservaSrv::mod(std::string cedulaCliente, std::string nombreEspacio, time_t fechaReservacion,
                        time_t fechaFinReservacion, std::string nuevoEspacio, time_t nuevaFechaReservacion,
                        time_t nuevaFechaFinReservacion
                    )
{
    validarCedula(cedulaCliente);
    validarString(nuevoEspacio);
    validarFechas(nuevaFechaReservacion, nuevaFechaFinReservacion);
    Reserva reserva = get(cedulaCliente, nombreEspacio, fechaReservacion, fechaFinReservacion);


    reserva.fechaReservacion = nuevaFechaReservacion;
    reserva.fechaFinReservacion = nuevaFechaFinReservacion;
    reserva.espacio = getEspacio(nuevoEspacio);

    dataBase.del(cedulaCliente, nombreEspacio, fechaReservacion, fechaFinReservacion);

    dataBase.add(reserva);

    return reserva;
}

void ReservaSrv::del(std::string cedula, std::string nombreEspacio, time_t fechaReservacion, time_t fechaFinReservacion)
{
    dataBase.del(cedulaCliente, nombreEspacio, fechaReservacion, fechaFinReservacion);
}

std::vector<Reserva> ReservaSrv::get(std::string cedulaCliente)
{
    return dataBase.get(cedulaCliente);
}

std::vector<Reserva> ReservaSrv::get(time_t fecha)
{
    return get(fecha);
}

std::vector<Reserva> ReservaSrv::get(std::string cedulaCliente, time_t fecha)
{
    return get(cedulaCliente, fecha);
}

std::vector<Reserva> ReservaSrv::get(time_t fechaInicial, time_t fechaFinal)
{
    return get(fechaInicial, fechaFinal);
}

std::vector<Reserva> ReservaSrv::get(std::string cedulaCliente, time_t fechaInicial, time_t fechaFinal)
{
    return get(cedulaCliente, fechaInicial, fechaFinal);
}

std::vector<Reserva> ReservaSrv::get()
{
    return get();
}

Espacio *ReservaSrv::getEspacio(std::string nombreEspacio)
{
    Espacio* espacio;
    EspacioComplementarioDAO espacioComplementarioDAO;
    EspacioDeportivoDAO espacioDeportivoDAO;

    try {
        EspacioComplementario e = espacioComplementarioDAO.get(nombreEspacio);
        espacio = new EspacioComplementario(e.nombre, e.descripcion, e.precioPorhora, e.capacidad, e.estado, e.horario, e.tipo);
    } catch (...) {
        try {
            EspacioDeportivo e = espacioDeportivoDAO.get(nombreEspacio);
            espacio = new EspacioDeportivo(e.nombre, e.descripcion, e.precioPorhora, e.capacidad, e.estado, e.horario, e.tipo);
        } catch (...) {
            throw "Espacio no encontrado.";
        }
    }
    return espacio;
}
