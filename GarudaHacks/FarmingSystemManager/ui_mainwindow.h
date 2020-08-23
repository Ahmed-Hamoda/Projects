/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCalendarWidget *calendarWidget;
    QLabel *label_27;
    QLabel *label_28;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *urgentTaskTable;
    QTableWidget *regularTaskTable;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QWidget *tab_3;
    QTableWidget *invtable;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *PayEmpButton_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEditName;
    QLineEdit *lineEditQuant;
    QLineEdit *lineEditPrice;
    QVBoxLayout *verticalLayout_3;
    QPushButton *invButton;
    QWidget *tab_2;
    QPushButton *PayEmpButton;
    QTableWidget *payrolltable;
    QLabel *label_10;
    QLabel *label_17;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *lineEditEmployee;
    QLineEdit *lineEditSalary;
    QLineEdit *lineEditHours;
    QPushButton *payButton_3;
    QWidget *tab_4;
    QPushButton *clearButton;
    QLabel *label_23;
    QLabel *label_24;
    QTableWidget *tasktable;
    QPushButton *pushButton_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_25;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEditUrgent;
    QPushButton *urgentButton;
    QLabel *label_26;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(859, 745);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 80, 811, 611));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        calendarWidget = new QCalendarWidget(tab);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setEnabled(true);
        calendarWidget->setGeometry(QRect(515, 0, 281, 181));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(8);
        calendarWidget->setFont(font1);
        calendarWidget->setCursor(QCursor(Qt::ArrowCursor));
        calendarWidget->setGridVisible(false);
        label_27 = new QLabel(tab);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 20, 211, 41));
        QFont font2;
        font2.setPointSize(20);
        label_27->setFont(font2);
        label_28 = new QLabel(tab);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 60, 451, 121));
        QFont font3;
        font3.setPointSize(9);
        label_28->setFont(font3);
        label_28->setWordWrap(true);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 180, 441, 381));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        urgentTaskTable = new QTableWidget(layoutWidget);
        if (urgentTaskTable->columnCount() < 1)
            urgentTaskTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        urgentTaskTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        urgentTaskTable->setObjectName(QString::fromUtf8("urgentTaskTable"));

        horizontalLayout_3->addWidget(urgentTaskTable);

        regularTaskTable = new QTableWidget(layoutWidget);
        if (regularTaskTable->columnCount() < 1)
            regularTaskTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        regularTaskTable->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        regularTaskTable->setObjectName(QString::fromUtf8("regularTaskTable"));

        horizontalLayout_3->addWidget(regularTaskTable);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 210, 181, 181));
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/kambo/OneDrive/Desktop/clear.png")));
        label->setScaledContents(true);
        lcdNumber = new QLCDNumber(tab);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(440, 380, 291, 141));
        lcdNumber->setLineWidth(0);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("intValue", QVariant(31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(740, 390, 41, 51));
        QFont font4;
        font4.setPointSize(36);
        label_2->setFont(font4);
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        invtable = new QTableWidget(tab_3);
        if (invtable->columnCount() < 5)
            invtable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        invtable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        invtable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        invtable->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        invtable->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        invtable->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        invtable->setObjectName(QString::fromUtf8("invtable"));
        invtable->setGeometry(QRect(0, 220, 801, 281));
        sizePolicy.setHeightForWidth(invtable->sizePolicy().hasHeightForWidth());
        invtable->setSizePolicy(sizePolicy);
        invtable->setLayoutDirection(Qt::LeftToRight);
        invtable->setRowCount(0);
        invtable->setColumnCount(5);
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 70, 411, 121));
        QFont font5;
        font5.setPointSize(10);
        label_18->setFont(font5);
        label_18->setWordWrap(true);
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 20, 211, 41));
        label_19->setFont(font2);
        PayEmpButton_2 = new QPushButton(tab_3);
        PayEmpButton_2->setObjectName(QString::fromUtf8("PayEmpButton_2"));
        PayEmpButton_2->setGeometry(QRect(280, 510, 161, 31));
        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(460, 50, 313, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font6;
        font6.setPointSize(12);
        label_3->setFont(font6);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lineEditName = new QLineEdit(layoutWidget1);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        verticalLayout_6->addWidget(lineEditName);

        lineEditQuant = new QLineEdit(layoutWidget1);
        lineEditQuant->setObjectName(QString::fromUtf8("lineEditQuant"));

        verticalLayout_6->addWidget(lineEditQuant);

        lineEditPrice = new QLineEdit(layoutWidget1);
        lineEditPrice->setObjectName(QString::fromUtf8("lineEditPrice"));

        verticalLayout_6->addWidget(lineEditPrice);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        invButton = new QPushButton(layoutWidget1);
        invButton->setObjectName(QString::fromUtf8("invButton"));

        verticalLayout_3->addWidget(invButton);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_5);


        verticalLayout_2->addLayout(verticalLayout_7);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        PayEmpButton = new QPushButton(tab_2);
        PayEmpButton->setObjectName(QString::fromUtf8("PayEmpButton"));
        PayEmpButton->setGeometry(QRect(320, 510, 101, 31));
        payrolltable = new QTableWidget(tab_2);
        if (payrolltable->columnCount() < 5)
            payrolltable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        payrolltable->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        payrolltable->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        payrolltable->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        payrolltable->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        payrolltable->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        payrolltable->setObjectName(QString::fromUtf8("payrolltable"));
        payrolltable->setGeometry(QRect(0, 220, 801, 281));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(payrolltable->sizePolicy().hasHeightForWidth());
        payrolltable->setSizePolicy(sizePolicy1);
        payrolltable->setGridStyle(Qt::SolidLine);
        payrolltable->horizontalHeader()->setCascadingSectionResizes(true);
        payrolltable->horizontalHeader()->setStretchLastSection(false);
        payrolltable->verticalHeader()->setCascadingSectionResizes(false);
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 20, 181, 41));
        label_10->setFont(font2);
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 70, 411, 121));
        label_17->setFont(font5);
        label_17->setWordWrap(true);
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(459, 50, 311, 159));
        verticalLayout_9 = new QVBoxLayout(layoutWidget2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_8->addWidget(label_11);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_8->addWidget(label_12);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_8->addWidget(label_13);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        lineEditEmployee = new QLineEdit(layoutWidget2);
        lineEditEmployee->setObjectName(QString::fromUtf8("lineEditEmployee"));

        verticalLayout_12->addWidget(lineEditEmployee);

        lineEditSalary = new QLineEdit(layoutWidget2);
        lineEditSalary->setObjectName(QString::fromUtf8("lineEditSalary"));

        verticalLayout_12->addWidget(lineEditSalary);

        lineEditHours = new QLineEdit(layoutWidget2);
        lineEditHours->setObjectName(QString::fromUtf8("lineEditHours"));

        verticalLayout_12->addWidget(lineEditHours);


        horizontalLayout_2->addLayout(verticalLayout_12);


        horizontalLayout->addLayout(horizontalLayout_2);

        payButton_3 = new QPushButton(layoutWidget2);
        payButton_3->setObjectName(QString::fromUtf8("payButton_3"));

        horizontalLayout->addWidget(payButton_3);


        verticalLayout_9->addLayout(horizontalLayout);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        clearButton = new QPushButton(tab_4);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(660, 500, 141, 45));
        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(20, 20, 271, 41));
        label_23->setFont(font2);
        label_24 = new QLabel(tab_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 70, 411, 141));
        label_24->setFont(font3);
        label_24->setWordWrap(true);
        tasktable = new QTableWidget(tab_4);
        if (tasktable->columnCount() < 3)
            tasktable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tasktable->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tasktable->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tasktable->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        tasktable->setObjectName(QString::fromUtf8("tasktable"));
        tasktable->setGeometry(QRect(0, 220, 801, 281));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 500, 231, 45));
        layoutWidget3 = new QWidget(tab_4);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(460, 50, 311, 162));
        verticalLayout_10 = new QVBoxLayout(layoutWidget3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(layoutWidget3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_25);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineEdit = new QLineEdit(layoutWidget3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEditUrgent = new QLineEdit(layoutWidget3);
        lineEditUrgent->setObjectName(QString::fromUtf8("lineEditUrgent"));

        horizontalLayout_8->addWidget(lineEditUrgent);


        verticalLayout->addLayout(horizontalLayout_8);

        urgentButton = new QPushButton(layoutWidget3);
        urgentButton->setObjectName(QString::fromUtf8("urgentButton"));

        verticalLayout->addWidget(urgentButton);


        verticalLayout_10->addLayout(verticalLayout);

        tabWidget->addTab(tab_4, QString());
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(350, 20, 147, 54));
        label_26->setPixmap(QPixmap(QString::fromUtf8("icons/sproutlogo.png")));
        label_26->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 859, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(invButton, SIGNAL(clicked()), invtable, SLOT(update()));
        QObject::connect(payButton_3, SIGNAL(clicked()), payrolltable, SLOT(update()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Welcome to Sprout System Management! Current weather is visible on the bottom right. Your pending urgent tasks and regular tasks are below. Click the Inventory, Payroll or Task Manager tabs to navigate through the application.", nullptr));
        QTableWidgetItem *___qtablewidgetitem = urgentTaskTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Urgent Tasks", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = regularTaskTable->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Regular Tasks", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Home", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = invtable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = invtable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = invtable->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Unit Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = invtable->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Total Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = invtable->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "To add an item to your inventory, fill out the fields on the right and click \"ADD\". It will appear in the table below. To remove an item from the inventory, simply check the \"Remove\" column and click the \"Remove Item(s)\" button at the bottom.", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Inventory", nullptr));
        PayEmpButton_2->setText(QCoreApplication::translate("MainWindow", "Remove Item(s)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Add an Item:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Item Name:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Quantity:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Value:", nullptr));
        invButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Inventory", nullptr));
        PayEmpButton->setText(QCoreApplication::translate("MainWindow", "Pay", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = payrolltable->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Employee", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = payrolltable->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Salary", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = payrolltable->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Hours", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = payrolltable->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Balance Owed", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = payrolltable->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "To Pay", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Payroll", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Fill out the fields on the right (name, hourly rate and hours) to add an employee. On payday, simply click the pay button (after paying your employees) to set hours and balance owed to 0.", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Add an Employee:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Rate:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Hours:", nullptr));
        payButton_3->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Payroll", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear All Tasks", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Task Manager", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Fill out the fields on the right to add a task (don't forget to assign its urgency). The task will appear in the table below and on the Home Screen in the location respective to its urgency. If you wish to remove a task(s), check the \"remove\" column and click the \"Remove Selected Tasks\" button at the bottom. To remove all tasks from the home screen and the table, click \"Clear All Tasks\".", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tasktable->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Task Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tasktable->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Urgency", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tasktable->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Remove Selected Tasks", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Add a Task:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Task Name:   ", nullptr));
        lineEdit->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Urgent (Y/N):", nullptr));
        urgentButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Task Manager", nullptr));
        label_26->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
