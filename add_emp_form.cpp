#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QDateEdit>
#include <iostream>
#include "add_emp_form.h"
#include "EmployeeListDialog.h"

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
    // Validate input fields
    if (nameEdit->text().isEmpty() || idEdit->text().isEmpty() || deptEdit->text().isEmpty() || salaryEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
        return;
    }

    Employee emp;
    emp.name = nameEdit->text();
    emp.id = idEdit->text();
    emp.department = deptEdit->text();
    emp.salary = salaryEdit->text();

    employeeList.push_back(emp); // Store in vector

    QMessageBox::information(this, "Saved", "Employee Data Saved!");

    // Convert std::vector to QVector
    QVector<Employee> employeeQVector;
    for (const auto& e : employeeList) {
        employeeQVector.push_back(e); // Add each employee to QVector
    }

    // Create and show the Employee List Dialog
    EmployeeListDialog* employeeListDialog = new EmployeeListDialog(this);
    employeeListDialog->setEmployeeList(employeeQVector);  // Now passing QVector<Employee> instead
    employeeListDialog->exec();
}

