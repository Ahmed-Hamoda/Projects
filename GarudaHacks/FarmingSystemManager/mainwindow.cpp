#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ReqClasses.cpp"

#include <iostream>
#include <string>
#include <QTabWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtDebug>
#include <QCheckBox>
#include <QAbstractButton>

TaskManager taskManager = TaskManager();
Inventory inventory = Inventory();

QString itemName;  // item name
int itemQuant;    // item quant
float itemPrice; // item price



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createTabMenu();
    ui->payrolltable->resizeColumnsToContents();
    ui->payrolltable->resizeRowsToContents();
    ui->payrolltable->verticalHeader()->setVisible(false);
    ui->payrolltable->setShowGrid(false);

    ui->invtable->resizeColumnsToContents();
    ui->invtable->resizeRowsToContents();

    ui->urgentTaskTable->resizeRowsToContents();
    ui->urgentTaskTable->resizeColumnsToContents();
    ui->regularTaskTable->resizeRowsToContents();
    ui->regularTaskTable->resizeColumnsToContents();

    ui->tasktable->resizeColumnsToContents();
    ui->tasktable->setShowGrid(false);
    ui->tasktable->verticalHeader()->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTabMenu(){
    QTabWidget *tabs = new QTabWidget();
    tabs->addTab(new QWidget(), "TAB 1");
    tabs->addTab(new QWidget(), "TAB 2");
}

//START of Ahmed's Portion

void MainWindow::on_clearButton_clicked()
{
    clearTasks();
}

void MainWindow::storeInputString(){
    QString submittedString = ui->lineEdit->text();
    QString urgentLine = ui->lineEditUrgent->text();

    int urgency = 0;

    if (submittedString.isEmpty()) {
        return;                             //cannot insert empty text into textBrowser
    }

    if(urgentLine == "Y" || urgentLine == "y"){
        urgency = 1;                        //make it urgent
    }

    Task task = Task(submittedString);
    taskManager.addTask(task, urgency);

    return;
}

void MainWindow::on_urgentButton_clicked()
{
    storeInputString();
    displayTasks();

    ui->lineEdit->clear();
    ui->lineEditUrgent->clear();
}


int i = 0;
void MainWindow::displayTasks() {
    int taskLength = (int)taskManager.tasks.size();

    /*if (not ui->textBrowser->toPlainText().isEmpty()){
        ui->textBrowser->clear();           //clear textBrowser if not empty
    }*/

    for (int i = 0; i < taskLength; i++) {

        if (taskManager.tasks[i].second==1 && i==taskLength-1){
            displayUrgentTasks(i);

        }else if(taskManager.tasks[i].second==0 && i==taskLength-1){
            displayRegularTasks(i);

        }
        // ui->textBrowser->append(QString::number(i + 1) + ". " + taskManager.tasks[taskLength - i - 1].first.task);

        //qDebug() << taskManager.tasks[taskLength - i - 1].second;
    }

    if(ui->tasktable->rowCount() == 0){
        i = 0;
    }

    ui->tasktable->insertRow( ui->tasktable->rowCount() );
    ui->tasktable->setItem(ui->tasktable->rowCount()-1,0, new QTableWidgetItem(taskManager.tasks[i].first.task));

    if (taskManager.tasks[i].second==1){
        ui->tasktable->setItem(ui->tasktable->rowCount()-1,1, new QTableWidgetItem("Y")); //IF urgent
    } else if(taskManager.tasks[i].second==0){
        ui->tasktable->setItem(ui->tasktable->rowCount()-1,1, new QTableWidgetItem("N")); //IF not urgent
    }

    QCheckBox * cb1 = new QCheckBox();
    ui->tasktable->setCellWidget(ui->tasktable->rowCount()-1,2,cb1);
    //ui->tasktable->setCellWidget(ui->tasktable->rowCount()-1,3,cb2);
    cb1->setStyleSheet( "text-align: center; margin-left:50%; margin-right:50%;" );
    //cb2->setStyleSheet( "text-align: center; margin-left:50%; margin-right:50%;" );

    ui->tasktable->resizeColumnsToContents();
    ui->tasktable->resizeRowsToContents();
    ui->tasktable->update();
    i++;

    return;
}

void MainWindow::displayRegularTasks(int index){
    QTableWidgetItem *in = new QTableWidgetItem(taskManager.tasks[index].first.task, 0);
    ui->regularTaskTable->insertRow( ui->regularTaskTable->rowCount() );
    ui->regularTaskTable->setItem(ui->regularTaskTable->rowCount()-1,0,in);
    ui->urgentTaskTable->resizeRowsToContents();
    ui->urgentTaskTable->resizeColumnsToContents();
    ui->regularTaskTable->resizeRowsToContents();
    ui->regularTaskTable->resizeColumnsToContents();
    return;
}

void MainWindow::displayUrgentTasks(int index){
    QTableWidgetItem *in = new QTableWidgetItem(taskManager.tasks[index].first.task, 0);
    ui->urgentTaskTable->insertRow( ui->urgentTaskTable->rowCount() );
    ui->urgentTaskTable->setItem(ui->urgentTaskTable->rowCount()-1,0,in);
    ui->urgentTaskTable->resizeRowsToContents();
    ui->urgentTaskTable->resizeColumnsToContents();
    ui->regularTaskTable->resizeRowsToContents();
    ui->regularTaskTable->resizeColumnsToContents();
    return;
}

void MainWindow::clearTasks() {
    if(not taskManager.tasks.empty()){
        taskManager.tasks.clear();
    }

    // ui->textBrowser->clear();
    ui->tasktable->setRowCount(0);
    ui->urgentTaskTable->setRowCount(0);
    ui->regularTaskTable->setRowCount(0);
    ui->urgentTaskTable->update();
    ui->regularTaskTable->update();
    ui->tasktable->update();
    return;
}

void MainWindow::on_pushButton_2_clicked()
{
    bool all_removed = false;
    int mark = -1;
    while (all_removed != true){
        for (int i = 0 ; i < ui->tasktable->rowCount() ; i++){
            QCheckBox *box = new QCheckBox();
            box = (QCheckBox*)ui->tasktable->cellWidget(i,2);
            if (box->isChecked()){
                all_removed = 0;
                mark = i;
                break;
            }
        }
        if (mark != -1){

            QTableWidgetItem *ure = ui->tasktable->item(mark,0);
            QString urestr = ure->text();
            QTableWidgetItem *um;
            for(int i = 0 ; i < ui->urgentTaskTable->rowCount() ; ++i ){
                 um = ui->urgentTaskTable->item(i,0);
                 if (um->text() == ure->text()){
                     //std::cout << "match!" << std::endl;
                     ui->urgentTaskTable->removeRow(i);
                     ui->urgentTaskTable->update();
                 }
            }

            for(int i = 0 ; i < ui->regularTaskTable->rowCount() ; ++i ){
                 um = ui->regularTaskTable->item(i,0);
                 if (um->text() == ure->text()){
                     //std::cout << "match!" << std::endl;
                     ui->regularTaskTable->removeRow(i);
                     ui->regularTaskTable->update();
                 }
            }

            //qDebug() << urestr;


            ui->tasktable->removeRow(mark);
            mark = -1;
        } else {
            all_removed = true;
        }
    }




    return;
}

//END of Ahmed's Portion


//START of Inventory Portion


void MainWindow::on_invButton_clicked()
{
    itemQuant = InvQuantClick();
    ui->lineEditQuant->clear();

    itemName = InvNameClick();
    ui->lineEditName->clear();

    itemPrice = InvPriceClick();
    ui->lineEditPrice->clear();

    //QTableWidgetItem *iq = new QTableWidgetItem(QString::number(InvQuantClick()));
    //std::cout << itemQuant << std::endl;
    //ui->invtable->setItem(1,1,iq);

    Item item = Item(itemName,itemPrice);
    inventory.addItem(item, itemQuant);

    displayInv();
}

QString MainWindow::InvNameClick(){
    QString submittedString = ui->lineEditName->text();

    if (submittedString.isEmpty()) {
        return "";                             //cannot insert empty text into textBrowser
    }

    return submittedString;
}

int MainWindow::InvQuantClick(){
    return ui->lineEditQuant->text().toInt();
}

float MainWindow::InvPriceClick(){
    return ui->lineEditPrice->text().toFloat();
}

void MainWindow::displayInv(){
    /*if (not ui->textBrowserInv->toPlainText().isEmpty()){
        ui->textBrowserInv->clear();           //clear textBrowser if not empty
    }

    for(pair<QString, int> i:inventory.inventory){
        ui->textBrowserInv->append(i.first + ": " + QString::number(i.second) + " $" + QString::number(inventory.prices[i.first]));
    }*/

    std::unordered_map<QString, int>::iterator it = inventory.inventory.begin();

    QTableWidgetItem *in = new QTableWidgetItem(it->first, 0);
    QTableWidgetItem *iq = new QTableWidgetItem(QString::number(it->second), 0);
    QTableWidgetItem *ip = new QTableWidgetItem(QString::number(inventory.prices[it->first]), 0);
    QTableWidgetItem *itp = new QTableWidgetItem(QString::number(it->second * inventory.prices[it->first]), 0);
    ui->invtable->insertRow( ui->invtable->rowCount() );
    QCheckBox * checko = new QCheckBox();
    ui->invtable->setCellWidget(ui->invtable->rowCount()-1,4,checko);
    checko->setStyleSheet( "text-align: center; margin-left:50%; margin-right:50%;" );
    ui->invtable->setItem(ui->invtable->rowCount()-1,0,in);
    ui->invtable->setItem(ui->invtable->rowCount()-1,1,iq);
    ui->invtable->setItem(ui->invtable->rowCount()-1,2,ip);
    ui->invtable->setItem(ui->invtable->rowCount()-1,3,itp);
    ui->invtable->resizeColumnsToContents();
    ui->invtable->resizeRowsToContents();
    ui->invtable->update();
    it++;
    return;
}

//END of inventory portion

//Start of payroll section

QString EmployeeName;
float salary;
float hours;
PayRollSystem payroll;
int empcount = 0;


QString MainWindow::EmployeeNames(){
    QString submittedString = ui->lineEditEmployee->text();
    if (submittedString.isEmpty()) {return "";}                        //cannot insert empty text into textBrowser
    return submittedString;
}

float MainWindow::HoursWorked(){
    return ui->lineEditHours->text().toFloat();
}

float MainWindow::Salary(){
    return ui->lineEditSalary->text().toFloat();
}

void MainWindow::displayPayroll(){

    Employee *i = &payroll.employees[empcount];
    QTableWidgetItem *in = new QTableWidgetItem(i->name, 0);
    QTableWidgetItem *iq = new QTableWidgetItem(QString::number(i->salary), 0);
    QTableWidgetItem *ip = new QTableWidgetItem(QString::number(i->hours), 0);
    QTableWidgetItem *itp = new QTableWidgetItem(QString::number(i->hours * i->salary), 0);

    ui->payrolltable->insertRow( ui->payrolltable->rowCount() );
    ui->payrolltable->setItem(ui->payrolltable->rowCount()-1,0,in);
    ui->payrolltable->setItem(ui->payrolltable->rowCount()-1,1,iq);
    ui->payrolltable->setItem(ui->payrolltable->rowCount()-1,2,ip);
    ui->payrolltable->setItem(ui->payrolltable->rowCount()-1,3,itp);
    ui->payrolltable->update();
        
    // checkbox

    QCheckBox * cb = new QCheckBox();
    ui->payrolltable->setCellWidget(ui->payrolltable->rowCount()-1,4,cb);
    cb->setStyleSheet( "text-align: center; margin-left:50%; margin-right:50%;" );
    //if (cb->isChecked() == 0) {qDebug() << "ok";}

    ui->payrolltable->resizeColumnsToContents();
    ui->payrolltable->resizeRowsToContents();
    ui->payrolltable->update();
    empcount++;
    return;
}

void MainWindow::on_payButton_3_clicked()
{
    EmployeeName = EmployeeNames();
    ui->lineEditEmployee->clear();
    salary = Salary();
    ui->lineEditSalary->clear();
    hours = HoursWorked();
    ui->lineEditHours->clear();

    Employee chad = Employee(EmployeeName, salary, hours);
    payroll.employees.push_back(chad);
    displayPayroll();
}


void MainWindow::on_PayEmpButton_clicked()
{
    for (int i = 0 ; i < ui->payrolltable->rowCount() ; ++i){
        QCheckBox *box = new QCheckBox();
        box = (QCheckBox*)ui->payrolltable->cellWidget(i,4);
        if (box->isChecked()){
            ui->payrolltable->setItem(i,2,new QTableWidgetItem(QString::number(0), 0));
            ui->payrolltable->setItem(i,3,new QTableWidgetItem(QString::number(0), 0));
        }
    }
    return;
}


