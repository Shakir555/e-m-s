#ifndef ADD_EMP_FORM_H
#define ADD_EMP_FORM_H

#include <QWidget>
#include <vector>
#include "emp.h"

class QLineEdit;
class QDateEdit;
class QPushButton;

class AddEmployeeForm: public QWidget
{
    Q_OBJECT
public:
    AddEmployeeForm(QWidget* parent = nullptr);
private slots:
    void saveEmployee();
private:
    QLineEdit* nameEdit;
    QLineEdit* idEdit;
    QLineEdit* deptEdit;
    QLineEdit* salaryEdit;
    QPushButton* saveBtn;
    std::vector<Employee>employeeList;
};
#endif