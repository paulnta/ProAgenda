/********************************************************************************
** Form generated from reading UI file 'testcalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCALENDAR_H
#define UI_TESTCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestCalendar
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *gridCalendar;
    QPushButton *pushButton;

    void setupUi(QWidget *TestCalendar)
    {
        if (TestCalendar->objectName().isEmpty())
            TestCalendar->setObjectName(QStringLiteral("TestCalendar"));
        TestCalendar->resize(339, 535);
        gridLayout_2 = new QGridLayout(TestCalendar);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(12, 30, -1, -1);
        gridCalendar = new QFormLayout();
        gridCalendar->setObjectName(QStringLiteral("gridCalendar"));
        gridCalendar->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        gridCalendar->setLabelAlignment(Qt::AlignCenter);
        gridCalendar->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        gridCalendar->setHorizontalSpacing(0);
        gridCalendar->setVerticalSpacing(0);
        gridCalendar->setContentsMargins(0, -1, 0, -1);
        pushButton = new QPushButton(TestCalendar);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridCalendar->setWidget(0, QFormLayout::LabelRole, pushButton);


        gridLayout_2->addLayout(gridCalendar, 0, 0, 1, 1);


        retranslateUi(TestCalendar);

        QMetaObject::connectSlotsByName(TestCalendar);
    } // setupUi

    void retranslateUi(QWidget *TestCalendar)
    {
        TestCalendar->setWindowTitle(QApplication::translate("TestCalendar", "Form", 0));
        pushButton->setText(QApplication::translate("TestCalendar", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class TestCalendar: public Ui_TestCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCALENDAR_H
