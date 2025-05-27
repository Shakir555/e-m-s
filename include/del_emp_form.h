#ifndef DEL_EMP_FORM_H
#define DEL_EMP_FORM_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class DeleteEmployeeForm : public QDialog {
    Q_OBJECT

public:
    DeleteEmployeeForm(QWidget* parent = nullptr);

private slots:
    void deleteEmployee();

private:
    QLineEdit* idEdit;
    QPushButton* deleteBtn;
};

#endif // DEL_EMP_FORM_H
