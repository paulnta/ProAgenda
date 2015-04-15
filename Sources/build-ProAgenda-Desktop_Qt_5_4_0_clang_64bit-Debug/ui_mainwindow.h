/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddTask;
    QAction *actionGoToTask;
    QAction *actionGoToCal;
    QAction *actionGoToResume;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *centralGridLayout;
    QWidget *editWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *editLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(704, 531);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        actionAddTask = new QAction(MainWindow);
        actionAddTask->setObjectName(QStringLiteral("actionAddTask"));
        actionAddTask->setCheckable(false);
        actionAddTask->setChecked(false);
        QIcon icon;
        QString iconThemeName = QStringLiteral("test");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/icons/img/icons/ic_add_to_photos_48px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAddTask->setIcon(icon);
        actionAddTask->setPriority(QAction::HighPriority);
        actionGoToTask = new QAction(MainWindow);
        actionGoToTask->setObjectName(QStringLiteral("actionGoToTask"));
        actionGoToTask->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/img/icons/task@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGoToTask->setIcon(icon1);
        actionGoToCal = new QAction(MainWindow);
        actionGoToCal->setObjectName(QStringLiteral("actionGoToCal"));
        actionGoToCal->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/img/icons/ic_today_48px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionGoToCal->setIcon(icon2);
        actionGoToResume = new QAction(MainWindow);
        actionGoToResume->setObjectName(QStringLiteral("actionGoToResume"));
        actionGoToResume->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/img/icons/ic_account_balance_48px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionGoToResume->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        centralGridLayout = new QGridLayout();
        centralGridLayout->setSpacing(6);
        centralGridLayout->setObjectName(QStringLiteral("centralGridLayout"));
        centralGridLayout->setContentsMargins(-1, 0, -1, -1);
        editWidget = new QWidget(centralWidget);
        editWidget->setObjectName(QStringLiteral("editWidget"));
        verticalLayout_3 = new QVBoxLayout(editWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        editLayout = new QVBoxLayout();
        editLayout->setSpacing(6);
        editLayout->setObjectName(QStringLiteral("editLayout"));
        editLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_3->addLayout(editLayout);


        centralGridLayout->addWidget(editWidget, 1, 0, 1, 1, Qt::AlignTop);


        gridLayout_2->addLayout(centralGridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 704, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setMaximumSize(QSize(16777215, 16777215));
        mainToolBar->setCursor(QCursor(Qt::ArrowCursor));
        mainToolBar->setMouseTracking(true);
        mainToolBar->setFocusPolicy(Qt::ClickFocus);
        mainToolBar->setAcceptDrops(false);
        mainToolBar->setLayoutDirection(Qt::LeftToRight);
        mainToolBar->setAutoFillBackground(true);
        mainToolBar->setStyleSheet(QStringLiteral(""));
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(30, 30));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionGoToTask);
        mainToolBar->addAction(actionGoToCal);
        mainToolBar->addAction(actionGoToResume);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAddTask->setText(QApplication::translate("MainWindow", "AddTask", 0));
        actionAddTask->setIconText(QApplication::translate("MainWindow", "Ajouter t\303\242che", 0));
#ifndef QT_NO_TOOLTIP
        actionAddTask->setToolTip(QApplication::translate("MainWindow", "Ajouter une t\303\242che", 0));
#endif // QT_NO_TOOLTIP
        actionAddTask->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionGoToTask->setText(QApplication::translate("MainWindow", "T\303\242ches", 0));
        actionGoToTask->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", 0));
        actionGoToCal->setText(QApplication::translate("MainWindow", "Calendrier", 0));
        actionGoToCal->setShortcut(QApplication::translate("MainWindow", "Ctrl+2", 0));
        actionGoToResume->setText(QApplication::translate("MainWindow", "R\303\251sum\303\251", 0));
        actionGoToResume->setShortcut(QApplication::translate("MainWindow", "Ctrl+3", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
