#ifndef FACTURASRV_H
#define FACTURASRV_H

#include <string>
#include <ctime>
#include <vector>

#include "../dao/facturadao.h"
#include "factura.h"
#include "cliente.h"
#include "espacio.h"

#include "../dao/clientedao.h"
#include "../dao/espaciocomplementariodao.h"
#include "../dao/espaciodeportivodao.h"

class facturasrv
{
public:
    facturadao dataBaseFactura;
    ClienteDAO dataBaseCliente;
    EspacioComplementarioDAO dataBaseEC;
    EspacioDeportivoDAO dataBaseED;
    facturasrv();
    /*
     * int numFactura;
    Cliente cliente;
    time_t fechaEmision;
    std::vector<Detalle> descripcion;
    double subTotal;
    double abono;
    double total;
     /*/
    Factura add(std::string cedulaCliente, std::string nombreEspacio, int cantidad, double abono);
    Factura facturar(int numFactura);
    void del(int numFactura);
    Factura get(int numFactura);
    Factura agregarAbono(int numFactura, double abono);
    std::vector<Factura> get(std::string cedula);
    std::vector<Factura> get();


};

#endif // FACTURASRV_H
