#include "CalculatorForm.h"

CalculatorForm::CalculatorForm(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    display = new QLineEdit(this);
    display->setAlignment(Qt::AlignCenter);
    resize(500, 500);

    gridLayout = new QGridLayout();
    QString buttons[6][4] = {
        {"="},
        {"1/x", "x^2", "sqrt(x)", "/"},
        {"7", "8", "9", "*"},
        {"4", "5", "6", "-"},
        {"1", "2", "3", "+"},
        {"+/-", "0", ",", "="}
    };

    QPushButton *button = new QPushButton(buttons[0][0], this);
    gridLayout->addWidget(button, 0, 3);

    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            QPushButton *button = new QPushButton(buttons[i][j], this);
            gridLayout->addWidget(button, i, j);
        }
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(display);
    mainLayout->addLayout(gridLayout);
}
