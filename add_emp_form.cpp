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
    Employee emp;
    emp.name = nameEdit->text();
    emp.id = idEdit->text();
    emp.department = deptEdit->text();
    emp.salary = salaryEdit->text();

    employeeList.push_back(emp); // store in vector

    QMessageBox::information(this, "Saved", "Employee Data Saved!");

    // Debug print
    std::cout << "Employees so far:\n";
    for (const auto& e : employeeList) {
        std::cout << "Name: " << e.name.toStdString()
                  << ", ID: " << e.id.toStdString()
                  << ", Dept: " << e.department.toStdString()
                  << ", Salary: " << e.salary.toStdString() << "\n";
    }
}

