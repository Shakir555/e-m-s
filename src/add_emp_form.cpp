#include <iostream>
#include <QDebug>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "add_emp_form.h"

extern std::vector<Employee> globalEmployeeList;

AddEmployeeForm::AddEmployeeForm(QWidget* parent) : QDialog(parent)
{
    setWindowTitle("Add Employee");
    setFixedSize(300, 300);
    nameEdit = new QLineEdit(this);
    idEdit = new QLineEdit(this);
    deptEdit = new QLineEdit(this);
    salaryEdit = new QLineEdit(this);
    saveBtn = new QPushButton("save", this);
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Name:", nameEdit);
    formLayout->addRow("ID:", idEdit);
    formLayout->addRow("Department:", deptEdit);
    formLayout->addRow("Salary:", salaryEdit);
    formLayout->addRow(saveBtn);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);
    connect(saveBtn, &QPushButton::clicked, this, &AddEmployeeForm::saveEmployee);
}

void AddEmployeeForm::saveEmployee()
{
    if (nameEdit->text().isEmpty() || idEdit->text().isEmpty() ||
        deptEdit->text().isEmpty() || salaryEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "All input text must be filled!");
        return;
    }
    else
    {
        QMessageBox::information(this, "Employee Information", "Employee Information filled");
    }
    Employee emp;
    emp.name = nameEdit->text();
    emp.id = idEdit->text();
    emp.department = deptEdit->text();
    emp.salary = salaryEdit->text();
    globalEmployeeList.push_back(emp);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql12.freesqldatabase.com");
    db.setDatabaseName("sql12781050");
    db.setUserName("sql12781050");
    db.setPassword("nTkylB8LP9");
    db.setPort(3306);
    if (!db.open())
    {
        QMessageBox::critical(this, "DB Connection Failed", db.lastError().text());
        return;
    }
    else
    {
        // connection success
    }
    QSqlQuery query;
    query.prepare("INSERT INTO employees (name, id, department, salary) VALUES (?, ?, ?, ?)");
    query.addBindValue(emp.name);
    query.addBindValue(emp.id);
    query.addBindValue(emp.department);
    query.addBindValue(emp.salary);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Insert Failed", query.lastError().text()); 
    }
    else
    {
        QMessageBox::information(this, "Success", "Employee inserted into database!");
    }
    db.close();
}

