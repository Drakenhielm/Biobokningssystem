#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QDir>
#include <QString>
#include <QFile>
#include <QPixmap>
#include <QDebug>

class ImageHandler
{
public:
    ImageHandler();

    bool copyImage(const QString & fromPath);
    bool replaceImage(const QString &oldFileName, const QString &newFilePath);
    bool removeImage(const QString &fileName);
    QString getFolderPath() const;
    QPixmap getPixmap(const QString &fileName) const;
    QString lastInsertedFileName() const;
    bool fileNameExists(const QString &fileName) const;

private:
    QString folder;
    QString lastInserted;
    QDir dir;

    bool createFolder();
    bool validImageFile(const QString &fileName) const;
    QString getFileName(const QString &path) const;
    void generateUniqueFileName(QString & fileName);
};


#endif // IMAGEHANDLER_H
