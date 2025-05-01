#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QDateEdit>
#include <iostream>
#include "add_emp_form.h"

AddEmployeeForm::AddEmployeeForm(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Add Employee");
    setFixedSize(300, 400);
    setGeometry(10, 200, 280, 30);
    std::cout << "employee form information init" << std::endl;
    nameEdit = new QLineEdit(this);
    idEdit = new QLineEdit(this);
    deptEdit = new QLineEdit(this);
    salaryEdit = new QLineEdit(this);
    saveBtn = new QPushButton("Save", this);
    std::cout << "employee form layout init" << std::endl;
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Name:", nameEdit);
    formLayout->addRow("ID:", idEdit);
    formLayout->addRow("Department:", deptEdit);
    formLayout->addRow("Salary:", salaryEdit);
    formLayout->addRow(saveBtn);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);
    connect(saveBtn, &QPushButton::clicked, this,
            &AddEmployeeForm::saveEmployee);
}

void AddEmployeeForm::saveEmployee()
{
    QString info = QString(
        "Name: %1\nID: %2\nDept: %3\nRole: %4\nSalary: %5\nJoin: %6\nEnd: %7")
        .arg(nameEdit->text())
        .arg(idEdit->text())
        .arg(deptEdit->text())
        .arg(salaryEdit->text());
    QMessageBox::information(this, "Saved", "Employee Data Saved!");
    std::cout << info.toStdString() << std::endl;
}


