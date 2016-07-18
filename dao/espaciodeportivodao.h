#ifndef ESPACIODEPORTIVODAO_H
#define ESPACIODEPORTIVODAO_H

#include <string>
#include <vector>

#include "../srv/espaciodeportivo.h"
#include "conexiondb.h"
#include "herramientas.h"

class EspacioDeportivoDAO {
public:
    EspacioDeportivoDAO();
    ConexionDB* dataBase;
    EspacioDeportivo add(EspacioDeportivo& espacio);
    EspacioDeportivo mod(EspacioDeportivo& espacio);
    void del(std::string nombre);
    EspacioDeportivo get(std::string nombre);
    std::vector<EspacioDeportivo> get();
    void modTipo(std::string nombre, std::string tipo);
};

#endif // ESPACIODEPORTIVODAO_H
