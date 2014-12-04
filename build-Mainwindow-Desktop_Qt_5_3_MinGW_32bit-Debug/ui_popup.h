/********************************************************************************
** Form generated from reading UI file 'popup.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_popup
{
public:
    QLabel *TitleLabel;
    QLabel *PlaytimeLabel;
    QLabel *GenreLabel;
    QLabel *PictureLabel;
    QLabel *YearLabel;
    QLabel *DescLabel;
    QComboBox *GenreCbb;
    QSpinBox *YearSpinBox;
    QSpinBox *AgeSpinBox;
    QTextEdit *DescritionEdit;
    QPushButton *AddButton;
    QPushButton *CancelButton;
    QLineEdit *TitleBox;
    QLineEdit *PictureEdit;
    QPushButton *ExploreButton;
    QLabel *CurrGenreLabel;
    QPushButton *RemoveGenreButton;
    QSpinBox *PlaytimeSpinBox;
    QLabel *AgeLabel;
    QPushButton *AddGenreButton;

    void setupUi(QDialog *popup)
    {
        if (popup->objectName().isEmpty())
            popup->setObjectName(QStringLiteral("popup"));
        popup->resize(449, 647);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(popup->sizePolicy().hasHeightForWidth());
        popup->setSizePolicy(sizePolicy);
        TitleLabel = new QLabel(popup);
        TitleLabel->setObjectName(QStringLiteral("TitleLabel"));
        TitleLabel->setGeometry(QRect(83, 103, 26, 16));
        PlaytimeLabel = new QLabel(popup);
        PlaytimeLabel->setObjectName(QStringLiteral("PlaytimeLabel"));
        PlaytimeLabel->setGeometry(QRect(83, 134, 61, 16));
        GenreLabel = new QLabel(popup);
        GenreLabel->setObjectName(QStringLiteral("GenreLabel"));
        GenreLabel->setGeometry(QRect(84, 199, 37, 16));
        PictureLabel = new QLabel(popup);
        PictureLabel->setObjectName(QStringLiteral("PictureLabel"));
        PictureLabel->setGeometry(QRect(81, 260, 41, 16));
        YearLabel = new QLabel(popup);
        YearLabel->setObjectName(QStringLiteral("YearLabel"));
        YearLabel->setGeometry(QRect(81, 291, 41, 16));
        DescLabel = new QLabel(popup);
        DescLabel->setObjectName(QStringLiteral("DescLabel"));
        DescLabel->setGeometry(QRect(79, 323, 71, 16));
        GenreCbb = new QComboBox(popup);
        GenreCbb->setObjectName(QStringLiteral("GenreCbb"));
        GenreCbb->setGeometry(QRect(210, 200, 74, 23));
        GenreCbb->setContextMenuPolicy(Qt::DefaultContextMenu);
        YearSpinBox = new QSpinBox(popup);
        YearSpinBox->setObjectName(QStringLiteral("YearSpinBox"));
        YearSpinBox->setGeometry(QRect(290, 290, 62, 24));
        YearSpinBox->setMaximum(9999);
        YearSpinBox->setValue(2014);
        AgeSpinBox = new QSpinBox(popup);
        AgeSpinBox->setObjectName(QStringLiteral("AgeSpinBox"));
        AgeSpinBox->setGeometry(QRect(290, 160, 62, 24));
        AgeSpinBox->setMaximum(9999);
        AgeSpinBox->setValue(12);
        DescritionEdit = new QTextEdit(popup);
        DescritionEdit->setObjectName(QStringLiteral("DescritionEdit"));
        DescritionEdit->setGeometry(QRect(79, 344, 271, 192));
        AddButton = new QPushButton(popup);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(220, 570, 80, 23));
        CancelButton = new QPushButton(popup);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(310, 570, 80, 23));
        TitleBox = new QLineEdit(popup);
        TitleBox->setObjectName(QStringLiteral("TitleBox"));
        TitleBox->setGeometry(QRect(140, 100, 211, 23));
        PictureEdit = new QLineEdit(popup);
        PictureEdit->setObjectName(QStringLiteral("PictureEdit"));
        PictureEdit->setGeometry(QRect(131, 259, 171, 23));
        ExploreButton = new QPushButton(popup);
        ExploreButton->setObjectName(QStringLiteral("ExploreButton"));
        ExploreButton->setGeometry(QRect(310, 259, 41, 23));
        CurrGenreLabel = new QLabel(popup);
        CurrGenreLabel->setObjectName(QStringLiteral("CurrGenreLabel"));
        CurrGenreLabel->setGeometry(QRect(80, 220, 211, 21));
        RemoveGenreButton = new QPushButton(popup);
        RemoveGenreButton->setObjectName(QStringLiteral("RemoveGenreButton"));
        RemoveGenreButton->setGeometry(QRect(270, 230, 81, 23));
        PlaytimeSpinBox = new QSpinBox(popup);
        PlaytimeSpinBox->setObjectName(QStringLiteral("PlaytimeSpinBox"));
        PlaytimeSpinBox->setGeometry(QRect(290, 130, 62, 24));
        PlaytimeSpinBox->setMaximum(9999);
        PlaytimeSpinBox->setValue(180);
        AgeLabel = new QLabel(popup);
        AgeLabel->setObjectName(QStringLiteral("AgeLabel"));
        AgeLabel->setGeometry(QRect(83, 166, 72, 16));
        AddGenreButton = new QPushButton(popup);
        AddGenreButton->setObjectName(QStringLiteral("AddGenreButton"));
        AddGenreButton->setGeometry(QRect(300, 200, 51, 23));
        TitleLabel->raise();
        PlaytimeLabel->raise();
        GenreLabel->raise();
        PictureLabel->raise();
        YearLabel->raise();
        DescLabel->raise();
        GenreCbb->raise();
        YearSpinBox->raise();
        AgeSpinBox->raise();
        DescritionEdit->raise();
        AddButton->raise();
        CancelButton->raise();
        TitleBox->raise();
        PictureEdit->raise();
        ExploreButton->raise();
        CurrGenreLabel->raise();
        PlaytimeSpinBox->raise();
        AgeLabel->raise();
        RemoveGenreButton->raise();
        AddGenreButton->raise();

        retranslateUi(popup);

        QMetaObject::connectSlotsByName(popup);
    } // setupUi

    void retranslateUi(QDialog *popup)
    {
        popup->setWindowTitle(QApplication::translate("popup", "Dialog", 0));
        TitleLabel->setText(QApplication::translate("popup", "Title", 0));
        PlaytimeLabel->setText(QApplication::translate("popup", "Playtime", 0));
        GenreLabel->setText(QApplication::translate("popup", "Genre", 0));
        PictureLabel->setText(QApplication::translate("popup", "Image", 0));
        YearLabel->setText(QApplication::translate("popup", "Year", 0));
        DescLabel->setText(QApplication::translate("popup", "Description", 0));
        GenreCbb->clear();
        GenreCbb->insertItems(0, QStringList()
         << QApplication::translate("popup", "Drama", 0)
         << QApplication::translate("popup", "Komedi", 0)
         << QApplication::translate("popup", "Thriller", 0)
         << QApplication::translate("popup", "Action", 0)
        );
        AddButton->setText(QApplication::translate("popup", "Add", 0));
        CancelButton->setText(QApplication::translate("popup", "Cancel", 0));
        PictureEdit->setText(QString());
        ExploreButton->setText(QApplication::translate("popup", "...", 0));
        CurrGenreLabel->setText(QString());
        RemoveGenreButton->setText(QApplication::translate("popup", "Remove", 0));
        AgeLabel->setText(QApplication::translate("popup", "Age-limit", 0));
        AddGenreButton->setText(QApplication::translate("popup", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class popup: public Ui_popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
