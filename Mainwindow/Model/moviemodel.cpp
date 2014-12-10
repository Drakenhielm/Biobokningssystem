#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", "MovieID", parent)
{
    setQuery("SELECT * FROM movie ORDER BY Title");
}

QString MovieModel::getMoviePoster(int row) const
{
    //name of the image
    QString image = data(index(row, MoviePoster)).toString();

    if(image != "" && imgHandler.fileNameExists(image))
    {
        //return the whole path to image
        return imgHandler.getFolderPath()+'/'+image;
    }

    //if no image file was found
    return QString();
}

int MovieModel::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, const QString &imagePath)
{
    dh.transaction();

    bool ok = imgHandler.copyImage(imagePath); //copy image

    QString image = imgHandler.lastInsertedFileName();

    QMap<QString, QVariant> values;
    values.insert(QString("Title"), title);
    values.insert(QString("PlayTime"), playTime);
    values.insert(QString("AgeLimit"), ageLimit);
    values.insert(QString("Description"), description);
    values.insert(QString("Genre"), genre);
    values.insert(QString("Year"), year);
    values.insert(QString("MoviePoster"), image);

    int id = dh.insert("movie", values); // insert values to the database
    ok = ok && id != -1;

    if(ok && dh.endTransaction(ok))
        return id;
    else
        return -1;
}

bool MovieModel::editMovie(int movieID, const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, const QString &imagePath)
{
    int row = getRowByPrimaryKeyValue(movieID);
    if(!imgHandler.fileNameExists(getMoviePoster(row)))
    {
        imgHandler.copyImage(imagePath);
    }
    else
    {
        imgHandler.replaceImage(getMoviePoster(row), imagePath);
    }

    QString image = imgHandler.lastInsertedFileName();

    QMap<QString, QVariant> values;
    values.insert(QString("MovieID"), movieID);
    values.insert(QString("Title"), title);
    values.insert(QString("PlayTime"), playTime);
    values.insert(QString("AgeLimit"), ageLimit);
    values.insert(QString("Description"), description);
    values.insert(QString("Genre"), genre);
    values.insert(QString("Year"), year);
    values.insert(QString("MoviePoster"), image);

    return dh.edit("movie", values, "MovieID = ?", movieID);
}

bool MovieModel::remove(const QVariant &pkValue)
{
    bool ok = true;
    dh.transaction();
    ok = ok && dh.remove("movie", "MovieID = ?", pkValue);
    ok = ok && dh.remove("booking", "ShowID IN (SELECT ShowID FROM show WHERE MovieID = ?)", pkValue);
    ok = ok && dh.remove("seatbooking",
                         "BookingID IN (SELECT BookingID FROM booking JOIN show ON booking.ShowID = show.ShowID WHERE MovieID = ?)",
                         pkValue);
    ok = ok && dh.remove("show", "MovieID = ?", pkValue);
    return ok && dh.endTransaction(ok);
}
