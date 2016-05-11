/********************************************************************************
** Form generated from reading UI file 'UnitTest.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITTEST_H
#define UI_UNITTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UnitTestClass
{
public:
    QPushButton *m_btnUqerAccess;

    void setupUi(QDialog *UnitTestClass)
    {
        if (UnitTestClass->objectName().isEmpty())
            UnitTestClass->setObjectName(QStringLiteral("UnitTestClass"));
        UnitTestClass->resize(420, 255);
        m_btnUqerAccess = new QPushButton(UnitTestClass);
        m_btnUqerAccess->setObjectName(QStringLiteral("m_btnUqerAccess"));
        m_btnUqerAccess->setGeometry(QRect(10, 10, 75, 23));
        m_btnUqerAccess->setAutoDefault(false);

        retranslateUi(UnitTestClass);
        QObject::connect(m_btnUqerAccess, SIGNAL(clicked()), UnitTestClass, SLOT(slot_BtnUqerAccess()));

        QMetaObject::connectSlotsByName(UnitTestClass);
    } // setupUi

    void retranslateUi(QDialog *UnitTestClass)
    {
        UnitTestClass->setWindowTitle(QApplication::translate("UnitTestClass", "UnitTest", 0));
        m_btnUqerAccess->setText(QApplication::translate("UnitTestClass", "\344\274\230\347\237\277\346\225\260\346\215\256\346\272\220", 0));
    } // retranslateUi

};

namespace Ui {
    class UnitTestClass: public Ui_UnitTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITTEST_H
