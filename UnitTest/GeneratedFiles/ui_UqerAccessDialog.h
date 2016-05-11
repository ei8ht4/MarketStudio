/********************************************************************************
** Form generated from reading UI file 'UqerAccessDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UQERACCESSDIALOG_H
#define UI_UQERACCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CUqerAccessDialog
{
public:
    QLineEdit *m_editToken;
    QLabel *m_labelToken;
    QLabel *m_labelUrl;
    QLineEdit *m_editURL;
    QTextEdit *m_editReply;
    QPushButton *m_btnGetData;

    void setupUi(QDialog *CUqerAccessDialog)
    {
        if (CUqerAccessDialog->objectName().isEmpty())
            CUqerAccessDialog->setObjectName(QStringLiteral("CUqerAccessDialog"));
        CUqerAccessDialog->resize(676, 447);
        m_editToken = new QLineEdit(CUqerAccessDialog);
        m_editToken->setObjectName(QStringLiteral("m_editToken"));
        m_editToken->setGeometry(QRect(70, 0, 411, 20));
        m_labelToken = new QLabel(CUqerAccessDialog);
        m_labelToken->setObjectName(QStringLiteral("m_labelToken"));
        m_labelToken->setGeometry(QRect(10, 10, 54, 12));
        m_labelUrl = new QLabel(CUqerAccessDialog);
        m_labelUrl->setObjectName(QStringLiteral("m_labelUrl"));
        m_labelUrl->setGeometry(QRect(10, 40, 54, 12));
        m_editURL = new QLineEdit(CUqerAccessDialog);
        m_editURL->setObjectName(QStringLiteral("m_editURL"));
        m_editURL->setGeometry(QRect(70, 40, 411, 20));
        m_editReply = new QTextEdit(CUqerAccessDialog);
        m_editReply->setObjectName(QStringLiteral("m_editReply"));
        m_editReply->setGeometry(QRect(10, 110, 651, 321));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_editReply->sizePolicy().hasHeightForWidth());
        m_editReply->setSizePolicy(sizePolicy);
        m_btnGetData = new QPushButton(CUqerAccessDialog);
        m_btnGetData->setObjectName(QStringLiteral("m_btnGetData"));
        m_btnGetData->setGeometry(QRect(200, 80, 201, 23));
#ifndef QT_NO_SHORTCUT
        m_labelToken->setBuddy(m_editToken);
        m_labelUrl->setBuddy(m_editURL);
#endif // QT_NO_SHORTCUT

        retranslateUi(CUqerAccessDialog);
        QObject::connect(m_btnGetData, SIGNAL(clicked()), CUqerAccessDialog, SLOT(slot_BtnGetDate()));

        QMetaObject::connectSlotsByName(CUqerAccessDialog);
    } // setupUi

    void retranslateUi(QDialog *CUqerAccessDialog)
    {
        CUqerAccessDialog->setWindowTitle(QApplication::translate("CUqerAccessDialog", "CUqerAccessDialog", 0));
        m_editToken->setText(QApplication::translate("CUqerAccessDialog", "4516631ff8298c847d332eb457a6fba0aa8caf6690dd640d92ce609718ab3ba1", 0));
        m_labelToken->setText(QApplication::translate("CUqerAccessDialog", "Token:", 0));
        m_labelUrl->setText(QApplication::translate("CUqerAccessDialog", "URL:", 0));
        m_btnGetData->setText(QApplication::translate("CUqerAccessDialog", "GetData", 0));
    } // retranslateUi

};

namespace Ui {
    class CUqerAccessDialog: public Ui_CUqerAccessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UQERACCESSDIALOG_H
