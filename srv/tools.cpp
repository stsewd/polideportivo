#include <regex>
#include <ctime>

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
    if (estado == Estado::libre)
        return "libre";
    else if (estado == Estado::mantenimiento)
        return "mantenimiento";
    else if (estado == Estado::ocupado)
        return "ocupado";
    else if (estado == Estado::reservado)
        return "reservado";
    else
        throw "Tipo de estado no valido.";
}

std::string getFecha(time_t *fecha)
{
    char buff[20];
    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(fecha));
    return buff;
}

time_t getFechaString(std::string fecha)
{
    struct tm tm;
    strptime(fecha.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
    time_t t = mktime(&tm);  // t is now your desired time_t
    return t;
}

Horario getHorario(std::string horaEntrada, std::string horaSalida)
{
    Hora entrada, salida;
    std::vector<std::string> elementos = split(horaEntrada,':');
    entrada.hora = std::atoi(elementos[0].c_str());
    entrada.minuto = std::atoi(elementos[1].c_str());
    elementos.clear();
    elementos=split(horaSalida,':');
    salida.hora = std::atoi(elementos[0].c_str());
    salida.minuto = std::atoi(elementos[1].c_str());
    Horario horario;
    horario.entrada = entrada;
    horario.salida = salida;
    return horario;
}


std::vector<std::string> split(std::string texto, char delim)
{
    std::vector<std::string> elementos;
    std::string aux="";
    for(char a : texto){
        if(a!=delim){
            aux+=a;
        }else{
            elementos.push_back(aux);
            aux="";
        }
    }
    elementos.push_back(aux);
    return elementos;
}

void validarFechas(time_t fechaReservacion, time_t fechaFinReservacion)
{
    if (difftime(fechaReservacion, fechaFinReservacion) > 0)
        throw "Fecha final mayor a la inicial";
}
