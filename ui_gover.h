/********************************************************************************
** Form generated from reading UI file 'gover.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOVER_H
#define UI_GOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *goverLabel;
    QLabel *tijdLabel;
    QPushButton *sluitBtn;
    QPushButton *opnieuwBtn;
    QPushButton *nieuwBtn;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 145);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(400, 145));
        Dialog->setMaximumSize(QSize(400, 145));
        QIcon icon;
        icon.addFile(QStringLiteral("../img/mijnb.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        goverLabel = new QLabel(Dialog);
        goverLabel->setObjectName(QStringLiteral("goverLabel"));
        goverLabel->setGeometry(QRect(0, 20, 400, 20));
        goverLabel->setAlignment(Qt::AlignCenter);
        tijdLabel = new QLabel(Dialog);
        tijdLabel->setObjectName(QStringLiteral("tijdLabel"));
        tijdLabel->setGeometry(QRect(25, 60, 375, 20));
        sluitBtn = new QPushButton(Dialog);
        sluitBtn->setObjectName(QStringLiteral("sluitBtn"));
        sluitBtn->setGeometry(QRect(275, 100, 100, 25));
        opnieuwBtn = new QPushButton(Dialog);
        opnieuwBtn->setObjectName(QStringLiteral("opnieuwBtn"));
        opnieuwBtn->setGeometry(QRect(150, 100, 100, 25));
        nieuwBtn = new QPushButton(Dialog);
        nieuwBtn->setObjectName(QStringLiteral("nieuwBtn"));
        nieuwBtn->setGeometry(QRect(25, 100, 100, 25));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        goverLabel->setText(QString());
        tijdLabel->setText(QApplication::translate("Dialog", "Time: ", 0));
        sluitBtn->setText(QApplication::translate("Dialog", "&Exit", 0));
        opnieuwBtn->setText(QApplication::translate("Dialog", "&Restart Game", 0));
        nieuwBtn->setText(QApplication::translate("Dialog", "&New Game", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOVER_H
