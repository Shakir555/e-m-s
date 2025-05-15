#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "emp_btn.h"
#include "add_emp_form.h"

void add_emp_btn(QWidget& wd)
{
    QPushButton* add_emp_btn = new QPushButton("Add Employee", &wd);
    add_emp_btn->setText("Add Employee");
    add_emp_btn->setToolTip("Create an employee details");
    add_emp_btn->setFont(QFont("Bold", 12, 1));
    add_emp_btn->setGeometry(10, 30, 280, 30);
    QObject::connect(add_emp_btn, &QPushButton::clicked, [&](){
        AddEmployeeForm* form = new AddEmployeeForm(&wd);
        form->show();
    });
    std::cout << "add employee button init" << std::endl;
}

void edit_emp_btn(QWidget& wd)
{
    QPushButton* edit_emp_btn = new QPushButton("Edit Employee", &wd);
    edit_emp_btn->setText("Edit Employee");
    edit_emp_btn->setToolTip("Edit an employee details");
    edit_emp_btn->setFont(QFont("Bold", 12, 1));
    edit_emp_btn->setGeometry(10, 50, 280, 30);
    std::cout << "edit employee button init" << std::endl;
}

void del_emp_btn(QWidget& wd)
{
    QPushButton* del_emp_btn = new QPushButton("Delete Employee", &wd);
    del_emp_btn->setText("Delete Employee");
    del_emp_btn->setToolTip("Delete an employee");
    del_emp_btn->setFont(QFont("Bold", 12, 1));
    del_emp_btn->setGeometry(10, 90, 280, 30);
    std::cout << "delete employee button init" << std::endl;
}

void view_emp_btn(QWidget& wd)
{
    QPushButton* view_emp_btn = new QPushButton("View Employee", &wd);
    view_emp_btn->setText("View Employee");
    view_emp_btn->setToolTip("View employee list");
    view_emp_btn->setFont(QFont("Bold", 12, 1));
    view_emp_btn->setGeometry(10, 120, 280, 30);
    std::cout << "view employee button init" << std::endl;
}