#ifndef ADD_EMP_FORM_H
#define ADD_EMP_FORM_H

#include <QWidget>

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
    QLineEdit* roleEdit;
    QLineEdit* salaryEdit;
    QLineEdit* joinDateEdit;
    QLineEdit* endDateEdit;
    QPushButton* saveBtn;
};
#endif