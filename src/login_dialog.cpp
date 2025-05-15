#include <QFormLayout>
#include <QMessageBox>
#include "login_dialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent), authenticated(false) 
{
    setWindowTitle("Login - Employer Mode");

    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Username:", usernameEdit);
    formLayout->addRow("Password:", passwordEdit);
    formLayout->addWidget(loginButton);

    setLayout(formLayout);

    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::verifyCredentials);
}


void LoginDialog::verifyCredentials() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Hardcoded credentials
    if (username == "admin" && password == "1234") {
        authenticated = true;
        accept();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

bool LoginDialog::isAuthenticated() const {
    return authenticated;
}
