/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Venster
{
public:
    QFrame *labelFrame;
    QLabel *mijnbLabel;
    QLabel *mOverLabel;
    QLabel *tOverLabel;
    QLabel *klokLabel;
    QLabel *grootteLabel;
    QRadioButton *kleinLabel;
    QRadioButton *medLabel;
    QRadioButton *grootLabel;
    QRadioButton *aangLabel;
    QLabel *hoogteLabel;
    QLineEdit *hoogteEdit;
    QLineEdit *breedteEdit;
    QLabel *breedteLabel;
    QLineEdit *mijnenEdit;
    QLabel *mijnenLabel;
    QPushButton *grootteBtn;

    void setupUi(QDialog *Venster)
    {
        if (Venster->objectName().isEmpty())
            Venster->setObjectName(QStringLiteral("Venster"));
        Venster->setEnabled(true);
        Venster->resize(500, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Venster->sizePolicy().hasHeightForWidth());
        Venster->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("img/mijnb.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Venster->setWindowIcon(icon);
        Venster->setModal(false);
        labelFrame = new QFrame(Venster);
        labelFrame->setObjectName(QStringLiteral("labelFrame"));
        labelFrame->setGeometry(QRect(20, 20, 180, 180));
        labelFrame->setFrameShape(QFrame::StyledPanel);
        labelFrame->setFrameShadow(QFrame::Raised);
        mijnbLabel = new QLabel(Venster);
        mijnbLabel->setObjectName(QStringLiteral("mijnbLabel"));
        mijnbLabel->setGeometry(QRect(20, 210, 30, 30));
        sizePolicy.setHeightForWidth(mijnbLabel->sizePolicy().hasHeightForWidth());
        mijnbLabel->setSizePolicy(sizePolicy);
        mijnbLabel->setLineWidth(0);
        mijnbLabel->setPixmap(QPixmap(QString::fromUtf8("img/mijnb.png")));
        mOverLabel = new QLabel(Venster);
        mOverLabel->setObjectName(QStringLiteral("mOverLabel"));
        mOverLabel->setGeometry(QRect(55, 215, 35, 20));
        sizePolicy.setHeightForWidth(mOverLabel->sizePolicy().hasHeightForWidth());
        mOverLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        mOverLabel->setFont(font);
        mOverLabel->setLayoutDirection(Qt::LeftToRight);
        mOverLabel->setAutoFillBackground(false);
        mOverLabel->setFrameShape(QFrame::Panel);
        mOverLabel->setFrameShadow(QFrame::Sunken);
        mOverLabel->setTextFormat(Qt::AutoText);
        mOverLabel->setScaledContents(false);
        mOverLabel->setAlignment(Qt::AlignCenter);
        mOverLabel->setWordWrap(false);
        mOverLabel->setMargin(0);
        mOverLabel->setIndent(-1);
        tOverLabel = new QLabel(Venster);
        tOverLabel->setObjectName(QStringLiteral("tOverLabel"));
        tOverLabel->setGeometry(QRect(145, 215, 35, 20));
        sizePolicy.setHeightForWidth(tOverLabel->sizePolicy().hasHeightForWidth());
        tOverLabel->setSizePolicy(sizePolicy);
        tOverLabel->setFont(font);
        tOverLabel->setLayoutDirection(Qt::LeftToRight);
        tOverLabel->setAutoFillBackground(false);
        tOverLabel->setFrameShape(QFrame::Panel);
        tOverLabel->setFrameShadow(QFrame::Sunken);
        tOverLabel->setTextFormat(Qt::AutoText);
        tOverLabel->setScaledContents(false);
        tOverLabel->setAlignment(Qt::AlignCenter);
        tOverLabel->setWordWrap(false);
        tOverLabel->setMargin(0);
        tOverLabel->setIndent(-1);
        klokLabel = new QLabel(Venster);
        klokLabel->setObjectName(QStringLiteral("klokLabel"));
        klokLabel->setGeometry(QRect(110, 210, 30, 30));
        sizePolicy.setHeightForWidth(klokLabel->sizePolicy().hasHeightForWidth());
        klokLabel->setSizePolicy(sizePolicy);
        klokLabel->setLineWidth(0);
        klokLabel->setPixmap(QPixmap(QString::fromUtf8("img/klok.png")));
        grootteLabel = new QLabel(Venster);
        grootteLabel->setObjectName(QStringLiteral("grootteLabel"));
        grootteLabel->setGeometry(QRect(220, 20, 60, 15));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        grootteLabel->setFont(font1);
        kleinLabel = new QRadioButton(Venster);
        kleinLabel->setObjectName(QStringLiteral("kleinLabel"));
        kleinLabel->setGeometry(QRect(220, 50, 90, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        kleinLabel->setFont(font2);
        kleinLabel->setChecked(true);
        medLabel = new QRadioButton(Venster);
        medLabel->setObjectName(QStringLiteral("medLabel"));
        medLabel->setGeometry(QRect(220, 110, 101, 50));
        medLabel->setFont(font2);
        grootLabel = new QRadioButton(Venster);
        grootLabel->setObjectName(QStringLiteral("grootLabel"));
        grootLabel->setGeometry(QRect(220, 170, 101, 50));
        grootLabel->setFont(font2);
        aangLabel = new QRadioButton(Venster);
        aangLabel->setObjectName(QStringLiteral("aangLabel"));
        aangLabel->setGeometry(QRect(350, 50, 90, 20));
        aangLabel->setFont(font2);
        hoogteLabel = new QLabel(Venster);
        hoogteLabel->setObjectName(QStringLiteral("hoogteLabel"));
        hoogteLabel->setEnabled(true);
        hoogteLabel->setGeometry(QRect(375, 75, 80, 20));
        hoogteLabel->setFont(font2);
        hoogteEdit = new QLineEdit(Venster);
        hoogteEdit->setObjectName(QStringLiteral("hoogteEdit"));
        hoogteEdit->setEnabled(true);
        hoogteEdit->setGeometry(QRect(460, 75, 30, 20));
        hoogteEdit->setFont(font2);
        hoogteEdit->setMaxLength(2);
        hoogteEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        breedteEdit = new QLineEdit(Venster);
        breedteEdit->setObjectName(QStringLiteral("breedteEdit"));
        breedteEdit->setEnabled(true);
        breedteEdit->setGeometry(QRect(460, 100, 30, 20));
        breedteEdit->setFont(font2);
        breedteEdit->setMaxLength(2);
        breedteEdit->setFrame(true);
        breedteEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        breedteLabel = new QLabel(Venster);
        breedteLabel->setObjectName(QStringLiteral("breedteLabel"));
        breedteLabel->setEnabled(true);
        breedteLabel->setGeometry(QRect(375, 100, 80, 20));
        breedteLabel->setFont(font2);
        mijnenEdit = new QLineEdit(Venster);
        mijnenEdit->setObjectName(QStringLiteral("mijnenEdit"));
        mijnenEdit->setEnabled(true);
        mijnenEdit->setGeometry(QRect(460, 125, 30, 20));
        mijnenEdit->setFont(font2);
        mijnenEdit->setMaxLength(3);
        mijnenEdit->setFrame(true);
        mijnenEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mijnenLabel = new QLabel(Venster);
        mijnenLabel->setObjectName(QStringLiteral("mijnenLabel"));
        mijnenLabel->setEnabled(true);
        mijnenLabel->setGeometry(QRect(375, 125, 80, 20));
        mijnenLabel->setFont(font2);
        grootteBtn = new QPushButton(Venster);
        grootteBtn->setObjectName(QStringLiteral("grootteBtn"));
        grootteBtn->setGeometry(QRect(385, 195, 75, 25));

        retranslateUi(Venster);
        QObject::connect(hoogteEdit, SIGNAL(returnPressed()), breedteEdit, SLOT(setFocus()));
        QObject::connect(breedteEdit, SIGNAL(returnPressed()), mijnenEdit, SLOT(setFocus()));
        QObject::connect(hoogteEdit, SIGNAL(textChanged(QString)), aangLabel, SLOT(toggle()));
        QObject::connect(breedteEdit, SIGNAL(textChanged(QString)), aangLabel, SLOT(toggle()));
        QObject::connect(mijnenEdit, SIGNAL(textChanged(QString)), aangLabel, SLOT(toggle()));
        QObject::connect(hoogteEdit, SIGNAL(returnPressed()), breedteEdit, SLOT(selectAll()));
        QObject::connect(breedteEdit, SIGNAL(returnPressed()), mijnenEdit, SLOT(selectAll()));

        QMetaObject::connectSlotsByName(Venster);
    } // setupUi

    void retranslateUi(QDialog *Venster)
    {
        Venster->setWindowTitle(QApplication::translate("Venster", "Minesweeper", 0));
        mijnbLabel->setText(QString());
        mOverLabel->setText(QString());
        tOverLabel->setText(QString());
        klokLabel->setText(QString());
        grootteLabel->setText(QApplication::translate("Venster", "Size", 0));
        kleinLabel->setText(QApplication::translate("Venster", "&Small\n"
"10 mines\n"
"9x9 squares", 0));
        medLabel->setText(QApplication::translate("Venster", "&Medium\n"
"40 mines\n"
"16x16 squares", 0));
        grootLabel->setText(QApplication::translate("Venster", "&Large\n"
"99 mines\n"
"16x30 squares", 0));
        aangLabel->setText(QApplication::translate("Venster", "&Custom:", 0));
        hoogteLabel->setText(QApplication::translate("Venster", "Height (9-24):", 0));
        hoogteEdit->setInputMask(QApplication::translate("Venster", "##", 0));
        hoogteEdit->setText(QString());
        breedteEdit->setInputMask(QApplication::translate("Venster", "##", 0));
        breedteEdit->setText(QString());
        breedteLabel->setText(QApplication::translate("Venster", "Width (9-30):", 0));
        mijnenEdit->setInputMask(QApplication::translate("Venster", "###", 0));
        mijnenEdit->setText(QString());
        mijnenLabel->setText(QApplication::translate("Venster", "Mines", 0));
        grootteBtn->setText(QApplication::translate("Venster", "&Start", 0));
    } // retranslateUi

};

namespace Ui {
    class Venster: public Ui_Venster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
