#ifndef CONEXIONDB_H
#define CONEXIONDB_H


#include <stdlib.h>
#include <iostream>
#include <string>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class ConexionDB
{
public:

    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *statement;
    sql::ResultSet *resultset;

    ConexionDB();
    ConexionDB(std::string servidor, std::string user, std::string pass, std::string DB);
    ~ConexionDB();
};

#endif // CONEXIONDB_H
