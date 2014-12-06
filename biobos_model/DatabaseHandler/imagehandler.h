#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QDir>
#include <QString>
#include <QFile>

class ImageHandler
{
public:
    ImageHandler();

    QString copyImage(const QString & imagePath);
    QString getFolderPath() const;

private:
    QString folder;
    QDir dir;
    bool createFolder();
    bool validImageFile(const QString &fileName) const;
    QString getFileName(const QString &path) const;
    void generateUniqueFileName(QString & fileName);
    bool fileNameExists(const QString &fileName) const;
};


#endif // IMAGEHANDLER_H
