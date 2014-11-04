#include "databasehandler.h"

DatabaseHandler::DatabaseHandler(const QString &fileName)
    : fileName{fileName}
{
}

bool DatabaseHandler::databaseExist()
{
    QFileInfo fileInfo(fileName);
    qDebug() << fileInfo.absoluteFilePath();
    return fileInfo.exists();
}

bool DatabaseHandler::openDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(this->fileName);
    if(!db.open())
        return false;
    if(!databaseExist())
        createDatabase();
    return true;
}

void DatabaseHandler::createDatabase()
{
    QSqlQuery query;
    query.exec(QString("CREATE TABLE hall(")
               +QString("HallID INTEGER PRIMARY KEY, ")
               +QString("Name TEXT, ")
               +QString("SoundSystem TEXT, ")
               +QString("ScreenSize TEXT)"));


}
