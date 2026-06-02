/********************************************************************************
** Form generated from reading UI file 'udpfieldswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPFIELDSWIDGET_H
#define UI_UDPFIELDSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UDPFieldsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBoxNrUDP;
    QWidget *containerWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayoutFields;

    void setupUi(QWidget *UDPFieldsWidget)
    {
        if (UDPFieldsWidget->objectName().isEmpty())
            UDPFieldsWidget->setObjectName("UDPFieldsWidget");
        UDPFieldsWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(UDPFieldsWidget);
        verticalLayout->setObjectName("verticalLayout");
        spinBoxNrUDP = new QSpinBox(UDPFieldsWidget);
        spinBoxNrUDP->setObjectName("spinBoxNrUDP");

        verticalLayout->addWidget(spinBoxNrUDP);

        containerWidget = new QWidget(UDPFieldsWidget);
        containerWidget->setObjectName("containerWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(containerWidget->sizePolicy().hasHeightForWidth());
        containerWidget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(containerWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayoutFields = new QVBoxLayout();
        verticalLayoutFields->setObjectName("verticalLayoutFields");

        verticalLayout_3->addLayout(verticalLayoutFields);


        verticalLayout->addWidget(containerWidget);


        retranslateUi(UDPFieldsWidget);

        QMetaObject::connectSlotsByName(UDPFieldsWidget);
    } // setupUi

    void retranslateUi(QWidget *UDPFieldsWidget)
    {
        UDPFieldsWidget->setWindowTitle(QCoreApplication::translate("UDPFieldsWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UDPFieldsWidget: public Ui_UDPFieldsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPFIELDSWIDGET_H
