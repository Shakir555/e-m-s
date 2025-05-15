#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QIcon>
#include <QFont>
#include <QScreen>
#include <QMessageBox>
#include <iostream>

#include "add_emp_form.h"
#include "login_dialog.h"
#include "EmployeeListDialog.h"


std::vector<Employee> globalEmployeeList;

// Function to initialize main window to follow desktop screen size
void qt_window(QWidget& wd)
{
    wd.setWindowIcon(QIcon("/home/shakir-salam/Documents/proj/e-m-s/resource/icon/icon.png"));
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
void admin_button(QWidget& wd)
{
    /// Login button on the left
    QPushButton* loginButton = new QPushButton("Admin Login", &wd);
    loginButton->setGeometry(100, 300, 200, 100);  // Position on left side

    QObject::connect(loginButton, &QPushButton::clicked, [&wd]() {
        LoginDialog loginDialog(&wd);
        if (loginDialog.exec() == QDialog::Accepted) {
            if (loginDialog.isAuthenticated()) {
                QMessageBox::information(&wd, "Success", "Admin logged in!");
                // TODO: enable admin-only features here
            }
        }
    });
}


// Function to add buttons to main window
void all_emp_btn(QWidget& wd)
{
    QPushButton* addButton = new QPushButton("Add Employee", &wd);
    addButton->setGeometry(1100, 300, 200, 100);

    QObject::connect(addButton, &QPushButton::clicked, []() {
    onAddEmployeeClicked();  
    });

    QPushButton* editButton = new QPushButton("Edit Employee", &wd);
    editButton->setGeometry(1100, 400, 200, 100);

    QPushButton* deleteButton = new QPushButton("Delete Employee", &wd);
    deleteButton->setGeometry(1100, 500, 200, 100);

    QPushButton* viewButton = new QPushButton("View Employees", &wd);
    viewButton->setGeometry(1100, 600, 200, 100);
    QObject::connect(viewButton, &QPushButton::clicked, []() {
    viewEmployeeClicked();
    });
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    QWidget wd;

    qt_window(wd);
    admin_button(wd);
    all_emp_btn(wd);
    wd.showFullScreen();

    return application.exec();
}