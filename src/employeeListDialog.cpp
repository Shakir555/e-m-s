#include "employeeListDialog.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QtSql>
#include <QMessageBox>

EmployeeListDialog::EmployeeListDialog(QWidget* parent) : QDialog(parent)
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
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql12.freesqldatabase.com");
    db.setDatabaseName("sql12781050");
    db.setUserName("sql12781050");
    db.setPassword("nTkylB8LP9");
    db.setPort(3306);

    if (!db.open()) {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
        return;
    }

    QSqlQuery query("SELECT name, id, department, salary FROM employees");

    QString employeeData;
    while (query.next()) {
        employeeData += QString("Name: %1, ID: %2, Dept: %3, Salary: %4\n")
                        .arg(query.value(0).toString())
                        .arg(query.value(1).toString())
                        .arg(query.value(2).toString())
                        .arg(query.value(3).toString());
    }

    employeeTextEdit->setText(employeeData);
    db.close();
}
