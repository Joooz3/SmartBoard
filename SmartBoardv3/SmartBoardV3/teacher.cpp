#include "teacher.h"
#include "ui_teacher.h"
#include <QFile>
#include <QTextStream>

Teacher::Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    QStringList titles;
    titles<<"Student ID"<<"Student Name"<<"Assign1"<<"Assign2"<<"Midterm"<<"Final";
    ui->tableWidget->setHorizontalHeaderLabels(titles);
}

Teacher::~Teacher()
{
    delete ui;



}


void Teacher::resetTable()
{
        while(ui->tableWidget->rowCount()>0){
            ui->tableWidget->removeRow(0);
        }
}





void Teacher::on_pushButton_clicked()
{
    resetTable();
    QString teacherName = "chang";
    QString morningTime = "AM";

    QFile file("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/database.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList A = line.split("-");
            QString teacher = A[2];
            QString time = A[4];
            if(teacher.contains(teacherName) && time.contains(morningTime) ==true){
                list(line);
            }

        }
        file.close();


}

void Teacher::list(QString tableList){
        QStringList A = tableList.split("-");
        QString id = A[0];
        QString student = A[1];
//        QString assign1 = A[2];
//        QString assign2 = A[3];
//        QString midterm = A[4];
//        QString final = A[5];





        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(id));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(student));


    }



void Teacher::on_btnUpload_clicked()
{
    QFile grades("C:/Users/alani/Documents/SmartBoard/SmartBoardv3/gradedatabase.txt");

    if(!grades.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    {
    QTextStream out(&grades);

    QStringList dataList;

    for ( int r = 0; r < ui->tableWidget->rowCount(); ++r){

        for(int c = 0; c < ui->tableWidget->columnCount(); ++c){
            dataList <<""+ui->tableWidget->item(r,c)->text()+"-";
            }
        out<<dataList;
    }


    grades.close();

}

}
