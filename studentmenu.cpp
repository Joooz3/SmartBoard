#include "studentmenu.h"
#include "ui_studentmenu.h"

studentmenu::studentmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentmenu)
{
    ui->setupUi(this);

    int colCount = 4;
    int rowCount = 4;

    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(item->flags()^ Qt::ItemIsEditable);

    ui->tableWidget->setColumnCount(colCount);
    ui->tableWidget->setRowCount(rowCount);
    QTableWidgetItem *hHeader1= new QTableWidgetItem("Subject");
    QTableWidgetItem *hHeader2 = new QTableWidgetItem("Hours");
    QTableWidgetItem *hHeader3 = new QTableWidgetItem("Grade");
    QTableWidgetItem *hHeader4 = new QTableWidgetItem("Time");
    ui->tableWidget->setHorizontalHeaderItem(0,hHeader1);
    ui->tableWidget->setHorizontalHeaderItem(1,hHeader2);
    ui->tableWidget->setHorizontalHeaderItem(2,hHeader3);
    ui->tableWidget->setHorizontalHeaderItem(3,hHeader4);




}

studentmenu::~studentmenu()
{
    delete ui;
}

//void getStudentInfo::getTable(){
//    QFile myFile(":/mikearmstrong.txt");
//    myFile.open(QIODevice::ReadOnly);

//    QTextStream textStream(&myFile);
//    QString line = textStream.readAll();
//    myFile.close();

//    ui->tableWidget->
//}
