#include "LoginForm.h"
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    resize(300, 150);

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Логин");

    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Пароль");
    passwordInput->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Вход", this);
    connect(loginButton, &QPushButton::clicked, this, &LoginForm::onLoginClicked);

    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);

    setLayout(layout);
}

void LoginForm::onLoginClicked() {
    if (usernameInput->text().isEmpty() || passwordInput->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка входа", "Пожалуйста введите логин и пароль");
    } else {
        accept();
    }
}
