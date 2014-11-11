/********************************************************************************
** Form generated from reading UI file 'hallview.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HALLVIEW_H
#define UI_HALLVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HallView
{
public:

    void setupUi(QWidget *HallView)
    {
        if (HallView->objectName().isEmpty())
            HallView->setObjectName(QStringLiteral("HallView"));
        HallView->resize(400, 300);

        retranslateUi(HallView);

        QMetaObject::connectSlotsByName(HallView);
    } // setupUi

    void retranslateUi(QWidget *HallView)
    {
        HallView->setWindowTitle(QApplication::translate("HallView", "HallView", 0));
    } // retranslateUi

};

namespace Ui {
    class HallView: public Ui_HallView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HALLVIEW_H
