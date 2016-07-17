#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H

#include <ctime>
#include <string>
class herramientas
{
public:
    herramientas();
    std::string get(time_t *fecha);
};

#endif // HERRAMIENTAS_H
