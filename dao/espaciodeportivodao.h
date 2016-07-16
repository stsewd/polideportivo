#ifndef ESPACIODEPORTIVODAO_H
#define ESPACIODEPORTIVODAO_H

#include <string>
#include <vector>

#include "../srv/espaciodeportivo.h"

class EspacioDeportivoDAO {
public:
    EspacioDeportivoDAO();

    EspacioDeportivo add(EspacioDeportivo& espacio);
    EspacioDeportivo mod(EspacioDeportivo& espacio);
    void del(std::string nombre);
    EspacioDeportivo get(std::string nombre);
    std::vector<EspacioDeportivo> get();
};

#endif // ESPACIODEPORTIVODAO_H
