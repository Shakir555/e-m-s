#include "main_window.h"
#include "clock.h"
#include "add_emp_form.h"
#include "edit_emp_form.h"
#include "del_emp_form.h"
#include "login_dialog.h"
#include "EmployeeListDialog.h"
#include "piechart.h"

#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QIcon>
#include <QMessageBox>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

std::vector<Employee> globalEmployeeList;

MainWindow::MainWindow(int screenWidth, int screenHeight, QWidget *parent) : QWidget(parent)
{
    this->setWindowIcon(QIcon("/home/shakir-salam/Documents/proj/e-m-s/resource/icon/icon.png"));
    this->setWindowTitle("EMS");

    // Admin Login Button
    QPushButton* loginButton = new QPushButton("Admin Login", this);
    loginButton->setGeometry(100, 300, 200, 100);
    connect(loginButton, &QPushButton::clicked, [this]() {
        LoginDialog loginDialog(this);
        if (loginDialog.exec() == QDialog::Accepted && loginDialog.isAuthenticated()) {
            QMessageBox::information(this, "Success", "Admin logged in!");
        }
    });

    // Add Employee Button
    QPushButton* addButton = new QPushButton("Add Employee", this);
    addButton->setGeometry(1100, 300, 200, 100);
    connect(addButton, &QPushButton::clicked, []() {
        AddEmployeeForm* form = new AddEmployeeForm(nullptr);
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setModal(true);
        form->show();
    });

    // Edit Employee Button
    QPushButton* editButton = new QPushButton("Edit Employee", this);
    editButton->setGeometry(1100, 400, 200, 100);
    connect(editButton, &QPushButton::clicked, []() {
        EditEmployeeForm* form = new EditEmployeeForm(nullptr);
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setModal(true);
        form->show();
    });

    // Delete Employee Button
    QPushButton* deleteButton = new QPushButton("Delete Employee", this);
    deleteButton->setGeometry(1100, 500, 200, 100);
    connect(deleteButton, &QPushButton::clicked, []() {
        DeleteEmployeeForm* form = new DeleteEmployeeForm(nullptr);
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setModal(true);
        form->show();
    });

    // View Employee Button
    QPushButton* viewButton = new QPushButton("View Employees", this);
    viewButton->setGeometry(1100, 600, 200, 100);
    connect(viewButton, &QPushButton::clicked, []() {
        QVector<Employee> employeeQVector;
        for (const auto& e : globalEmployeeList)
            employeeQVector.append(e);

        EmployeeListDialog* dialog = new EmployeeListDialog(nullptr);
        dialog->exec();
    });

    // EMS Title Label
    QLabel* titleLabel = new QLabel("E-M-S", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont;
    titleFont.setPointSize(40);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: black;");
    titleLabel->setGeometry((screenWidth - 300) / 2, 30, 300, 100);

    // Clock widget
    clockWidget = new Clock(this);
    clockWidget->setGeometry(1050, 50, 300, 100);
    clockWidget->show();

    // Pie Chart Widget (centered horizontally and vertically)
    pieChartWidget = new PieChartOpenGLWidget(this);
    int pieChartWidth = 500;
    int pieChartHeight = 500;
    int pieChartX = (screenWidth - pieChartWidth) / 2;   // Center horizontally
    int pieChartY = (screenHeight - pieChartHeight) / 2; // Center vertically
    pieChartWidget->setGeometry(pieChartX, pieChartY, pieChartWidth, pieChartHeight);

    // Fetch Data from DB
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "MainPieChartConn");
    db.setHostName("sql12.freesqldatabase.com");
    db.setDatabaseName("sql12781050");
    db.setUserName("sql12781050");
    db.setPassword("nTkylB8LP9");
    db.setPort(3306);

    if (db.open()) {
        QSqlQuery query("SELECT department, COUNT(*) FROM employees GROUP BY department", db);
        QMap<QString, int> departmentData;

        while (query.next()) {
            departmentData[query.value(0).toString()] = query.value(1).toInt();
        }

        pieChartWidget->setDepartmentData(departmentData);
        db.close();
    } else {
        QMessageBox::warning(this, "Database Error", db.lastError().text());
    }
}
