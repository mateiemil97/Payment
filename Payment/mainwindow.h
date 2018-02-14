#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_pushButton_clicked();
    void on_get_paid_2_pressed();
    void on_get_hours_clicked();
    void on_get_no_days_clicked();


    void on_clear_all_clicked();

private:
    Ui::MainWindow *ui;
    int increment=1;
    double salary;
    int use_days;
    double use_paid;
    double hours;
    double taxes;
    QString name;
    QString paid;
    enum collumn
    {
        NAME,TAXES,PaidHour,NoDAYS,HOURS, GROSS , NET
    };
};
#endif // MAINWINDOW_H
