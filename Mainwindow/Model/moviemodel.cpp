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

    QString image;

    if(imgHandler.copyImage(imagePath)) //copy image
    {
        //if success - save the file name
        image = imgHandler.lastInsertedFileName();
    }

    //database values
    QMap<QString, QVariant> values;
    values.insert(QString("Title"), title);
    values.insert(QString("PlayTime"), playTime);
    values.insert(QString("AgeLimit"), ageLimit);
    values.insert(QString("Description"), description);
    values.insert(QString("Genre"), genre);
    values.insert(QString("Year"), year);
    values.insert(QString("MoviePoster"), image);

    int id = dh.insert("movie", values); // insert values to the database

    return id;
}

bool MovieModel::editMovie(int movieID, const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, const QString &imagePath)
{
    bool ok;

    int row = getRowByPrimaryKeyValue(movieID);

    QString oldImage = data(index(row, MoviePoster)).toString();

    if(!imgHandler.fileNameExists(oldImage))
    {
        ok = imgHandler.copyImage(imagePath);
    }
    else
    {
        ok = imgHandler.replaceImage(oldImage, imagePath);
    }

    QString newImage;
    if(ok == true)
    {
        newImage = imgHandler.lastInsertedFileName();
    }

    //database values
    QMap<QString, QVariant> values;
    values.insert(QString("MovieID"), movieID);
    values.insert(QString("Title"), title);
    values.insert(QString("PlayTime"), playTime);
    values.insert(QString("AgeLimit"), ageLimit);
    values.insert(QString("Description"), description);
    values.insert(QString("Genre"), genre);
    values.insert(QString("Year"), year);
    values.insert(QString("MoviePoster"), newImage);

    //edit movie
    return dh.edit("movie", values, "MovieID = ?", movieID);
}

bool MovieModel::remove(const QVariant &pkValue)
{
    bool ok = true;

    dh.transaction();

    int row = getRowByPrimaryKeyValue(pkValue);

    //remove image
    imgHandler.removeImage(BaseModel::data(index(row, MovieModel::MoviePoster)).toString());

    //remove from movie
    ok = ok && dh.remove("movie", "MovieID = ?", pkValue);

    //remove from booking
    ok = ok && dh.remove("booking", "ShowID IN (SELECT ShowID FROM show WHERE MovieID = ?)", pkValue);

    //remove from seatbooking
    ok = ok && dh.remove("seatbooking",
                         "BookingID IN (SELECT BookingID FROM booking JOIN show ON booking.ShowID = show.ShowID WHERE MovieID = ?)",
                         pkValue);

    //remove from show
    ok = ok && dh.remove("show", "MovieID = ?", pkValue);

    return ok && dh.endTransaction(ok);
}
