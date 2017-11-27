#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


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

void MainWindow::openTeacher()
{
    teacher = new Teacher(this);
    teacher->show();
}

void MainWindow::on_btnLogin_clicked()
{
    QString username = ui->txtUser->text();
    QString password = ui->txtPass->text();

    if(username == "Admin" && password == "Admin"){
        hide();
        admin = new Admin(this);
        admin->show();
    }
    if(username == "teacher" && password == "teacher"){
        hide();
        openTeacher();
    }

}
