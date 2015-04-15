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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    QWidget *editWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *editLayout;
    QWidget *wrapperContentWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *contentLayout;
    QWidget *ContentWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *mainView;
    QWidget *sideBarWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *sideBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(800, 500);
        MainWindow->setMinimumSize(QSize(800, 500));
        MainWindow->setFocusPolicy(Qt::WheelFocus);
        MainWindow->setWindowOpacity(1);
        MainWindow->setStyleSheet(QLatin1String("QToolBar.EditToolBar {\n"
"  border-bottom: 1px solid rgb(227, 227, 227);\n"
"  background-color: rgba(255, 255, 255, 0.75);\n"
"}\n"
"\n"
"QWidget#mainWidget{\n"
"	  background-color: #efefef;\n"
"\n"
"}"));
        MainWindow->setTabShape(QTabWidget::Rounded);
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
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        editWidget = new QWidget(mainWidget);
        editWidget->setObjectName(QStringLiteral("editWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editWidget->sizePolicy().hasHeightForWidth());
        editWidget->setSizePolicy(sizePolicy1);
        editWidget->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(editWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        editLayout = new QVBoxLayout();
        editLayout->setSpacing(6);
        editLayout->setObjectName(QStringLiteral("editLayout"));
        editLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        editLayout->setContentsMargins(-1, -1, -1, 0);

        verticalLayout_3->addLayout(editLayout);


        verticalLayout->addWidget(editWidget, 0, Qt::AlignTop);

        wrapperContentWidget = new QWidget(mainWidget);
        wrapperContentWidget->setObjectName(QStringLiteral("wrapperContentWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wrapperContentWidget->sizePolicy().hasHeightForWidth());
        wrapperContentWidget->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(wrapperContentWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        contentLayout = new QHBoxLayout();
        contentLayout->setSpacing(6);
        contentLayout->setObjectName(QStringLiteral("contentLayout"));
        ContentWidget = new QWidget(wrapperContentWidget);
        ContentWidget->setObjectName(QStringLiteral("ContentWidget"));
        horizontalLayout = new QHBoxLayout(ContentWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mainView = new QVBoxLayout();
        mainView->setSpacing(0);
        mainView->setObjectName(QStringLiteral("mainView"));

        horizontalLayout->addLayout(mainView);

        sideBarWidget = new QWidget(ContentWidget);
        sideBarWidget->setObjectName(QStringLiteral("sideBarWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sideBarWidget->sizePolicy().hasHeightForWidth());
        sideBarWidget->setSizePolicy(sizePolicy3);
        sideBarWidget->setMinimumSize(QSize(300, 0));
        sideBarWidget->setAutoFillBackground(false);
        sideBarWidget->setStyleSheet(QLatin1String("QWidget#sideBarWidget{\n"
"	background-image: url(:/design/design/ui_blur.png);\n"
"	background-position: center center;\n"
"  	border-left: 1px solid rgb(227, 227, 227);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(sideBarWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 0, 0, 0);
        sideBar = new QVBoxLayout();
        sideBar->setSpacing(6);
        sideBar->setObjectName(QStringLiteral("sideBar"));

        verticalLayout_5->addLayout(sideBar);


        horizontalLayout->addWidget(sideBarWidget);


        contentLayout->addWidget(ContentWidget);


        verticalLayout_2->addLayout(contentLayout);


        verticalLayout->addWidget(wrapperContentWidget);


        gridLayout_2->addWidget(mainWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy4);
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

        mainToolBar->addAction(actionGoToTask);
        mainToolBar->addAction(actionGoToCal);
        mainToolBar->addAction(actionGoToResume);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ProAgenda", 0));
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
