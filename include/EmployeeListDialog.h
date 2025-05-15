#ifndef EMPLOYEELISTDIALOG_H
#define EMPLOYEELISTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QVector>
#include "emp.h"  // Assuming you have an Employee struct/class

class EmployeeListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeListDialog(QWidget* parent = nullptr);
    void setEmployeeList(const QVector<Employee>& employees);

private:
    QTextEdit* employeeTextEdit;
};

#endif // EMPLOYEELISTDIALOG_H
