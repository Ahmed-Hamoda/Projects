#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createTabMenu();

private slots:
    //void on_goButton_clicked();
    void on_clearButton_clicked();      // tasks shit

    void on_invButton_clicked();        // inventory shit

    void on_payButton_3_clicked();      // payroll

    void on_urgentButton_clicked();
    
    void on_PayEmpButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    void storeInputString();
    void clearTasks();
    void displayTasks();  //tasks shit
    void storeUrgentString();
    void displayUrgentTasks(int index);
    void displayRegularTasks(int index);

    QString InvNameClick();
    int InvQuantClick();
    float InvPriceClick();      //inventory shit
    void displayInv();

    QString EmployeeNames();     //payroll
    float HoursWorked();
    float Salary();
    void displayPayroll();
};
#endif // MAINWINDOW_H
