#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QIcon>
#include <QFont>
#include <iostream>

#include "add_emp_form.h"


std::vector<Employee> globalEmployeeList;

// Function to initialize main window
void qt_window(QWidget& wd)
{
    wd.setFixedSize(500, 500);
    wd.setWindowIcon(QIcon("/home/shakir-salam/Documents/proj/e-m-s/resource/icon.png"));
    wd.setWindowTitle("EMS");
}

// ✅ Convert this to a standalone function (not member of MainWindow)
void onAddEmployeeClicked()
{
    AddEmployeeForm* form = new AddEmployeeForm(nullptr);  // separate window
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setModal(true);
    form->show();
}

void viewEmployeeClicked()
{
    QVector<Employee> employeeQVector;
    for (const auto& e : globalEmployeeList)
        employeeQVector.append(e);

    EmployeeListDialog* dialog = new EmployeeListDialog(nullptr);
    dialog->setEmployeeList(employeeQVector);
    dialog->exec();
}


// Function to add buttons to main window
void all_emp_btn(QWidget& wd)
{
    QPushButton* addButton = new QPushButton("Add Employee", &wd);
    addButton->setGeometry(50, 50, 150, 40);

    QObject::connect(addButton, &QPushButton::clicked, []() {
    onAddEmployeeClicked();  // ✅ keep this
    });

    QPushButton* viewButton = new QPushButton("View Employees", &wd);
    viewButton->setGeometry(50, 200, 150, 40);
    QObject::connect(viewButton, &QPushButton::clicked, []() {
    viewEmployeeClicked();
    });

    QPushButton* editButton = new QPushButton("Edit Employee", &wd);
    editButton->setGeometry(50, 100, 150, 40);

    QPushButton* deleteButton = new QPushButton("Delete Employee", &wd);
    deleteButton->setGeometry(50, 150, 150, 40);
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    QWidget wd;

    qt_window(wd);
    all_emp_btn(wd);

    wd.show();
    return application.exec();
}
