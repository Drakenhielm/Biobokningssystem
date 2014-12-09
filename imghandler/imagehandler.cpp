#include "imagehandler.h"

ImageHandler::ImageHandler()
{
    folder = "img";
    dir = QDir::currentPath();
    if(!dir.cd(folder))
        createFolder();
}

bool ImageHandler::createFolder()
{
    dir = QDir::currentPath();
    dir.mkdir(folder);
    return dir.cd(folder);
}

/*Copy an image file to img folder. Returns the filename in the new folder.
 * The filename will be changed if there already exists a image with that filename.
 * If the copy fails an empty string will be returned */
bool ImageHandler::copyImage(const QString & fromPath)
{
    if(!dir.exists())
    {
        if(!createFolder())
            return false;
    }
    QString fileName = getFileName(fromPath);
    if(fileNameExists(fileName))
    {
        //if the filename exists we need to create a new unique filename for the image
        generateUniqueFileName(fileName);
    }
    if(validImageFile(fileName))
    {
        if(QFile::copy(fromPath, dir.path()+'/'+fileName))
        {
            lastInserted = fileName;
            return true;
        }
    }
    return false;
}

bool ImageHandler::removeImage(const QString &fileName)
{
    return QFile::remove(dir.path()+'/'+fileName);
}

QPixmap ImageHandler::getPixmap(const QString &fileName) const
{

    return QPixmap(dir.path()+'/'+fileName);
}

QString ImageHandler::lastInsertedFileName() const
{
    return lastInserted;
}

QString ImageHandler::getFolderPath() const
{
    return dir.path();
}

/*Check if the file extension is ".png", ".jpg", ".jpeg", ".gif" or ".bmp". */
bool ImageHandler::validImageFile(const QString &fileName) const
{
    QString extension = fileName.mid(fileName.lastIndexOf('.'), -1);
    return extension == ".png" || extension == ".jpg" || extension == ".jpeg"
            || extension == ".gif" || extension == ".bmp";
}

QString ImageHandler::getFileName(const QString &path) const
{
    int p = path.lastIndexOf('/');
    return path.mid(p+1, -1);
}

/*Genrates a unique file name within the folder
 *
 * Example: if fileName is "img.png" but "img.png" already exists in the folder,
 * then the new fileName will be "img2.png".
 *
 * If "img.png" and "img2.png" already exists, then the new fileName will be "img3.png".
 *
 * */
void ImageHandler::generateUniqueFileName(QString & fileName)
{
    QString fileNameWithoutExtension = fileName.mid(0, fileName.lastIndexOf('.'));
    QString extension = fileName.mid(fileName.lastIndexOf('.'), -1);
    int i = 2;
    while(fileNameExists(fileName))
    {
        fileName = fileNameWithoutExtension+QString::number(i)+extension;
        i++;
    }
}

bool ImageHandler::fileNameExists(const QString &fileName) const
{
    return QFileInfo::exists(dir.path()+'/'+fileName);
}
