#ifndef FACTURADAO_H
#define FACTURADAO_H

#include <string>
#include <ctime>
#include <vector>

#include "../srv/factura.h"
#include "conexiondb.h"
#include "../srv/tools.h"
#include "clientedao.h"
#include "../srv/tools.h"

class facturadao
{
public:
    facturadao();
    ~facturadao();
    ConexionDB *dataBase;
    ClienteDAO  clientedao;
    Factura add(Factura factura);
    void del(int numFactura);
    Factura get(int numFactura);
    Factura agregarAbono(int numFactura, double abono);
    std::vector<Factura> get(std::string cedula);
    std::vector<Factura> get();

};

#endif // FACTURADAO_H
