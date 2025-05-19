#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QIcon>
#include <QFont>
#include <QScreen>
#include <QMessageBox>
#include <iostream>

#include "clock.h"
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

// Convert this to a standalone function (not member of MainWindow)
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
    // Set black background for main window
    // wd.setStyleSheet("background-color: black;");
    admin_button(wd);
    all_emp_btn(wd);

    // ✅ Add centered "E-M-S" title label
    QLabel* titleLabel = new QLabel("E-M-S", &wd);
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont titleFont;
    titleFont.setPointSize(40);  // Large font
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: black;");

    // Center horizontally, near the top
    int windowWidth = QGuiApplication::primaryScreen()->availableGeometry().width();
    titleLabel->setGeometry((windowWidth - 300) / 2, 30, 300, 100);


    // // Create and assign layout first
    // QVBoxLayout* layout = new QVBoxLayout(&wd);
    // wd.setLayout(layout);

    // // Create and display the clock in layout
    // Clock* clockWidget = new Clock(layout);

     // ✅ Add clock widget with manual geometry (top-center or top-right)
    Clock* clockWidget = new Clock(nullptr);
    clockWidget->setParent(&wd);
    clockWidget->setGeometry(1050, 50, 300, 100); // Adjust position as needed
    clockWidget->show();

    wd.showFullScreen();

    return application.exec();
}