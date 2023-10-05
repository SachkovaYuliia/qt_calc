
#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QRegularExpression>
//#include <QRegularExpressionMatch>
#include <QRegularExpressionValidator>
QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow

{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();

private slots:
    void on_pushButton_plus_clicked();
    //void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_lineEdit_returnPressed();

    void on_pushButton_minus_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::calc *ui;
    QString input, output;
    double  operand1, operand2, result;
    int operand3, operand4;
    int     operation;

    QString r= "^(-?)[1-9][0-9]{1,6}([\\.][0-9]{1,3})?$";
    //QString r="^[^a-zA-Z~!@#$%\^&\*\(\)\+/=:;'\?\[\]\{\} ]{1,7}([,\.][0-9]{1,3})?$";
    //QString r = "^-?[0-9]{1,7}([,\.][0-9]{1,3})?[\+\*\-\/%]?$";
    QRegularExpression regular = QRegularExpression(r);
    QString n= "^(-?)[1-9][1-9]{1,6}([\\.][0-9]{1,3})?$";
    QRegularExpression ne_null = QRegularExpression(n);
//    QString n1= "^(-?)[1-9][1-9]{1,6})?$";
//    QRegularExpression only_int = QRegularExpression(n1);
};

#endif // CALC_H
