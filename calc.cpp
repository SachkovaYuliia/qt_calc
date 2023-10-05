#include "calc.h"
#include "./ui_calc.h"
calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
    //маска #	дозволяє цифри і знаки +,-
    //ui->lineEdit->setInputMask("#");
    QRegularExpression rx("^(-?)[1-9][0-9]{1,7}([\\.][0-9]{1,2})?$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit->setValidator(validator);

}
calc::~calc()
{
//    delete validator;
//    delete validator2;
    delete ui;
}

void calc::on_pushButton_plus_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input+"+");
    operation = 1;
    operand1  = input.toDouble();
    output    = input+"+";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}

void calc::on_pushButton_7_clicked()
{
    input = ui->lineEdit->text();
    operand2 = input.toDouble();
    operand4 = input.toInt();
    output+=input;
    ui->lineEdit_2->setText(output);
    switch (operation) {
    case 1:
        result = operand1 + operand2;
        break;
    case 2:
        result = operand1 - operand2;
        break;
    case 3:
        result = operand1 * operand2;
        break;
    case 4:
        result = operand1 / operand2;
        break;
    case 5:
        result = operand3 % operand4;
        break;
    default:
        break;
    }
    output+="="+QString::number(result);
    ui->lineEdit_2->setText(output);
    ui->lineEdit->  setText(QString::number(result));
    output=input="";
}

void calc::on_lineEdit_returnPressed()
{
    QString temp=ui->lineEdit->text();
    QRegularExpressionMatch obj = regular.match(temp);
    if (obj.hasMatch())
    {
        ui->lineEdit_2->setText("Допустимі дані");
        //qDebug("Число");
    }
    else
    {
        ui->lineEdit_2->setText("Не допустимі дані");
        //qDebug("Не число");
    };
}

void calc::on_pushButton_minus_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input+"-");
    operation = 2;
    operand1  = input.toDouble();
    output    = input+"-";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus(
        );
}


void calc::on_pushButton_3_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input+"*");
    operation = 3;
    operand1  = input.toDouble();
    output    = input+"*";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}


void calc::on_pushButton_4_clicked()
{
    input = ui->lineEdit->text();
    QString n=ui->lineEdit->text();
    QRegularExpressionMatch ne_null = regular.match(n);
    if (ne_null.hasMatch())
    {
        ui->lineEdit_2->setText("Допустимі дані");
    }
    else
    {
        ui->lineEdit_2->setText("На ноль ділити не можна");
    };
    ui->lineEdit->setText(input+"/");
    operation = 4;
    operand1  = input.toDouble();
    output    = input+"/";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}


void calc::on_pushButton_5_clicked()
{
    input = ui->lineEdit->text();

    ui->lineEdit->setText(input+"%");
    operation = 5;
    operand3  = input.toInt();
    output    = input+"%";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}


void calc::on_pushButton_6_clicked()
{
     ui->lineEdit->setText("");
     ui->lineEdit_2->setText("");
}

