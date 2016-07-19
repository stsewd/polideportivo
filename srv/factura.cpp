#include "factura.h"

Factura::Factura()
{

}

Factura::Factura(Cliente cliente, Espacio& espacio, int horas, double abono)
{
    this->cliente=cliente;
    this->espacio=espacio;
    this->fechaEmision=time(NULL);
    this->horas=horas;
    this->abono=abono;
    this->subTotal=this->subTotal-abono;
    this->total=espacio.precioPorhora*horas;

}



