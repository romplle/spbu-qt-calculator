#include <QApplication>
#include "LoginForm.h"
#include "CalculatorForm.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LoginForm login;
    if (login.exec() == QDialog::Accepted) {
        CalculatorForm calculator;
        calculator.show();
        return app.exec();
    }
    return 0;
}
