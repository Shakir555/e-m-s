#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QIcon>
#include <QMessageBox>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QLocale>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include "main_window.h"
#include "clock.h"
#include "add_emp_form.h"
#include "edit_emp_form.h"
#include "del_emp_form.h"
#include "login_dialog.h"
#include "employeeListDialog.h"
#include "piechart.h"

std::vector<Employee>globalEmployeeList;

MainWindow::MainWindow(int screenWidth, int screenHeight, 
                       QWidget* parent):QWidget(parent)
{

    this->setWindowIcon(QIcon(":/icon/icon.jpg"));
    this->setWindowTitle("EMS");
    QLabel* titleLabel = new QLabel("E-M-S", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont("Orbitron", 40, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setGeometry((screenWidth - 400) / 2, 30, 400, 80);
    clockWidget = new Clock(this);
    clockWidget->setGeometry(1050, 50, 300, 100);
    clockWidget->show();
    QLabel* versionLabel = new QLabel("FW Version: 1.0.0", this);
    QFont versionFont("Segoe UI", 10);
    versionFont.setItalic(true);
    versionLabel->setFont(versionFont);
    versionLabel->setGeometry(10, screenHeight - 30, 200, 20);
    QPushButton* loginButton = new QPushButton("Admin Login", this);
    loginButton->setGeometry(100, 300, 200, 100);
    connect(loginButton, &QPushButton::clicked, [this]()
    {
        LoginDialog loginDialog(this);
        if (loginDialog.exec() == QDialog::Accepted && loginDialog.isAuthenticated())
        {
            QMessageBox::information(this, "Success", "Admin Logged in Success!");
        }
        else
        {
            //Admin Logged in Failed
        }
    });
    QPushButton* addButton = new QPushButton("Add Employee", this);
    addButton->setGeometry(1100, 300, 200, 100);
    connect(addButton, &QPushButton::clicked, []()
    {
        auto* form = new AddEmployeeForm(nullptr);
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setModal(true);
        form->show();
    });
    QPushButton* editButton = new QPushButton("Edit Employee", this);
    editButton->setGeometry(1100, 400, 200, 100);
    connect(editButton, &QPushButton::clicked, []()
    {
        auto* form = new EditEmployeeForm(nullptr);
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setModal(true);
        form->show();
    });
    QPushButton* deleteButton = new QPushButton("Delete Employee", this);
    deleteButton->setGeometry(1100, 500, 200, 100);
    connect(deleteButton, &QPushButton::clicked, []()
    {
        auto* form = new DeleteEmployeeForm(nullptr);
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setModal(true);
        form->show();
    });
    QPushButton* viewButton = new QPushButton("View Employee", this);
    viewButton->setGeometry(1100, 600, 200, 100);
    connect(viewButton, &QPushButton::clicked, []()
    {
        QVector<Employee> employeeQVector;
        for (const auto& e:globalEmployeeList)
        {
            employeeQVector.append(e);
        }
        auto* dialog = new EmployeeListDialog(nullptr);
        dialog->exec();
    });
    pieChartWidget = new PieChartOpenGLWidget(this);
    int pieChartWidth = 500;
    int pieChartHeight = 500;
    int pieChartX = (screenWidth - pieChartWidth) / 2;
    int pieChartY = (screenHeight - pieChartHeight) / 2;
    pieChartWidget->setGeometry(pieChartX, pieChartY,
                                pieChartWidth, pieChartHeight);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "MainPieChartConn");
    QString dbPath = QCoreApplication::applicationDirPath() + "/employee.db";
    db.setDatabaseName(dbPath);
    if (db.open())
    {
        QSqlQuery query("SELECT department, COUNT(*) FROM employees GROUP BY department", db);
        QMap<QString, int> departmentData;
        while (query.next())
        {
            departmentData[query.value(0).toString()] = query.value(1).toInt();
        }
        pieChartWidget->setDepartmentData(departmentData);
        db.close();
    }
    else
    {
        QMessageBox::warning(this, "Database Error", db.lastError().text());
    }
}