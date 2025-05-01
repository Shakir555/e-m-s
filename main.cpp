#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QIcon>
#include <QFont>
#include <iostream>
#include "emp_btn.h"

void qt_window(QWidget& wd)
{
    wd.setFixedSize(500, 500);
    wd.setWindowIcon(QIcon("/home/shakir-salam/Documents/proj/emp_ms/icon.png"));
    wd.setWindowTitle("EMS");
}

void all_emp_btn(QWidget& wd)
{
    add_emp_btn(wd);
    edit_emp_btn(wd);
    del_emp_btn(wd);
}


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    QWidget wd;
    qt_window(wd);
    all_emp_btn(wd);
    wd.show();  
    return application.exec();
}
