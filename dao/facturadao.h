#ifndef FACTURADAO_H
#define FACTURADAO_H

#include <string>
#include <ctime>
#include <vector>

#include "../srv/factura.h"
#include "conexiondb.h"
#include "../srv/tools.h"
#include "clientedao.h"

class facturadao
{
public:
    facturadao();
    ~facturadao();
    ConexionDB *dataBase;
    ConexionDB *dataBase1;
    ClienteDAO  clientedao;
    Factura add(Factura factura);
    void del(int numFactura, std::string cedula);
    Factura get(int numFactura, std::string cedula);
    Factura agregarAbono(int numFactura, std::string cedula, double abono);
    std::vector<Factura> get(std::string cedula);
    std::vector<Factura> get();

};

#endif // FACTURADAO_H
