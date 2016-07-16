#ifndef ESPACIODEPORTIVOSRV_H
#define ESPACIODEPORTIVOSRV_H

#include <string>
#include <vector>

#include "espaciodeportivo.h"
#include "../dao/espaciodeportivodao.h"

class EspacioDeportivoSrv
{
public:
    EspacioDeportivoDAO dataBase;

    EspacioDeportivoSrv();
    EspacioDeportivo add(std::string nombre, std::string descripcion, double precioPorHora,
                         int capacidad, std::string estado, Horario horario, std::string tipoEspacio
    );

    EspacioDeportivo mod(std::string nombre, std::string descripcion, double precioPorHora,
                         int capacidad, std::string estado, Horario horario, std::string tipoEspacio
    );

    void del(std::string nombre);

    EspacioDeportivo get(std::string nombre);

    std::vector<EspacioDeportivo> get();

 private:
    TipoEspacioDeportivo getTipo(std::string tipoEspacio);
    Estado getEstado(std::string estadoEspacio);
};

#endif // ESPACIODEPORTIVOSRV_H
