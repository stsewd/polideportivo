#include "herramientas.h"

herramientas::herramientas()
{

}

std::__cxx11::string herramientas::get(time_t *fecha)
{
    char buff[20];
    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(fecha));
    return buff;
}

time_t herramientas::get(std::__cxx11::string fecha)
{
    const char *time_details = "16:35:12";
    struct tm tm;
    strptime(fecha, "%Y-%m-%d %H:%M:%S", &tm);
    time_t t = mktime(&tm);  // t is now your desired time_t
    return t;
}



