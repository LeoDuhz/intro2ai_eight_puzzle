/********************************************************************************
** Form generated from reading UI file 'aboutus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTUS_H
#define UI_ABOUTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aboutus
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *aboutus)
    {
        if (aboutus->objectName().isEmpty())
            aboutus->setObjectName(QString::fromUtf8("aboutus"));
        aboutus->resize(580, 274);
        label = new QLabel(aboutus);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 281, 17));
        label_2 = new QLabel(aboutus);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 281, 17));
        label_3 = new QLabel(aboutus);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 100, 431, 17));
        label_4 = new QLabel(aboutus);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 140, 361, 17));
        pushButton = new QPushButton(aboutus);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 190, 89, 25));

        retranslateUi(aboutus);

        QMetaObject::connectSlotsByName(aboutus);
    } // setupUi

    void retranslateUi(QDialog *aboutus)
    {
        aboutus->setWindowTitle(QCoreApplication::translate("aboutus", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("aboutus", "\345\205\253\346\225\260\347\240\201\351\227\256\351\242\230\346\261\202\350\247\243-\344\272\272\345\267\245\346\231\272\350\203\275\346\246\202\350\256\272\345\244\247\344\275\234\344\270\232", nullptr));
        label_2->setText(QCoreApplication::translate("aboutus", "Author: \346\235\234\346\265\251\345\223\262 \344\275\225\350\212\235\345\217\266 \346\235\216\346\230\212\351\242\226 \345\274\240\345\255\220\345\201\245", nullptr));
        label_3->setText(QCoreApplication::translate("aboutus", "Github Repository: https://github.com/LeoDuhz/intro2ai", nullptr));
        label_4->setText(QCoreApplication::translate("aboutus", "Contact us: hzdu0915@gmail.com", nullptr));
        pushButton->setText(QCoreApplication::translate("aboutus", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutus: public Ui_aboutus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTUS_H
