#ifndef DEL_EMP_BTN
#define DEL_EMP_BTN

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class DeleteEmployeeForm:public QDialog
{
    Q_OBJECT

public:
    DeleteEmployeeForm(QWidget* parent = nullptr);

private slots:
    void deleteEmployee();

private:
    QLineEdit* idEdit;
    QPushButton* deleteBtn;
};

#endif