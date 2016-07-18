#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H

#include <ctime>
#include <string>
class herramientas
{
public:
    herramientas();
    std::string getFecha(time_t *fecha);
    std::time_t getFecha(std::string fecha);
};

#endif // HERRAMIENTAS_H
