#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", parent)
{
}

bool MovieModel::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year)
{
    database().transaction();
    int rowCount = this->rowCount();
    qDebug() << rowCount;
    if(!insertRow(rowCount))
    {
        qDebug() << "insertRows" << lastError().text();
        return false;
    }

    setData(index(rowCount,1), title);
    setData(index(rowCount,2), playTime);
    setData(index(rowCount,3), ageLimit);
    setData(index(rowCount,4), description);
    setData(index(rowCount,5), genre);
    setData(index(rowCount,6), year);

    if(submitAll())
    {
        return database().commit();
    }
    else
    {
        database().rollback();
        qDebug() << "Database Write Error" <<
            "The database reported an error: " <<
            lastError().text();
        return false;
    }
}


