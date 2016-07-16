#ifndef ESPACIOCOMPLEMENTARIOSRV_H
#define ESPACIOCOMPLEMENTARIOSRV_H

#include <string>
#include <vector>

#include "espaciocomplementario.h"
#include "../dao/espaciocomplementariodao.h"

class EspacioComplementarioSrv
{
public:

    EspacioComplementarioDAO dataBase;

    EspacioComplementarioSrv();

    EspacioComplementario add(std::string nombre, std::string descripcion, double precioPorHora,
                              int capacidad, std::string estado, Horario horario, std::string tipoEspacio
    );

    EspacioComplementario mod(std::string nombre, std::string descripcion, double precioPorHora,
                              int capacidad, std::string estado, Horario horario, std::string tipoEspacio
    );

    void del(std::string nombre);

    EspacioComplementario get(std::string nombre);

    std::vector<EspacioComplementario> get();
private:
    TipoEspacioComplementario getTipo(std::string tipoEspacio);
    Estado getEstado(std::string estadoEspacio);
};

#endif // ESPACIOCOMPLEMENTARIOSRV_H
