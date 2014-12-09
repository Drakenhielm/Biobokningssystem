#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QDir>
#include <QString>
#include <QFile>
#include <QPixmap>

class ImageHandler
{
public:
    ImageHandler();

    bool copyImage(const QString & fromPath);
    QString getFolderPath() const;
    QPixmap getPixmap(const QString &fileName) const;
    QString lastInsertedFileName() const;

private:
    QString folder;
    QString lastInserted;
    QDir dir;

    bool createFolder();
    bool validImageFile(const QString &fileName) const;
    QString getFileName(const QString &path) const;
    void generateUniqueFileName(QString & fileName);
    bool fileNameExists(const QString &fileName) const;
};


#endif // IMAGEHANDLER_H
