#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
using namespace std;
double total_minutes;
int begin , end;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//MAKE PAYMENT BY NUMBERS OF HOUR
void MainWindow::on_get_paid_2_pressed()
{
    taxes=ui->label_taxes->text().toDouble();
    paid=ui->paid_hour->text();
    use_paid=paid.toDouble();


    salary=(ui->get_hours_2->text().toDouble() * use_paid) -(ui->get_hours_2->text().toDouble() * use_paid)*taxes/100;
    QString shown_salary = QString::number(salary);
    ui->label->setText("SALARY:" + shown_salary);


    //GET DATA

    use_paid=paid.toDouble();

    use_days=ui->days->value();

    name = ui->label_name->text();

    //Create table
    ui->tableWidget->setColumnCount(7);

    int aux = ui->tableWidget->rowCount();

    QStringList titleHorizontal;
    titleHorizontal<<"NAME"<<"TAXES(%)"<<"P/H"<<"No.DAYS"<<"HOURS"<<"GROSS"<<"NET";

    ui->tableWidget->setHorizontalHeaderLabels(titleHorizontal);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(aux,NAME, new QTableWidgetItem(name));
    ui->tableWidget->setItem(aux,TAXES, new QTableWidgetItem(QString::number(taxes)));
    ui->tableWidget->setItem(aux,PaidHour, new QTableWidgetItem(QString::number(use_paid)));
    ui->tableWidget->setItem(aux,NoDAYS, new QTableWidgetItem("-"));
    ui->tableWidget->setItem(aux,HOURS, new QTableWidgetItem(ui->get_hours_2->text()));
    ui->tableWidget->setItem(aux,GROSS, new QTableWidgetItem(QString :: number(ui->get_hours_2->text().toDouble() * use_paid)));
    ui->tableWidget->setItem(aux,NET, new QTableWidgetItem(QString ::number(salary)));

    //Clear fields


    ui->label_name->clear();
    ui->paid_hour->clear();
    ui->get_hours_2->clear();
    ui->days->clear();


}



void MainWindow::on_get_no_days_clicked()
{
    ui->label->clear();
    use_days=ui->days->value();
    QString show_day=QString::number(use_days);
    ui->label->setText("DAYS:" + show_day);
    QString index_shown=QString::number(1);
    ui->label_hours->setText(index_shown);
}




//INSERT HOURS INTERVAL
void MainWindow::on_get_hours_clicked()
{
   increment++;
   int  begin_hour = ui->begin_hour->text().toInt();
   int begin_minutes= ui->begin_minutes->text().toInt();

   int end_hour = ui->end_hour->text().toInt();
   int end_minutes = ui->end_minutes->text().toInt();

    total_minutes +=((end_hour * 60 ) + end_minutes) -(( begin_hour * 60) + begin_minutes);


    QString index_shown=QString::number(increment);
    ui->label_hours->setText(index_shown);

    if(increment == use_days+1)
    {
      ui->label->setText("PRESS GET RESULT");
      ui->label_hours->clear();

    }
    ui->begin_hour->clear();
    ui->begin_minutes->clear();
    ui->end_hour->clear();
    ui->end_minutes->clear();
}



//GET RESULT Interval
void MainWindow::on_pushButton_clicked()
{
    paid=ui->paid_hour->text();

    use_paid=paid.toDouble();

    taxes=ui->label_taxes->text().toDouble();

    name = ui->label_name->text();


    QString shown_salary;
    salary = (total_minutes / 60) * use_paid;
    double net=salary - (salary * taxes/100);
    shown_salary = QString::number(salary);
    ui->label->setText("SALARY:" + shown_salary);




    //Create table
    ui->tableWidget->setColumnCount(7);
    int aux = ui->tableWidget->rowCount();

    QStringList titleHorizontal;
    titleHorizontal<<"NAME"<<"TAXES(%)"<<"P/H"<<"No.DAYS"<<"HOURS"<<"GROSS"<<"NET";

    ui->tableWidget->setHorizontalHeaderLabels(titleHorizontal);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(aux,NAME, new QTableWidgetItem(name));
    ui->tableWidget->setItem(aux,TAXES, new QTableWidgetItem(QString::number(taxes)));
    ui->tableWidget->setItem(aux,PaidHour, new QTableWidgetItem(QString::number(use_paid)));
    ui->tableWidget->setItem(aux,NoDAYS, new QTableWidgetItem(QString::number(use_days)));
    ui->tableWidget->setItem(aux,HOURS, new QTableWidgetItem(QString::number(total_minutes / 60)));
    ui->tableWidget->setItem(aux,GROSS, new QTableWidgetItem(shown_salary));
    ui->tableWidget->setItem(aux,NET, new QTableWidgetItem(QString ::number(net)));

    //Reset
    total_minutes=0;
    increment=1;

    //Clear fields


    ui->paid_hour->clear();
    ui->get_hours_2->clear();
    ui->days->clear();
    ui->begin_hour->clear();
    ui->begin_minutes->clear();
    ui->end_hour->clear();
    ui->end_minutes->clear();

}




void MainWindow::on_clear_all_clicked()
{
    ui->label->clear();
    ui->label_name->clear();
    ui->paid_hour->clear();
    ui->get_hours_2->clear();
    ui->label_taxes->clear();
    ui->days->clear();
    ui->label_hours->clear();
    ui->begin_hour->clear();
    ui->begin_minutes->clear();
    ui->end_hour->clear();
    ui->end_minutes->clear();
    ui->tableWidget->setRowCount(0);
}
