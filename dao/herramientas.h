#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H

#include <ctime>
#include <string>
class herramientas
{
public:
    herramientas();
    std::string get(time_t *fecha);
    std::time_t get(std::string fecha);
};

#endif // HERRAMIENTAS_H
