#ifndef MATRIXSEATMODEL_H
#define MATRIXSEATMODEL_H

class MatrixSeatModel : public BaseModel
{
public:
    MatrixSeatModel(QObject *parent = 0);

private:
    int hallID;
    int showID;
    QString bookingPhoneNr;
};

#endif // MATRIXSEATMODEL_H
