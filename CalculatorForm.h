#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class CalculatorForm : public QMainWindow {
    Q_OBJECT
public:
    CalculatorForm(QWidget *parent = nullptr);

private:
    QLineEdit *display;
    QGridLayout *gridLayout;
    QWidget *centralWidget;

    void createLayout();
};

#endif // CALCULATORFORM_H
