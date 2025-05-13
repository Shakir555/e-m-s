#include "EmployeeListDialog.h"
#include <QVBoxLayout>
#include <QTextEdit>

EmployeeListDialog::EmployeeListDialog(QWidget* parent) : QDialog(parent)
{
    setWindowTitle("Employee List");
    setFixedSize(400, 300);

    employeeTextEdit = new QTextEdit(this);
    employeeTextEdit->setReadOnly(true);  // Make the text edit read-only

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(employeeTextEdit);
    setLayout(layout);
}

void EmployeeListDialog::setEmployeeList(const QVector<Employee>& employees)
{
    QString employeeData;
    for (const auto& e : employees) {
        employeeData += QString("Name: %1, ID: %2, Dept: %3, Salary: %4\n")
                            .arg(e.name)
                            .arg(e.id)
                            .arg(e.department)
                            .arg(e.salary);
    }
    employeeTextEdit->setText(employeeData);
}
