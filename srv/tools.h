#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include "espacio.h"
#include "espaciocomplementario.h"
#include "espaciodeportivo.h"
#include "../dao/espaciocomplementariodao.h"
#include "../dao/espaciodeportivodao.h"


void validarCedula(std::string cedula);
void validarTelefono(std::string telefono);
void validarString(std::string str);
void validarNumero(double num);
TipoEspacioComplementario getTipoEspacioComplementario(std::string tipoEspacio);
TipoEspacioDeportivo getTipoEspacioDeportivo(std::string tipoEspacio);
Estado getEstado(std::string estadoEspacio);
std::string estadoToString(Estado estado);
std::string getFecha(time_t *fecha);
time_t getFechaString(std::string fecha);
Horario getHorario(std::string horaentrada, std::string horaSalida);
std::vector<std::string> split(std::string texto, char delim);
void validarFechas(time_t fechaReservacion, time_t fechaFinReservacion);
Espacio *getEspacio(std::string nombreEspacio);

#endif // TOOLS_H
