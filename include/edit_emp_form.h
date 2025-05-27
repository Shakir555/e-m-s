#ifndef EDIT_EMP_FORM_H
#define EDIT_EMP_FORM_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class EditEmployeeForm : public QDialog {
    Q_OBJECT

public:
    EditEmployeeForm(QWidget* parent = nullptr);

private slots:
    void fetchEmployee();
    void updateEmployee();

private:
    QLineEdit *idEdit, *nameEdit, *deptEdit, *salaryEdit;
    QPushButton *fetchBtn, *updateBtn;
};

#endif // EDIT_EMP_FORM_H
