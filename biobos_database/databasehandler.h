#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>

//temp for debugging
#include <QDebug>
#include <iostream>
#include <iomanip>

class DatabaseHandler
{
public:
    DatabaseHandler(const QString & fileName);

    //functions
    bool databaseExist();
    bool openDatabase();

private:
    //variables
    QString fileName;

    //functions
    void createDatabase();
};

#endif // DATABASEHANDLER_H
