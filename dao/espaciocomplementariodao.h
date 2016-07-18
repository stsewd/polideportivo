#ifndef ESPACIOCOMPLEMENTARIODAO_H
#define ESPACIOCOMPLEMENTARIODAO_H

#include <string>
#include <vector>

#include "../srv/espaciocomplementario.h"
#include "conexiondb.h"
#include "herramientas.h"

class EspacioComplementarioDAO
{
public:
    EspacioComplementarioDAO();
    ConexionDB* dataBase;
    EspacioComplementario add(EspacioComplementario& espacio);
    EspacioComplementario mod(EspacioComplementario& espacio);
    void del(std::string nombre);
    EspacioComplementario get(std::string nombre);
    std::vector<EspacioComplementario> get();
    void modTipo(std::string nombre, std::string tipo);
};

#endif // ESPACIOCOMPLEMENTARIODAO_H
