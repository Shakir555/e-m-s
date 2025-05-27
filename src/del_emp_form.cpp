#include "del_emp_form.h"
#include <QFormLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QPushButton>
#include <QVBoxLayout>

DeleteEmployeeForm::DeleteEmployeeForm(QWidget* parent) : QDialog(parent)
{
    setWindowTitle("Delete Employee");
    setFixedSize(300, 200);

    idEdit = new QLineEdit(this);
    deleteBtn = new QPushButton("Delete", this);

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Employee ID:", idEdit);
    formLayout->addRow(deleteBtn);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);

    connect(deleteBtn, &QPushButton::clicked, this, &DeleteEmployeeForm::deleteEmployee);
}

void DeleteEmployeeForm::deleteEmployee()
{
    QString empId = idEdit->text().trimmed();

    if (empId.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter an Employee ID.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "DeleteConnection");
    db.setHostName("sql12.freesqldatabase.com");
    db.setDatabaseName("sql12781050");
    db.setUserName("sql12781050");
    db.setPassword("nTkylB8LP9");
    db.setPort(3306);

    if (!db.open()) {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    query.prepare("DELETE FROM employees WHERE id = ?");
    query.addBindValue(empId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Delete Failed", query.lastError().text());
    } else {
        QMessageBox::information(this, "Deleted", "Employee removed successfully.");
        this->close();
    }

    db.close();
}
