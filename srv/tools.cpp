#include <regex>

#include "tools.h"



void validarCedula(std::string cedula)
{
    std::regex cedulaRegex("\\d{10}");
    if (!std::regex_match(cedula, cedulaRegex))
        throw "Cédula no válida";
}

void validarTelefono(std::string telefono)
{
    std::regex telefonoRegex("\\d{10}");
    if (!std::regex_match(telefono, telefonoRegex))
        throw "Teléfono no válido";
}

void validarString(std::string str)
{
    if (str == "")
        throw "Cadena vacía";
}

void validarNumero(double num)
{
    if (num < 0)
        throw "Número negativo.";
}
