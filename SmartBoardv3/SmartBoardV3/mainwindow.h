#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"
#include "teacher.h"

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
    void openTeacher();

    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;
    Admin *admin;
    Teacher *teacher;

};

#endif // MAINWINDOW_H
