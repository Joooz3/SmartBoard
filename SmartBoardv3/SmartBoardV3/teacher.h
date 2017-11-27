#ifndef TEACHER_H
#define TEACHER_H

#include <QFile>
#include <QTextStream>

#include <QDialog>

namespace Ui {
class Teacher;
}

class Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = 0);
    ~Teacher();
    void list(QString);


private slots:
    void on_pushButton_clicked();
    void resetTable();

    void on_btnUpload_clicked();

private:
    Ui::Teacher *ui;
};

#endif // TEACHER_H
