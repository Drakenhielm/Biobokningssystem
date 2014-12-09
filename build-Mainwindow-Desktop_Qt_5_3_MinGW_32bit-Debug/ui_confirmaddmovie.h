/********************************************************************************
** Form generated from reading UI file 'confirmaddmovie.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMADDMOVIE_H
#define UI_CONFIRMADDMOVIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_confirmAddMovie
{
public:
    QPushButton *AddButton;
    QPushButton *CancelButton;
    QLabel *label;

    void setupUi(QDialog *confirmAddMovie)
    {
        if (confirmAddMovie->objectName().isEmpty())
            confirmAddMovie->setObjectName(QStringLiteral("confirmAddMovie"));
        confirmAddMovie->resize(400, 300);
        AddButton = new QPushButton(confirmAddMovie);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(50, 120, 80, 23));
        CancelButton = new QPushButton(confirmAddMovie);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(230, 120, 80, 23));
        label = new QLabel(confirmAddMovie);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 50, 251, 16));

        retranslateUi(confirmAddMovie);

        QMetaObject::connectSlotsByName(confirmAddMovie);
    } // setupUi

    void retranslateUi(QDialog *confirmAddMovie)
    {
        confirmAddMovie->setWindowTitle(QApplication::translate("confirmAddMovie", "Dialog", 0));
        AddButton->setText(QApplication::translate("confirmAddMovie", "L\303\244gg till", 0));
        CancelButton->setText(QApplication::translate("confirmAddMovie", "Avbryt", 0));
        label->setText(QApplication::translate("confirmAddMovie", "Du h\303\245ller p\303\245 att l\303\244gga till en film", 0));
    } // retranslateUi

};

namespace Ui {
    class confirmAddMovie: public Ui_confirmAddMovie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMADDMOVIE_H
