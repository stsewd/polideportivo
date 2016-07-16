#include "espaciocomplementariosrv.h"

EspacioComplementarioSrv::EspacioComplementarioSrv()
{

}

EspacioComplementario EspacioComplementarioSrv::add(std::string nombre, std::string descripcion,
                                                    double precioPorHora, int capacidad, std::string estadoEspacio,
                                                    Horario horario, std::string tipoEspacio
                                                )
{
    TipoEspacioComplementario tipo = getTipo(tipoEspacio);
    Estado estado = getEstado(estadoEspacio);

    EspacioComplementario espacio(nombre, descripcion, precioPorHora, capacidad, estado, horario, tipo);

    dataBase.add(espacio);

    return espacio;

}

EspacioComplementario EspacioComplementarioSrv::mod(std::string nombre, std::string descripcion,
                                                    double precioPorHora, int capacidad, std::string estadoEspacio,
                                                    Horario horario, std::string tipoEspacio)
{
    EspacioComplementario espacio = get(nombre);

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

void EspacioComplementarioSrv::del(std::string nombre)
{
    dataBase.del(nombre);
}

EspacioComplementario EspacioComplementarioSrv::get(std::string nombre)
{
    return dataBase.get(nombre);
}

std::vector<EspacioComplementario> EspacioComplementarioSrv::get()
{
    return dataBase.get();
}

TipoEspacioComplementario EspacioComplementarioSrv::getTipo(std::string tipoEspacio)
{
    TipoEspacioComplementario tipo(tipoEspacio);
    return tipo;
}

Estado EspacioComplementarioSrv::getEstado(std::string estadoEspacio)
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
