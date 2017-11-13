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

void MainWindow::on_loginButton_clicked()
{
//    QString username = ui->userName->text();
//    QString password = ui->password->text();

//    if(username == "test" && password == "test"){
        hide();
        studentMenu = new studentmenu(this);
        studentMenu->show();
//    }
//    else{
//        QMessageBox::warning(this,"login","username and password is incorrect");
//    }

}
