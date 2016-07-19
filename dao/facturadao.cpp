#include "facturadao.h"

facturadao::facturadao()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

Factura facturadao::add(Factura factura)
{

}

void facturadao::del(std::__cxx11::string cedula, time_t fechaEmision)
{

}

Factura facturadao::get(std::__cxx11::string cedula, time_t fechaEmision)
{

}

Factura facturadao::agregarAbono(std::__cxx11::string cedula, time_t fechaEmision, double abono)
{

}

Factura facturadao::get(std::__cxx11::string cedula)
{

}

