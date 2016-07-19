#include "facturasrv.h"
#include "tools.h"

facturasrv::facturasrv()
{


}

Factura facturasrv::add(std::string cedulaCliente, std::string nombreEspacio, int cantidad, double abono)
{
  validarCedula(cedulaCliente);
  validarString(nombreEspacio);
  validarNumero(cantidad);
  validarNumero(abono);

  Cliente cliente = dataBaseCliente.get(cedulaCliente);
  Espacio espacio = *(getEspacio(nombreEspacio));
  Factura factura(cliente, espacio, cantidad, abono);
  dataBaseFactura.add(factura);
  return factura;
}

Factura facturasrv::facturar(int numFactura)
{
    //validarNumero(numFactura);

    return dataBaseFactura.get(numFactura);
}

void facturasrv::del(int numFactura)
{
    //validarNumero(numFactura);

    dataBaseFactura.del(numFactura);
}

Factura facturasrv::get(int numFactura)
{
    //validarNumero(numFactura);

    return dataBaseFactura.get(numFactura);
}

Factura facturasrv::agregarAbono(int numFactura, double abono)
{
    validarNumero(abono);
    Factura factura = dataBaseFactura.get(numFactura);
    double com = factura.subTotal+abono;
    if(com>factura.total){
        throw std::string("La cantidad que va abonar sobrepasa la deuda");
    }
    return dataBaseFactura.agregarAbono(numFactura, abono);
}

std::vector<Factura> facturasrv::get(std::string cedula)
{
    validarCedula(cedula);

    return dataBaseFactura.get(cedula);
}

std::vector<Factura> facturasrv::get()
{
    return dataBaseFactura.get();
}










