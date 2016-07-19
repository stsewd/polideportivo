#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include "espacio.h"
#include "espaciocomplementario.h"
#include "espaciodeportivo.h"


void validarCedula(std::string cedula);
void validarTelefono(std::string telefono);
void validarString(std::string str);
void validarNumero(double num);
TipoEspacioComplementario getTipoEspacioComplementario(std::string tipoEspacio);
Estado getEstado(std::string estadoEspacio);
TipoEspacioDeportivo getTipoEspacioDeportivo(std::string tipoEspacio);
Estado getEstado(std::string estadoEspacio);
std::string estadoToString(Estado estado);
std::string getFecha(time_t *fecha);
time_t getFechaString(std::string fecha);
Horario getHorario(std::string horaentrada, std::string horaSalida);
std::vector<std::string> split(std::string texto, char delim);
#endif // TOOLS_H
