#include "factura.h"

factura::Factura()
{

}


Factura::Factura(Cliente cliente, std::vector<Detalle> descripcion)
{
    this->cliente=cliente;
    this->descripcion=descripcion;
    this->fechaEmision=time(&NULL);
    this->abono=0;
    this->subTotal=0;
    this->total=0;

}
