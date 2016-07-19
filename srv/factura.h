#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include <vector>
#include <ctime>
#include "cliente.h"
#include "espacio.h"
class Detalle
{
public:
    int numDetalle;
    int cantidad;
    std::string descripcion;
    double precio;
};

class Factura
{
public:
    int numFactura;
    Cliente cliente;
    time_t fechaEmision;
    Espacio espacio;
    //std::vector<Detalle> descripcion;
    double subTotal;
    double abono;
    double total;
    int horas;

    Factura();
    Factura(Cliente cliente, Espacio &espacio, int horas, double abono);
    ~Factura(){};
};

#endif // FACTURA_H
