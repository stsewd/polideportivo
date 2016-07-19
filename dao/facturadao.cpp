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
                                     std::to_string(factura.abono) + "', '" + std::to_string(factura.total) + "')"
                                     );
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return factura;
}

void facturadao::del(int numFactura, std::string cedula)
{
    try{
        dataBase->statement->execute("DELETE FROM Factura where idFactura='" + std::to_string(numFactura) + "', and idCliente='"+
                                     cedula + "'"
                                     );

    }catch(...){
        throw std::string("No se puede eliminar la factura");
    }
}

Factura facturadao::get(int numFactura, std::string cedula)
{
    Factura factura;
    std::vector<Detalle> productos;
    Detalle detalle;
    try{
        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Detalle where idFactura='" + std::to_string(numFactura) + "'");
        while(dataBase->resultset->next()){
            detalle.numDetalle = std::atoi(dataBase->resultset->getString(1).c_str());
            detalle.descripcion = dataBase->resultset->getString(3);
            detalle.cantidad = std::atoi(dataBase->resultset->getString(4).c_str());
            detalle.precio = std::atof(dataBase->resultset->getString(5).c_str());
            productos.push_back(detalle);
        }
        Cliente cliente = clientedao.get(cedula);
        factura.cliente = cliente;

        dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Factura where idCliente='"+cedula+"'");
        factura.fechaEmision = getFechaString(dataBase->resultset->getString(3));
        factura.abono = std::atof(dataBase->resultset->getString(4).c_str());
        factura.total = std::atof(dataBase->resultset->getString(5).c_str());
        factura.subTotal = factura.total - factura.abono;
        factura.descripcion = productos;
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return factura;

}

Factura facturadao::agregarAbono(int numFactura, std::string cedula, double abono)
{
    Factura factura;
    try{
    factura = get(numFactura, cedula);
    dataBase->statement->execute("UPDATE Factura SET abono='" + std::to_string(factura.abono+abono) + "', where idFactura='"+
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
    std::vector<Detalle> productos;
    Detalle detalle;
    try{
        dataBase1->resultset = dataBase1->statement->executeQuery("SELECT * FROM Factura where='"+cedula+"'");
        while(dataBase1->resultset->next()){
            dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Detalle where idFactura='" + dataBase->resultset->getString(1) + "'");
            while(dataBase->resultset->next()){
                detalle.numDetalle = std::stoi(dataBase->resultset->getString(1).c_str());
                detalle.descripcion = dataBase->resultset->getString(3);
                detalle.cantidad = std::atoi(dataBase->resultset->getString(4).c_str());
                detalle.precio = std::atof(dataBase->resultset->getString(5).c_str());
                productos.push_back(detalle);
            }
            factura.numFactura = std::atoi(dataBase->resultset->getString(1).c_str());
            Cliente cliente = clientedao.get(dataBase1->resultset->getString(2));
            factura.cliente = cliente;
            factura.fechaEmision = getFechaString(dataBase->resultset->getString(3));
            factura.abono = std::atof(dataBase->resultset->getString(4).c_str());
            factura.total = std::atof(dataBase->resultset->getString(5).c_str());
            factura.subTotal = factura.total - factura.abono;
            factura.descripcion = productos;
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
    std::vector<Detalle> productos;
    Detalle detalle;
    try{
        dataBase1->resultset = dataBase1->statement->executeQuery("SELECT * FROM Factura");
        while(dataBase1->resultset->next()){
            dataBase->resultset = dataBase->statement->executeQuery("SELECT * FROM Detalle where idFactura='" + dataBase->resultset->getString(1) + "'");
            while(dataBase->resultset->next()){
                detalle.numDetalle = std::stoi(dataBase->resultset->getString(1).c_str());
                detalle.descripcion = dataBase->resultset->getString(3);
                detalle.cantidad = std::atoi(dataBase->resultset->getString(4).c_str());
                detalle.precio = std::atof(dataBase->resultset->getString(5).c_str());
                productos.push_back(detalle);
            }
            factura.numFactura = std::atoi(dataBase->resultset->getString(1).c_str());
            Cliente cliente = clientedao.get(dataBase1->resultset->getString(2));
            factura.cliente = cliente;
            factura.fechaEmision = getFechaString(dataBase->resultset->getString(3));
            factura.abono = std::atof(dataBase->resultset->getString(4).c_str());
            factura.total = std::atof(dataBase->resultset->getString(5).c_str());
            factura.subTotal = factura.total - factura.abono;
            factura.descripcion = productos;
            facturas.push_back(factura);
        }
    }catch(...){
        throw std::string("Error al ingresar la factura");
    }
    return facturas;
}




