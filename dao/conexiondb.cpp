#include "conexiondb.h"


ConexionDB::ConexionDB()
{

}

ConexionDB::ConexionDB(std::string servidor, std::string user, std::string pass, std::string DB)
{
    driver = get_driver_instance();
    con = driver->connect(servidor,user,pass);
    con->setSchema(DB);
    statement = con->createStatement();
}

ConexionDB::~ConexionDB()
{
    con->close();
    statement->close();
    resultset->close();

}
