#include "herramientas.h"

herramientas::herramientas()
{

}

std::__cxx11::string herramientas::get(time_t *fecha)
{
    struct tm tmp = fecha;
    //formato del DATETIME en mysql
    //YYYY-MM-DD HH:MM:SS
    std::string fecha = std::string(tmp->tm_year+1900) +"-"+std::string(tmp->tm_mon+1)+"-"+std::string(tmp->tm_mday)+" "+std::string(tmp->tm_hour)+":"+std::string(tmp->tm_min)+":"+std::string(tmp->tm_sec);
    return fecha;
}


