#ifndef ADD_EMP_FORM_H
#define ADD_EMP_FORM_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "EmployeeListDialog.h"

class AddEmployeeForm : public QDialog  // ✅ Use QDialog here
{
    Q_OBJECT

public:
    explicit AddEmployeeForm(QWidget* parent = nullptr);

private slots:
    void saveEmployee();

private:
    QLineEdit* nameEdit;
    QLineEdit* idEdit;
    QLineEdit* deptEdit;
    QLineEdit* salaryEdit;
    QPushButton* saveBtn;
    std::vector<Employee> employeeList;
};

#endif // ADD_EMP_FORM_H
