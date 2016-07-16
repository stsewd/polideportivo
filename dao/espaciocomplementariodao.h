#ifndef ESPACIOCOMPLEMENTARIODAO_H
#define ESPACIOCOMPLEMENTARIODAO_H

#include <string>
#include <vector>

#include "../srv/espaciocomplementario.h"

class EspacioComplementarioDAO
{
public:
    EspacioComplementarioDAO();

    EspacioComplementario add(EspacioComplementario& espacio);
    EspacioComplementario mod(EspacioComplementario& espacio);
    void del(std::string nombre);
    EspacioComplementario get(std::string nombre);
    std::vector<EspacioComplementario> get();
};

#endif // ESPACIOCOMPLEMENTARIODAO_H
