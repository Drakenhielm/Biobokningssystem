#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>

class DatabaseHandler
{
public:
    DatabaseHandler();

    bool databaseExist();
    void createDatabase();
    bool openDatabase();

private:
};

#endif // DATABASEHANDLER_H
