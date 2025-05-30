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

private:
    QTextEdit* employeeTextEdit;
    void loadEmployeesFromDatabase();
};

#endif