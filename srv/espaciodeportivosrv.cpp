#include "espaciodeportivosrv.h"
#include "espaciodeportivo.h"

EspacioDeportivoSrv::EspacioDeportivoSrv()
{

}

EspacioDeportivo EspacioDeportivoSrv::add(std::string nombre, std::string descripcion,
                                          double precioPorHora, int capacidad, std::string estadoEspacio,
                                          Horario horario, std::string tipoEspacio
                                        )
{
    validarVacio(nombre);
    validarVacio(descripcion);
    validarNumero(precioPorHora);
    validarNumero(capacidad);

    TipoEspacioDeportivo tipo = getTipo(tipoEspacio);
    Estado estado = getEstado(estadoEspacio);

    EspacioDeportivo espacio(nombre, descripcion, precioPorHora, capacidad, estado, horario, tipo);

    dataBase.add(espacio);

    return espacio;
}

EspacioDeportivo EspacioDeportivoSrv::mod(std::string nombre, std::string descripcion,
                                          double precioPorHora, int capacidad, std::string estadoEspacio,
                                          Horario horario, std::string tipoEspacio
                                        )
{
    validarVacio(nombre);
    validarVacio(descripcion);
    validarNumero(precioPorHora);
    validarNumero(capacidad);

    EspacioDeportivo espacio = get(nombre);

    auto tipo = getTipo(tipoEspacio);
    auto estado = getEstado(estadoEspacio);

    espacio.capacidad = capacidad;
    espacio.descripcion = descripcion;
    espacio.estado = estado;
    espacio.horario = horario;
    espacio.precioPorhora = precioPorHora;
    espacio.tipo = tipo;

    dataBase.mod(espacio);
    return espacio;
}

void EspacioDeportivoSrv::del(std::string nombre)
{
    dataBase.del(nombre);
}

EspacioDeportivo EspacioDeportivoSrv::get(std::string nombre)
{
    return dataBase.get(nombre);
}

std::vector<EspacioDeportivo> EspacioDeportivoSrv::get()
{
    return dataBase.get();
}

TipoEspacioDeportivo EspacioDeportivoSrv::getTipo(std::string tipoEspacio)
{
    TipoEspacioDeportivo tipo(tipoEspacio);
    return tipo;
}

Estado EspacioDeportivoSrv::getEstado(std::string estadoEspacio)
{
    if (estadoEspacio == "libre")
        return Estado::libre;
    else if (estadoEspacio == "ocupado")
        return Estado::ocupado;
    else if (estadoEspacio == "reservado")
        return Estado::reservado;
    else if (estadoEspacio == "mantenimiento")
        return Estado::mantenimiento;
    else
        throw "Estado no válido";
}
