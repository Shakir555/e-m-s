#include <QFormLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include "edit_emp_form.h"

EditEmployeeForm::EditEmployeeForm(QWidget* parent): QDialog(parent)
{
    setWindowTitle("Edit Employee");
    setFixedSize(300, 200);
    idEdit = new QLineEdit(this);
    nameEdit = new QLineEdit(this);
    deptEdit = new QLineEdit(this);
    salaryEdit = new QLineEdit(this);
    fetchBtn = new QPushButton("Fetch", this);
    updateBtn = new QPushButton("Update", this);
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Employee ID Edit:", idEdit);
    formLayout->addRow(fetchBtn);
    formLayout->addRow("Name:", nameEdit);
    formLayout->addRow("Department:", deptEdit);
    formLayout->addRow("Salary:", salaryEdit);
    formLayout->addRow(updateBtn);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);
    connect(fetchBtn, &QPushButton::clicked, this, &EditEmployeeForm::fetchEmployee);
    connect(updateBtn, &QPushButton::clicked, this, &EditEmployeeForm::updateEmployee);
}

void EditEmployeeForm::fetchEmployee()
{
    QString empId = idEdit->text().trimmed();
    if (empId.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please Enter an Employee ID");
        return;
    }
    QSqlDatabase db;
    if (QSqlDatabase::contains("EditConnection")) {
        db = QSqlDatabase::database("EditConnection");
    } 
    else 
    {
        db = QSqlDatabase::addDatabase("QSQLITE", "EditConnection");
        db.setDatabaseName("employee.db");  
    }
    if (!db.open())
    {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
        return;
    }
    QSqlQuery query(db);
    query.prepare("SELECT name, department, salary FROM employees WHERE id = ?");
    query.addBindValue(empId);
    if (!query.exec() || !query.next())
    {
        QMessageBox::warning(this, "Error", "Employee not found!");
        db.close();
        return;
    }
    nameEdit->setText(query.value(0).toString());
    deptEdit->setText(query.value(1).toString());
    salaryEdit->setText(query.value(2).toString());
    db.close();
}

void EditEmployeeForm::updateEmployee()
{
    QString empId = idEdit->text().trimmed();
    QString name = nameEdit->text().trimmed();
    QString dept = deptEdit->text().trimmed();
    QString salary = salaryEdit->text().trimmed();
    if (empId.isEmpty() || name.isEmpty() || dept.isEmpty() || salary.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "All Input must be filled!");
        return;
    }
    QSqlDatabase db = QSqlDatabase::database("EditConnection");
    if (!db.isOpen() && !db.open())
    {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
        return;
    }
    QSqlQuery query(db);
    query.prepare("UPDATE employees SET name = ?, department = ?, salary = ? WHERE id = ?");
    query.addBindValue(name);
    query.addBindValue(dept);
    query.addBindValue(salary);
    query.addBindValue(empId);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Update Failed", query.lastError().text());
    }
    else
    {
        QMessageBox::information(this, "Success", "Employee updated successfully!");
        this->close();
    }
    db.close();
}
