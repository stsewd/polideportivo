#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include <vector>
#include <ctime>
#include "cliente.h"

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
    std::vector<Detalle> descripcion;
    double subTotal;
    double abono;
    double total;

    Factura();
    Factura(Cliente cliente,std::vector<Detalle> descripcion);
    ~Factura();


};

#endif // FACTURA_H
