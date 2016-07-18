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

std::string estadoToString(Estado estado)
{
    if (estado = Estado::libre)
        return "libre";
    else if (estado = Estado::mantenimiento)
        return "mantenimiento";
    else if (estado = Estado::ocupado)
        return "ocupado";
    else if (estado = Estado::reservado)
        return "reservado";
    else
        throw "Tipo de estado no valido.";
}

std::string Herramientas::getFecha(time_t *fecha)
{
    char buff[20];
    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(fecha));
    return buff;
}

time_t Herramientas::getFecha(std::string fecha)
{
    struct tm tm;
    strptime(fecha, "%Y-%m-%d %H:%M:%S", &tm);
    time_t t = mktime(&tm);  // t is now your desired time_t
    return t;
}

Horario getHorario(std::string horaEntrada, std::string horaSalida)
{
    Hora entrada, salida;
    entrada.hora = std::atoi(horaEntrada.substr(0,2));
    entrada.minuto = std::atoi(horaEntrada.substr(3,6));
    salida.hora = std::atoi(horaSalida.substr(0,2));
    salida.minuto = std::atoi(horaSalida.substr(3,6));
    Horario horario;
    horario.entrada = entrada;
    horario.salida = salida;
    return horario;
}
