/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QStringLiteral("TestWidget"));
        TestWidget->resize(545, 401);
        horizontalLayout_2 = new QHBoxLayout(TestWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(TestWidget);
        widget->setObjectName(QStringLiteral("widget"));
        formLayout_2 = new QFormLayout(widget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEdit_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_2);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, dateEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, pushButton);


        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "Form", 0));
        label->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        label_2->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        label_3->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        pushButton->setText(QApplication::translate("TestWidget", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
