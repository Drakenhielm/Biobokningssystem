#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QStringList>
#include <QPair>

#include <databasehandler.h>

void printTableTest();
bool hallTableOk();
bool movieTableOk();
bool seatTableOk();
bool showTableOk();
bool bookingTableOk();
bool seatbookingTableOk();
void printTableList();

int insertBooking(DatabaseHandler &dh, int showID, const QString &phone);
bool editBooking(DatabaseHandler &dh, int bookingID, int showID, const QString & phone);
bool removeBooking(DatabaseHandler &dh, int bookingID);

//Test program
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DatabaseHandler dh;
    std::cout << "1. Open database: ";
    if(dh.openDatabase())
        std::cout << "OK" << std::endl << std::endl;
    else
        std::cout << QSqlError().text().toStdString() << std::endl << std::endl;

    std::cout << "2. Complete database: " << std::boolalpha << dh.databaseComplete() << std::endl << std::endl;

    if(!dh.databaseComplete())
        dh.createDatabase();

    std::cout << "3. Test all tables" << std::endl;
    printTableTest();
    std::cout << std::endl;

    std::cout << "4. Print table list";
    printTableList();
    std::cout << std::endl;

    std::cout << "5. Insert: ";
    int idInsert = insertBooking(dh, 1, "Insert 1");
    int idEdit = insertBooking(dh, 1, "Insert 2"); //edited later
    int idRemove = insertBooking(dh, 1, "Insert 3");
    if(idInsert > 0 && idEdit > 0 && idRemove > 0)
        std::cout << "OK" << std::endl;
    else
        std::cout << "NOK" << std::endl;
    std::cout << std::endl;

    std::cout << "6. Edit: ";
    if(editBooking(dh, idEdit, 2, "Edit"))
        std::cout << "OK" << std::endl;
    else
        std::cout << "NOK" << std::endl;
    std::cout << std::endl;

    std::cout << "7. Remove: ";
    if(removeBooking(dh, idRemove))
        std::cout << "OK" << std::endl;
    else
        std::cout << "NOK" << std::endl;
    std::cout << std::endl;

    std::cout << QSqlError().text().toStdString() << std::endl;
    return a.exec();
}

void printTableTest()
{
    int errors = 0;
    if(!hallTableOk())
        std::cout << "\t" << ++errors << ". hall table NOT OK" << std::endl;
    if(!movieTableOk())
        std::cout << "\t" << ++errors << ". movie table NOT OK" << std::endl;
    if(!seatTableOk())
        std::cout << "\t" << ++errors << ". seat table NOT OK" << std::endl;
    if(!showTableOk())
        std::cout << "\t" << ++errors << ". show table NOT OK" << std::endl;
    if(!bookingTableOk())
        std::cout << "\t" << ++errors << ". booking table NOT OK" << std::endl;
    if(!seatbookingTableOk())
        std::cout << "\t" << ++errors << ". seatbooking table NOT OK" << std::endl;

    if(errors == 0)
        std::cout << "All tables are OK" << std::endl;
    else
        std::cout << "Number of errors: " << errors << std::endl;
}


bool hallTableOk()
{
    QSqlRecord record = QSqlDatabase::database().record("hall");
    return (record.indexOf("HallID") == 0
            && record.indexOf("Name") > 0
            && record.indexOf("SoundSystem") > 0
            && record.indexOf("ScreenSize") > 0);
}

bool movieTableOk()
{
    QSqlRecord record = QSqlDatabase::database().record("movie");
    return (record.indexOf("MovieID") == 0
            && record.indexOf("Title") > 0
            && record.indexOf("PlayTime") > 0
            && record.indexOf("AgeLimit") > 0
            && record.indexOf("Description") > 0
            && record.indexOf("Genre") > 0
            && record.indexOf("Year") > 0
            && record.indexOf("MoviePoster") > 0);
}

bool seatTableOk()
{
    QSqlRecord record = QSqlDatabase::database().record("seat");
    return (record.indexOf("SeatID") == 0
            && record.indexOf("Row") > 0
            && record.indexOf("Column") > 0
            && record.indexOf("SeatNr") > 0
            && record.indexOf("HallID") > 0);
}

bool showTableOk()
{
    QSqlRecord record = QSqlDatabase::database().record("show");
    return (record.indexOf("ShowID") == 0
            && record.indexOf("DateTime") > 0
            && record.indexOf("Price") > 0
            && record.indexOf("ThreeD") > 0
            && record.indexOf("Subtitles") > 0
            && record.indexOf("Language") > 0
            && record.indexOf("MovieID") > 0
            && record.indexOf("HallID") > 0);
}

bool bookingTableOk()
{
    QSqlRecord record = QSqlDatabase::database().record("booking");
    return (record.indexOf("BookingID") == 0
            && record.indexOf("ShowID") > 0
            && record.indexOf("Phone") > 0);
}

bool seatbookingTableOk()
{
    QSqlRecord record = QSqlDatabase::database().record("seatbooking");
    return (record.indexOf("SeatBookingID") == 0
            && record.indexOf("SeatID") > 0
            && record.indexOf("BookingID") > 0);
}

void printTableList()
{
    QStringList list = QSqlDatabase::database().tables();
    for (int i = 0; i < list.size(); ++i)
    {
        std::cout << list.at(i).toLocal8Bit().constData() << std::endl;
    }
}

int insertBooking(DatabaseHandler &dh, int showID, const QString &phone)
{
    QList<QPair<QString, QVariant> > list;
    list.append(qMakePair(QString("ShowID"), showID));
    list.append(qMakePair(QString("Phone"), phone));
    return dh.insert("booking", list);
}

bool editBooking(DatabaseHandler &dh, int bookingID, int showID, const QString & phone)
{
    QList<QPair<QString, QVariant> > list;
    list.append(qMakePair(QString("ShowID"), showID));
    list.append(qMakePair(QString("Phone"), phone));
    return dh.edit("booking", list, "BookingID", bookingID);
}

bool removeBooking(DatabaseHandler &dh, int bookingID)
{
    return dh.remove("booking", "BookingID", bookingID);
}
