/********************************************************************************
** Form generated from reading UI file 'add_Movie.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_MOVIE_H
#define UI_ADD_MOVIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_Movie
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *AddButton;
    QPushButton *CancelButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *TitleLabel;
    QLineEdit *TitleBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PlaytimeLabel;
    QSpinBox *PlaytimeSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *AgeLabel;
    QSpinBox *AgeSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *GenreLabel;
    QComboBox *GenreCbb;
    QPushButton *AddGenreButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *CurrGenreLabel;
    QPushButton *RemoveGenreButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *PictureLabel;
    QLineEdit *PictureEdit;
    QPushButton *ExploreButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *YearLabel;
    QSpinBox *YearSpinBox;
    QVBoxLayout *verticalLayout;
    QLabel *DescLabel;
    QTextEdit *DescritionEdit;

    void setupUi(QDialog *add_Movie)
    {
        if (add_Movie->objectName().isEmpty())
            add_Movie->setObjectName(QStringLiteral("add_Movie"));
        add_Movie->resize(304, 491);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(add_Movie->sizePolicy().hasHeightForWidth());
        add_Movie->setSizePolicy(sizePolicy);
        add_Movie->setMinimumSize(QSize(304, 491));
        add_Movie->setMaximumSize(QSize(304, 491));
        layoutWidget = new QWidget(add_Movie);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 450, 169, 32));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout_8->addWidget(AddButton);

        CancelButton = new QPushButton(layoutWidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_8->addWidget(CancelButton);

        layoutWidget1 = new QWidget(add_Movie);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 260, 420));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        TitleLabel = new QLabel(layoutWidget1);
        TitleLabel->setObjectName(QStringLiteral("TitleLabel"));

        horizontalLayout->addWidget(TitleLabel);

        TitleBox = new QLineEdit(layoutWidget1);
        TitleBox->setObjectName(QStringLiteral("TitleBox"));

        horizontalLayout->addWidget(TitleBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PlaytimeLabel = new QLabel(layoutWidget1);
        PlaytimeLabel->setObjectName(QStringLiteral("PlaytimeLabel"));

        horizontalLayout_2->addWidget(PlaytimeLabel);

        PlaytimeSpinBox = new QSpinBox(layoutWidget1);
        PlaytimeSpinBox->setObjectName(QStringLiteral("PlaytimeSpinBox"));
        PlaytimeSpinBox->setMaximum(9999);
        PlaytimeSpinBox->setValue(180);

        horizontalLayout_2->addWidget(PlaytimeSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        AgeLabel = new QLabel(layoutWidget1);
        AgeLabel->setObjectName(QStringLiteral("AgeLabel"));

        horizontalLayout_3->addWidget(AgeLabel);

        AgeSpinBox = new QSpinBox(layoutWidget1);
        AgeSpinBox->setObjectName(QStringLiteral("AgeSpinBox"));
        AgeSpinBox->setMaximum(9999);
        AgeSpinBox->setValue(12);

        horizontalLayout_3->addWidget(AgeSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        GenreLabel = new QLabel(layoutWidget1);
        GenreLabel->setObjectName(QStringLiteral("GenreLabel"));

        horizontalLayout_4->addWidget(GenreLabel);

        GenreCbb = new QComboBox(layoutWidget1);
        GenreCbb->setObjectName(QStringLiteral("GenreCbb"));
        GenreCbb->setContextMenuPolicy(Qt::DefaultContextMenu);

        horizontalLayout_4->addWidget(GenreCbb);

        AddGenreButton = new QPushButton(layoutWidget1);
        AddGenreButton->setObjectName(QStringLiteral("AddGenreButton"));

        horizontalLayout_4->addWidget(AddGenreButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        CurrGenreLabel = new QLabel(layoutWidget1);
        CurrGenreLabel->setObjectName(QStringLiteral("CurrGenreLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CurrGenreLabel->sizePolicy().hasHeightForWidth());
        CurrGenreLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(CurrGenreLabel);

        RemoveGenreButton = new QPushButton(layoutWidget1);
        RemoveGenreButton->setObjectName(QStringLiteral("RemoveGenreButton"));

        horizontalLayout_5->addWidget(RemoveGenreButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        PictureLabel = new QLabel(layoutWidget1);
        PictureLabel->setObjectName(QStringLiteral("PictureLabel"));

        horizontalLayout_6->addWidget(PictureLabel);

        PictureEdit = new QLineEdit(layoutWidget1);
        PictureEdit->setObjectName(QStringLiteral("PictureEdit"));

        horizontalLayout_6->addWidget(PictureEdit);

        ExploreButton = new QPushButton(layoutWidget1);
        ExploreButton->setObjectName(QStringLiteral("ExploreButton"));

        horizontalLayout_6->addWidget(ExploreButton);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        YearLabel = new QLabel(layoutWidget1);
        YearLabel->setObjectName(QStringLiteral("YearLabel"));

        horizontalLayout_7->addWidget(YearLabel);

        YearSpinBox = new QSpinBox(layoutWidget1);
        YearSpinBox->setObjectName(QStringLiteral("YearSpinBox"));
        YearSpinBox->setMaximum(9999);
        YearSpinBox->setValue(2014);

        horizontalLayout_7->addWidget(YearSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        DescLabel = new QLabel(layoutWidget1);
        DescLabel->setObjectName(QStringLiteral("DescLabel"));

        verticalLayout->addWidget(DescLabel);

        DescritionEdit = new QTextEdit(layoutWidget1);
        DescritionEdit->setObjectName(QStringLiteral("DescritionEdit"));

        verticalLayout->addWidget(DescritionEdit);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(add_Movie);

        QMetaObject::connectSlotsByName(add_Movie);
    } // setupUi

    void retranslateUi(QDialog *add_Movie)
    {
        add_Movie->setWindowTitle(QApplication::translate("add_Movie", "Dialog", 0));
        AddButton->setText(QApplication::translate("add_Movie", "Submit", 0));
        CancelButton->setText(QApplication::translate("add_Movie", "Cancel", 0));
        TitleLabel->setText(QApplication::translate("add_Movie", "Title", 0));
        PlaytimeLabel->setText(QApplication::translate("add_Movie", "Playtime", 0));
        AgeLabel->setText(QApplication::translate("add_Movie", "Age", 0));
        GenreLabel->setText(QApplication::translate("add_Movie", "Genre", 0));
        GenreCbb->clear();
        GenreCbb->insertItems(0, QStringList()
         << QApplication::translate("add_Movie", "Drama", 0)
         << QApplication::translate("add_Movie", "Comedy", 0)
         << QApplication::translate("add_Movie", "Thriller", 0)
         << QApplication::translate("add_Movie", "Action", 0)
        );
        AddGenreButton->setText(QApplication::translate("add_Movie", "+", 0));
        CurrGenreLabel->setText(QString());
        RemoveGenreButton->setText(QApplication::translate("add_Movie", "Remove", 0));
        PictureLabel->setText(QApplication::translate("add_Movie", "Picture", 0));
        PictureEdit->setText(QString());
        ExploreButton->setText(QApplication::translate("add_Movie", "...", 0));
        YearLabel->setText(QApplication::translate("add_Movie", "Year", 0));
        DescLabel->setText(QApplication::translate("add_Movie", "Description", 0));
    } // retranslateUi

};

namespace Ui {
    class add_Movie: public Ui_add_Movie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_MOVIE_H
