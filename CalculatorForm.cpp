#include "CalculatorForm.h"

CalculatorForm::CalculatorForm(QWidget *parent)
    : QMainWindow(parent), leftOperand(0), waitingForOperand(true) {

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    currentExpression = new QLineEdit(this);
    currentExpression->setAlignment(Qt::AlignLeft);

    lastOperation = new QLineEdit(this);
    lastOperation->setAlignment(Qt::AlignLeft);

    resultDisplay = new QLineEdit(this);
    resultDisplay->setAlignment(Qt::AlignLeft);

    gridLayout = new QGridLayout();

    QString buttons[5][4] = {
        {"", "", "C", "/"},
        {"7", "8", "9", "*"},
        {"4", "5", "6", "-"},
        {"1", "2", "3", "+"},
        {"", "0", "", "="}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (buttons[i][j] == "") {
                continue;
            }
            QPushButton *button = new QPushButton(buttons[i][j], this);
            gridLayout->addWidget(button, i, j);

            if (buttons[i][j] == "=") {
                connect(button, &QPushButton::clicked, this, &CalculatorForm::onEqualClicked);
            } else if (buttons[i][j] == "C") {
                connect(button, &QPushButton::clicked, this, &CalculatorForm::onClearClicked);
            } else if (buttons[i][j] == "+" || buttons[i][j] == "-" || buttons[i][j] == "*" || buttons[i][j] == "/") {
                connect(button, &QPushButton::clicked, this, &CalculatorForm::onOperatorClicked);
            } else {
                connect(button, &QPushButton::clicked, this, &CalculatorForm::onDigitClicked);
            }
        }
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(currentExpression);
    mainLayout->addWidget(lastOperation);
    mainLayout->addWidget(resultDisplay);
    mainLayout->addLayout(gridLayout);
}

void CalculatorForm::onDigitClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    QString digitValue = clickedButton->text();

    if (waitingForOperand) {
        currentExpression->clear();
        waitingForOperand = false;
    }

    currentExpression->setText(currentExpression->text() + digitValue);
}

void CalculatorForm::onOperatorClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    QString clickedOperator = clickedButton->text();

    if (!waitingForOperand) {
        leftOperand = currentExpression->text().toInt();
        currentOperator = clickedOperator;
        lastOperation->setText(currentExpression->text() + " " + currentOperator);
        waitingForOperand = true;
    }
}

void CalculatorForm::onEqualClicked() {
    double rightOperand = currentExpression->text().toInt();
    double result = 0;

    if (currentOperator == "+") {
        result = leftOperand + rightOperand;
    } else if (currentOperator == "-") {
        result = leftOperand - rightOperand;
    } else if (currentOperator == "*") {
        result = leftOperand * rightOperand;
    } else if (currentOperator == "/") {
        if (rightOperand != 0) {
            result = leftOperand / rightOperand;
        } else {
            resultDisplay->setText("Деление на 0!");
            return;
        }
    }

    resultDisplay->setText(QString::number(result));
    lastOperation->setText(lastOperation->text() + " " + QString::number(rightOperand));
    waitingForOperand = true;
}

void CalculatorForm::onClearClicked() {
    currentExpression->clear();
    lastOperation->clear();
    resultDisplay->clear();
    leftOperand = 0;
    currentOperator.clear();
    waitingForOperand = true;
}
