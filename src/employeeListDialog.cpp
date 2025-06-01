#include <QtSql>
#include <QTextEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include "employeeListDialog.h"

EmployeeListDialog::EmployeeListDialog(QWidget* parent): QDialog(parent)
{
    setWindowTitle("Employee List");
    setFixedSize(400, 300);
    employeeTextEdit = new QTextEdit(this);
    employeeTextEdit->setReadOnly(true);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(employeeTextEdit);
    setLayout(layout);
    loadEmployeesFromDatabase();
}

void EmployeeListDialog::loadEmployeesFromDatabase()
{
    QString connectionName = "EmployeeListConn";
    QSqlDatabase db;
    if (QSqlDatabase::contains(connectionName)) 
    {
        db = QSqlDatabase::database(connectionName);
    } 
    else 
    {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("employee.db");
    }
    if (!db.open()) 
    {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
        return;
    }
    QSqlQuery query(db);
    if (!query.exec("SELECT name, id, department, salary FROM employees")) 
    {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        return;
    }
    QString employeeData;
    while(query.next()) 
    {
        employeeData += QString("Name: %1, ID: %2, Dept: %3, Salary: %4\n")
                        .arg(query.value(0).toString())
                        .arg(query.value(1).toString())
                        .arg(query.value(2).toString())
                        .arg(query.value(3).toString());
    }
    employeeTextEdit->setText(employeeData);
    db.close();
}