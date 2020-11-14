// hellodb.cpp
// Compile with: g++ -Wall -I/usr/include/cppconn -o hellodb hellodb.cpp -L/usr/lib -lmysqlcppconn

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <mysql_connection.h>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>

using namespace std;

int main()
{
    cout << endl;
    cout << "Running 'SELECT * FROM potluck'" << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        // Create a connection
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "P@$$W0RD");
        // Connect to the MySQL events database
        con->setSchema("events");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM potluck");

        while (res->next()) {
            /* Access column data by alias or column name */
            cout << res->getString("id") << "\t" 
                 << res->getString("name") << "\t" 
                 << setw(15) << left 
                            << res->getString("Food") << "\t"
                 << res->getString("confirmed") << "\t"
                 << res->getString("signup_date") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    return 0;
}

