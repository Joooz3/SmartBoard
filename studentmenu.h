#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <QDialog>

namespace Ui {
class studentmenu;
}

class studentmenu : public QDialog
{
    Q_OBJECT

public:
    explicit studentmenu(QWidget *parent = 0);
    ~studentmenu();

private:
    Ui::studentmenu *ui;
};

#endif // STUDENTMENU_H
