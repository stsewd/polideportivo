#include "facturadao.h"

facturadao::facturadao()
{
    dataBase = new ConexionDB("localhost:3306","root","1234","Polideportivo");
}

facturadao::~facturadao()
{

}

Factura facturadao::add(Factura factura)
{
    try{
        dataBase->statement->execute("INSERT INTO Factura values('" + std::to_string(factura.numFactura) + "', '" +
                                     factura.cliente.cedula + "', '" +  getFecha(&(factura.fechaEmision)) + "', '" +
                                     std::to_string(factura.abono) + "', '" + std::to_string(factura.total) + "', '"+
                                     std::string(factura.espacio.nombre)+"')"
                                     );
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return factura;
}

void facturadao::del(int numFactura)
{
    try{
        dataBase->statement->execute("DELETE FROM Factura where idFactura='" + std::to_string(numFactura) + "'"
                                     );

    }catch(...){
        throw std::string("No se puede eliminar la factura");
    }
}

Factura facturadao::get(int numFactura)
{
    Factura factura;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Factura where idFactura='"+std::to_string(numFactura)+"'");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(2));
            Espacio espacio  = *(getEspacio(dataBase->resultset->getString(6)));
            factura.cliente = cliente;
            factura.espacio= espacio;
            factura.fechaEmision = getFechaString(dataBase->resultset->getString(3));
            factura.abono = std::atof(dataBase->resultset->getString(4).c_str());
            factura.total = std::atof(dataBase->resultset->getString(5).c_str());
            factura.subTotal = factura.total - factura.abono;
        }
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return factura;

}

Factura facturadao::agregarAbono(int numFactura, double abono)
{
    Factura factura;
    try{
        factura = get(numFactura);
        double total = factura.total-abono;
        dataBase->statement->execute("UPDATE Factura SET abono='" + std::to_string(factura.abono+abono) + "', subTotal='"+std::to_string(total)+"' where idFactura='"+
                                 std::to_string(factura.numFactura) + "'");
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return factura;
}

std::vector<Factura> facturadao::get(std::string cedula)
{
    Factura factura;
    std::vector<Factura> facturas;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Factura where idCliente='"+cedula+"'");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(2));
            Espacio espacio  = *(getEspacio(dataBase->resultset->getString(6)));
            factura.cliente = cliente;
            factura.espacio = espacio;
            factura.fechaEmision = getFechaString(dataBase->resultset->getString(3));
            factura.abono = std::atof(dataBase->resultset->getString(4).c_str());
            factura.total = std::atof(dataBase->resultset->getString(5).c_str());
            factura.subTotal = factura.total - factura.abono;
            facturas.push_back(factura);
        }
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return facturas;
}

std::vector<Factura> facturadao::get()
{
    Factura factura;
    std::vector<Factura> facturas;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Factura ");
        while(dataBase->resultset->next()){
            Cliente cliente = clientedao.get(dataBase->resultset->getString(2));
            Espacio espacio  = *(getEspacio(dataBase->resultset->getString(6)));
            factura.cliente = cliente;
            factura.espacio= espacio;
            factura.fechaEmision = getFechaString(dataBase->resultset->getString(3));
            factura.abono = std::atof(dataBase->resultset->getString(4).c_str());
            factura.total = std::atof(dataBase->resultset->getString(5).c_str());
            factura.subTotal = factura.total - factura.abono;
            facturas.push_back(factura);
        }
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return facturas;
}




