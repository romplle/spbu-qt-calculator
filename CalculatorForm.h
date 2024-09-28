#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>

class CalculatorForm : public QMainWindow {
    Q_OBJECT
public:
    explicit CalculatorForm(QWidget *parent = nullptr);

private slots:
    void onDigitClicked();
    void onOperatorClicked();
    void onEqualClicked();
    void onClearClicked();

private:
    QLineEdit *currentExpression;
    QLineEdit *lastOperation;
    QLineEdit *resultDisplay;
    QGridLayout *gridLayout;
    QWidget *centralWidget;

    QString currentOperator;
    double leftOperand;
    bool waitingForOperand;

    void createLayout();
};

#endif // CALCULATORFORM_H
