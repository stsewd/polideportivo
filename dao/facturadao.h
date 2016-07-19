#ifndef FACTURADAO_H
#define FACTURADAO_H

#include <string>
#include <ctime>
#include <vector>

#include "../srv/factura.h"
#include "conexiondb.h"

class facturadao
{
public:
    facturadao();
    ConexionDB *dataBase;
    Factura add(Factura factura);
    void del(std::string cedula, time_t fechaEmision);
    Factura get(std::string cedula, time_t fechaEmision);
    Factura agregarAbono(std::string cedula, time_t fechaEmision, double abono);
    Factura get(std::string cedula);

};

#endif // FACTURADAO_H
