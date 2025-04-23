/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_height;
    QLabel *label_weight;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLabel *label_result;
    QPushButton *pushButton_result;
    QLabel *label_2;
    QLabel *label_height1;
    QLabel *label_weight1;
    QLabel *label_gender;
    QLabel *label_ill;
    QGroupBox *groupBox_system;
    QRadioButton *radioButton_european;
    QRadioButton *radioButton_american;
    QGroupBox *groupBox_gender;
    QRadioButton *radioButton_female;
    QRadioButton *radioButton_male;
    QGroupBox *groupBox_ill;
    QRadioButton *radioButton_chr;
    QRadioButton *radioButton_chrno;
    QLabel *label_age;
    QLineEdit *lineEdit_age;
    QLabel *label_level;
    QComboBox *comboBox_activity;
    QWidget *chartWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_import;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_height = new QLabel(centralwidget);
        label_height->setObjectName("label_height");
        label_height->setGeometry(QRect(40, 30, 63, 20));
        label_weight = new QLabel(centralwidget);
        label_weight->setObjectName("label_weight");
        label_weight->setGeometry(QRect(40, 60, 63, 20));
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName("lineEdit_1");
        lineEdit_1->setGeometry(QRect(120, 30, 113, 26));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 60, 113, 26));
        label_result = new QLabel(centralwidget);
        label_result->setObjectName("label_result");
        label_result->setGeometry(QRect(20, 210, 71, 20));
        pushButton_result = new QPushButton(centralwidget);
        pushButton_result->setObjectName("pushButton_result");
        pushButton_result->setGeometry(QRect(100, 210, 93, 29));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(560, 10, 211, 20));
        label_height1 = new QLabel(centralwidget);
        label_height1->setObjectName("label_height1");
        label_height1->setGeometry(QRect(240, 30, 51, 20));
        label_weight1 = new QLabel(centralwidget);
        label_weight1->setObjectName("label_weight1");
        label_weight1->setGeometry(QRect(240, 60, 31, 20));
        label_gender = new QLabel(centralwidget);
        label_gender->setObjectName("label_gender");
        label_gender->setGeometry(QRect(40, 90, 63, 20));
        label_ill = new QLabel(centralwidget);
        label_ill->setObjectName("label_ill");
        label_ill->setGeometry(QRect(40, 170, 231, 20));
        groupBox_system = new QGroupBox(centralwidget);
        groupBox_system->setObjectName("groupBox_system");
        groupBox_system->setGeometry(QRect(560, 30, 161, 81));
        groupBox_system->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        radioButton_european = new QRadioButton(groupBox_system);
        radioButton_european->setObjectName("radioButton_european");
        radioButton_european->setGeometry(QRect(10, 10, 131, 24));
        radioButton_european->setChecked(false);
        radioButton_european->setAutoExclusive(false);
        radioButton_american = new QRadioButton(groupBox_system);
        radioButton_american->setObjectName("radioButton_american");
        radioButton_american->setGeometry(QRect(10, 40, 131, 24));
        groupBox_gender = new QGroupBox(centralwidget);
        groupBox_gender->setObjectName("groupBox_gender");
        groupBox_gender->setGeometry(QRect(110, 80, 211, 41));
        groupBox_gender->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        radioButton_female = new QRadioButton(groupBox_gender);
        radioButton_female->setObjectName("radioButton_female");
        radioButton_female->setGeometry(QRect(10, 10, 110, 24));
        radioButton_male = new QRadioButton(groupBox_gender);
        radioButton_male->setObjectName("radioButton_male");
        radioButton_male->setGeometry(QRect(110, 10, 110, 24));
        groupBox_ill = new QGroupBox(centralwidget);
        groupBox_ill->setObjectName("groupBox_ill");
        groupBox_ill->setGeometry(QRect(270, 150, 121, 51));
        groupBox_ill->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        radioButton_chr = new QRadioButton(groupBox_ill);
        radioButton_chr->setObjectName("radioButton_chr");
        radioButton_chr->setGeometry(QRect(10, 20, 51, 24));
        radioButton_chrno = new QRadioButton(groupBox_ill);
        radioButton_chrno->setObjectName("radioButton_chrno");
        radioButton_chrno->setGeometry(QRect(60, 20, 61, 24));
        label_age = new QLabel(centralwidget);
        label_age->setObjectName("label_age");
        label_age->setGeometry(QRect(40, 130, 63, 20));
        lineEdit_age = new QLineEdit(centralwidget);
        lineEdit_age->setObjectName("lineEdit_age");
        lineEdit_age->setGeometry(QRect(120, 130, 113, 26));
        label_level = new QLabel(centralwidget);
        label_level->setObjectName("label_level");
        label_level->setGeometry(QRect(540, 110, 241, 20));
        comboBox_activity = new QComboBox(centralwidget);
        comboBox_activity->addItem(QString());
        comboBox_activity->addItem(QString());
        comboBox_activity->addItem(QString());
        comboBox_activity->setObjectName("comboBox_activity");
        comboBox_activity->setGeometry(QRect(570, 140, 121, 26));
        chartWidget = new QWidget(centralwidget);
        chartWidget->setObjectName("chartWidget");
        chartWidget->setGeometry(QRect(890, 450, 21, 20));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 310, 761, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName("pushButton_save");
        pushButton_save->setGeometry(QRect(400, 210, 161, 29));
        pushButton_import = new QPushButton(centralwidget);
        pushButton_import->setObjectName("pushButton_import");
        pushButton_import->setGeometry(QRect(200, 210, 191, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 250, 221, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_height->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\321\201\321\202", nullptr));
        label_weight->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\201", nullptr));
        label_result->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        pushButton_result->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\201\320\270\321\201\321\202\320\265\320\274\321\213 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217:", nullptr));
        label_height1->setText(QString());
        label_weight1->setText(QString());
        label_gender->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273", nullptr));
        label_ill->setText(QCoreApplication::translate("MainWindow", "\320\225\321\201\321\202\321\214 \321\205\321\200\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\267\320\260\320\261\320\276\320\273\320\265\320\262\320\260\320\275\320\270\321\217?", nullptr));
        groupBox_system->setTitle(QString());
        radioButton_european->setText(QCoreApplication::translate("MainWindow", "\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\260\321\217", nullptr));
        radioButton_american->setText(QCoreApplication::translate("MainWindow", "\320\260\320\274\320\265\321\200\320\270\320\272\320\260\320\275\321\201\320\272\320\260\321\217", nullptr));
        groupBox_gender->setTitle(QString());
        radioButton_female->setText(QCoreApplication::translate("MainWindow", "\320\226\320\265\320\275\321\201\320\272\320\270\320\271", nullptr));
        radioButton_male->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\266\321\201\320\272\320\276\320\271", nullptr));
        groupBox_ill->setTitle(QString());
        radioButton_chr->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260", nullptr));
        radioButton_chrno->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        label_age->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        label_level->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \321\204\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\320\270:", nullptr));
        comboBox_activity->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\270\320\267\320\272\320\270\320\271", nullptr));
        comboBox_activity->setItemText(1, QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));
        comboBox_activity->setItemText(2, QCoreApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\320\272\320\270\320\271", nullptr));

        pushButton_save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        pushButton_import->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
