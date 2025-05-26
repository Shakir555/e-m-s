#ifndef EMPLOYEELISTDIALOG_H
#define EMPLOYEELISTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include "emp.h"

class EmployeeListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeListDialog(QWidget* parent = nullptr);
    void setEmployeeList(const QVector<Employee>& employees) {} // optional fallback

private:
    QTextEdit* employeeTextEdit;
    void loadEmployeesFromDatabase(); // ✅ add this method
};

#endif // EMPLOYEELISTDIALOG_H
