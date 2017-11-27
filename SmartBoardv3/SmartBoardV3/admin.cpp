#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    setWindowTitle("Admin");

    ui->tableWidget->setColumnCount(5);
    QStringList titles;
    titles<<"ID"<<"Student Name"<<"Professor"<<"Class"<<"Time";
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    ui->tableWidget->setColumnWidth(0,65);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,200);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::resetTable()
{
        while(ui->tableWidget->rowCount()>0){
            ui->tableWidget->removeRow(0);
        }
}


void Admin::on_pushButton_2_clicked()
{
    QFile file("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/database.txt");
        if(!file.open(QIODevice::Append|QIODevice::Text))
            return;

    QTextStream out(&file);
    out<<ui->txtId->text()<<"-"<<ui->txtStudent->text()<<"-"<<
         ui->txtProfessor->text()<<"-"<<ui->txtClass->text()<<"-"<<ui->txtTime->text()<<"\n";
    file.close();

    resetTable();

    QFile file2("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/database.txt");
        if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file2);
        while(!in.atEnd()){
            QString line = in.readLine();
            list(line);
        }
        file.close();

}

void Admin::list(QString tableList){
        QStringList A = tableList.split("-");
        QString id = A[0];
        QString student = A[1];
        QString prof = A[2];
        QString classs = A[3];
        QString hour = A[4];

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(id));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(student));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(prof));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(classs));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,new QTableWidgetItem(hour));
    }

void Admin::deleteRow()
{
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
}


void Admin::on_pushButton_clicked()
{

    QString txt = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();


    QFile file1("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/database.txt");
        if(!file1.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QFile temp("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/temp.txt");
        if(!temp.open(QIODevice::Append|QIODevice::Text))
            return;
        QTextStream in(&file1);
        QTextStream out(&temp);
            while(!in.atEnd()){
                QString line = in.readLine();
                QStringList A = line.split("-");
                QString id = A[0];
                if(id.compare(txt)!=0){
                    out<<line<<"\n";
                }
            }
   file1.close();
   temp.close();


   QFile file3("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/database.txt");
   if(!file3.open(QIODevice::WriteOnly | QIODevice::Text))
       return;
   file3.close();

   QFile file2("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/database.txt");
   if(!file2.open(QIODevice::Append | QIODevice::Text))
       return;
   QFile temp1("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/temp.txt");
         if(!temp1.open(QIODevice::ReadOnly|QIODevice::Text))
             return;
   QTextStream in1(&temp1);
   QTextStream out2(&file2);
   while(!in1.atEnd()){
       QString line = in1.readLine();
       out2<<line<<"\n";
   }

   file2.close();
   temp1.close();
   deleteRow();




}
