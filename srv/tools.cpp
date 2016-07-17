#include <regex>

#include "tools.h"



void validarCedula(std::string cedula)
{
    std::regex cedulaRegex("\\d{10}");
    if (!std::regex_match(cedula, cedulaRegex))
        throw "Cédula no válida";
}
