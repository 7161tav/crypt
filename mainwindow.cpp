#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcdNumber->display(ui->lineEdit->text().size());

    ui->spinBox_1_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_1_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_1_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_1_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_4->setMaximum(ui->lineEdit->text().size()-1);

    ui->spinBox_a_1_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_1_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_1_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_1_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_4->setMaximum(ui->lineEdit->text().size()-1);

    hide();
    hide_2();

    ui->comboBox->addItem("  ");
    ui->comboBox->addItem("2x2");
    ui->comboBox->addItem("3x3");
    ui->comboBox->addItem("4x4");

    ui->comboBox_2->addItem("  ");
    ui->comboBox_2->addItem("2x2");
    ui->comboBox_2->addItem("3x3");
    ui->comboBox_2->addItem("4x4");

    QRegExp exp("[0-9]+$");
    ui->lineEdit1_Alfa->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit1_Alfa_2->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit1_Alfa_3->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit1_Beta->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit1_Beta_2->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit1_Beta_3->setValidator(new QRegExpValidator(exp, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
        enCription();
    else
        deCription();
}

void MainWindow::enCription()
{
    QString  str = ui->lineEdit->text();
    QString text = ui->lineEdit_input->text();
    int a = ui->lineEdit1_Alfa->text().toInt();
    int b = ui->lineEdit1_Beta->text().toInt();

    QString result;

    int k = 0;
    int index = 0;
    for (int i = 0; i < text.size(); i++)
        for (int j = 0; j < str.size(); j++)
            if (text[i] == str[j])
            {
                index = (a * k + b) % str.size();
                result.append(str[index]);
                k = 0;
                break;
            }
            else
            {
                k++;
                if (k == str.size()+1)
                    result.append(text[i-1]);
            }
    ui->lineEdit_output->setText(result);
}

void MainWindow::deCription()
{
    QString str = ui->lineEdit->text();
    QString text = ui->lineEdit_input->text();
    int a = ui->lineEdit1_Alfa->text().toInt();
    int b = ui->lineEdit1_Beta->text().toInt();
    QString result;
    int k = 0;
    int index = 0;

    for (int i = 0; i < text.size(); i++)
        for (int j = 0; j < str.size(); j++)
            if (text[i] == str[j])
            {
                index = (ext_gcd(str.size(), a, 0, 1))* (k - b);
                while(index < 0) index+=str.size();
                index %= str.size();  
                result.append(str[index]);
                k = 0;
                break;
            }
            else
            {
                k++;
                if (k == str.size()+1)
                    result.append(text[i-1]);
            }
    ui->lineEdit_output->setText(result);
}

int MainWindow::ext_gcd(int a, int b, int x, int y)
{
    int q, r, x1, x2, y1, y2,d;
    if (b == 0)
    {
        d = a, x = 1, y = 0;
        return d;
    }
    x2 = 1, x1 = 0, y2 = 0, y1 = 1;
    while (b > 0)
    {
        q = a / b, r = a - q * b;
        x = x2 - q * x1, y = y2 - q * y1;
        a = b, b = r;
        x2 = x1, x1 = x, y2 = y1, y1 = y;
    }
    d = a, x = x2, y = y2;
    return y;
}

int MainWindow::ext_gcdx(int a, int b, int x, int y)
{
    int q, r, x1, x2, y1, y2, d;
    if (b == 0)
    {
        d = a, x = 1, y = 0;
        return d;
    }
    x2 = 1, x1 = 0, y2 = 0, y1 = 1;
    while (b > 0)
    {
        q = a / b, r = a - q * b;
        x = x2 - q * x1, y = y2 - q * y1;
        a = b, b = r;
        x2 = x1, x1 = x, y2 = y1, y1 = y;
    }
    d = a, x = x2, y = y2;
    return x;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->lcdNumber->display(arg1.size());
    ui->spinBox_1_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_1_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_1_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_1_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_2_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_3_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_4_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_1_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_1_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_1_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_1_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_2_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_3_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_a_4_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_1_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_2_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_3_4->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_1->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_2->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_3->setMaximum(ui->lineEdit->text().size()-1);
    ui->spinBox_b_4_4->setMaximum(ui->lineEdit->text().size()-1);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->radioButton_3->isChecked())
        enCriptionRec();
    else
        deCriptionRec();
}

void MainWindow::enCriptionRec()
{
    QString str = ui->lineEdit->text();
    QString text = ui->lineEdit_2->text();
    int *a = new int[text.size()-1];
    int *b = new int[text.size()-1];
    a[0] = ui->lineEdit1_Alfa_2->text().toInt();
    b[0] = ui->lineEdit1_Beta_2->text().toInt();
    a[1] = ui->lineEdit1_Alfa_3->text().toInt();
    b[1] = ui->lineEdit1_Beta_3->text().toInt();

    for(int i = 2; i < text.size(); i++)
    {
        a[i] = (a[i-1] * a[i-2]) % str.size();
        b[i] = (b[i-1] + b[i-2]) % str.size();
    }

    QString result;

    int k = 0;
    int index = 0;
    for (int i = 0; i < text.size(); i++)
        for (int j = 0; j < str.size(); j++)
            if (text[i] == str[j])
            {
                index = (a[i] * k + b[i]) % str.size();
                result.append(str[index]);
                k = 0;
                break;
            }
            else
            {
                k++;
                if (k == str.size()+1)
                    result.append(text[i-1]);
            }
    ui->lineEdit_3->setText(result);
}

void MainWindow::deCriptionRec()
{
    QString str = ui->lineEdit->text();
    QString text = ui->lineEdit_2->text();
    int *a = new int[text.size()-1];
    int *b = new int[text.size()-1];
    a[0] = ui->lineEdit1_Alfa_2->text().toInt();
    b[0] = ui->lineEdit1_Beta_2->text().toInt();
    a[1] = ui->lineEdit1_Alfa_3->text().toInt();
    b[1] = ui->lineEdit1_Beta_3->text().toInt();

    for(int i = 2; i < text.size(); i++)
    {
        a[i] = (a[i-1] * a[i-2]) % str.size();
        b[i] = (b[i-1] + b[i-2]) % str.size();
    }

    QString result;

    int k = 0;
    int index = 0;

    for (int i = 0; i < text.size(); i++)
        for (int j = 0; j < str.size(); j++)
            if (text[i] == str[j])
            {
                index = (ext_gcd(str.size(), a[i], 0, 1))* (k - b[i]);
                while(index < 0) index+=str.size();
                index %= str.size();
                result.append(str[index]);
                k = 0;
                break;
            }
            else
            {
                k++;
                if (k == str.size()+1)
                    result.append(text[i-1]);
            }
    ui->lineEdit_3->setText(result);
}

void MainWindow::hide()
{
    ui->spinBox_1_1->hide();
    ui->spinBox_1_2->hide();
    ui->spinBox_1_3->hide();
    ui->spinBox_1_4->hide();
    ui->spinBox_2_1->hide();
    ui->spinBox_2_2->hide();
    ui->spinBox_2_3->hide();
    ui->spinBox_2_4->hide();
    ui->spinBox_3_1->hide();
    ui->spinBox_3_2->hide();
    ui->spinBox_3_3->hide();
    ui->spinBox_3_4->hide();
    ui->spinBox_4_1->hide();
    ui->spinBox_4_2->hide();
    ui->spinBox_4_3->hide();
    ui->spinBox_4_4->hide();
}

void MainWindow::hide_2()
{
    ui->spinBox_a_1_1->hide();
    ui->spinBox_a_1_2->hide();
    ui->spinBox_a_1_3->hide();
    ui->spinBox_a_1_4->hide();
    ui->spinBox_a_2_1->hide();
    ui->spinBox_a_2_2->hide();
    ui->spinBox_a_2_3->hide();
    ui->spinBox_a_2_4->hide();
    ui->spinBox_a_3_1->hide();
    ui->spinBox_a_3_2->hide();
    ui->spinBox_a_3_3->hide();
    ui->spinBox_a_3_4->hide();
    ui->spinBox_a_4_1->hide();
    ui->spinBox_a_4_2->hide();
    ui->spinBox_a_4_3->hide();
    ui->spinBox_a_4_4->hide();
    ui->spinBox_b_1_1->hide();
    ui->spinBox_b_1_2->hide();
    ui->spinBox_b_1_3->hide();
    ui->spinBox_b_1_4->hide();
    ui->spinBox_b_2_1->hide();
    ui->spinBox_b_2_2->hide();
    ui->spinBox_b_2_3->hide();
    ui->spinBox_b_2_4->hide();
    ui->spinBox_b_3_1->hide();
    ui->spinBox_b_3_2->hide();
    ui->spinBox_b_3_3->hide();
    ui->spinBox_b_3_4->hide();
    ui->spinBox_b_4_1->hide();
    ui->spinBox_b_4_2->hide();
    ui->spinBox_b_4_3->hide();
    ui->spinBox_b_4_4->hide();
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "  ") hide();
    if(arg1 == "2x2")
    {
        ui->spinBox_1_1->show();
        ui->spinBox_1_2->show();
        ui->spinBox_1_3->hide();
        ui->spinBox_1_4->hide();
        ui->spinBox_2_1->show();
        ui->spinBox_2_2->show();
        ui->spinBox_2_3->hide();
        ui->spinBox_2_4->hide();
        ui->spinBox_3_1->hide();
        ui->spinBox_3_2->hide();
        ui->spinBox_3_3->hide();
        ui->spinBox_3_4->hide();
        ui->spinBox_4_1->hide();
        ui->spinBox_4_2->hide();
        ui->spinBox_4_3->hide();
        ui->spinBox_4_4->hide();
    }
    if(arg1 == "3x3")
    {
        ui->spinBox_1_1->show();
        ui->spinBox_1_2->show();
        ui->spinBox_1_3->show();
        ui->spinBox_1_4->hide();
        ui->spinBox_2_1->show();
        ui->spinBox_2_2->show();
        ui->spinBox_2_3->show();
        ui->spinBox_2_4->hide();
        ui->spinBox_3_1->show();
        ui->spinBox_3_2->show();
        ui->spinBox_3_3->show();
        ui->spinBox_3_4->hide();
        ui->spinBox_4_1->hide();
        ui->spinBox_4_2->hide();
        ui->spinBox_4_3->hide();
        ui->spinBox_4_4->hide();
    }
    if(arg1 == "4x4")
    {
        ui->spinBox_1_1->show();
        ui->spinBox_1_2->show();
        ui->spinBox_1_3->show();
        ui->spinBox_1_4->show();
        ui->spinBox_2_1->show();
        ui->spinBox_2_2->show();
        ui->spinBox_2_3->show();
        ui->spinBox_2_4->show();
        ui->spinBox_3_1->show();
        ui->spinBox_3_2->show();
        ui->spinBox_3_3->show();
        ui->spinBox_3_4->show();
        ui->spinBox_4_1->show();
        ui->spinBox_4_2->show();
        ui->spinBox_4_3->show();
        ui->spinBox_4_4->show();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    bool a = IsPrime(ui->lineEdit->text().size());
    if(a)
    {
        int a_1_1 = ui->spinBox_1_1->value();
        int a_1_2 = ui->spinBox_1_2->value();
        int a_1_3 = ui->spinBox_1_3->value();
        int a_1_4 = ui->spinBox_1_4->value();
        int a_2_1 = ui->spinBox_2_1->value();
        int a_2_2 = ui->spinBox_2_2->value();
        int a_2_3 = ui->spinBox_2_3->value();
        int a_2_4 = ui->spinBox_2_4->value();
        int a_3_1 = ui->spinBox_3_1->value();
        int a_3_2 = ui->spinBox_3_2->value();
        int a_3_3 = ui->spinBox_3_3->value();
        int a_3_4 = ui->spinBox_3_4->value();
        int a_4_1 = ui->spinBox_4_1->value();
        int a_4_2 = ui->spinBox_4_2->value();
        int a_4_3 = ui->spinBox_4_3->value();
        int a_4_4 = ui->spinBox_4_4->value();

        int b_1_1, b_1_2, b_1_3, b_1_4,
            b_2_1, b_2_2, b_2_3, b_2_4,
            b_3_1, b_3_2, b_3_3, b_3_4,
            b_4_1, b_4_2, b_4_3, b_4_4;

        int det = 0, x = 0;

        if(ui->comboBox->currentText() == "  ")
            QMessageBox::information(this,tr("Информация"),tr("Матрица не задана"));
        if(ui->comboBox->currentText() == "2x2")
        {
            det = a_1_1 * a_2_2 - a_1_2 * a_2_1;
            if(det == 0)
                QMessageBox::information(this,tr("Информация"),tr("Определитель матрицы нулевой"));
            else
            {
                QString str = ui->lineEdit->text();
                QString text = ui->lineEdit_4->text();
                QString result;
                if(ui->radioButton_6->isChecked())
                {
                    if(text.size() % 2 == 1) text.append(" ");
                    for (int i = 0; i < text.size(); i+=2)
                    {
                        result.append(str[(str.indexOf(text[i]) * a_1_1 + str.indexOf(text[i+1]) * a_2_1) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_2 + str.indexOf(text[i+1]) * a_2_2) % str.size()]);
                    }
                    ui->lineEdit_5->setText(result);
                }
                else
                {
                    if(text.size() % 2 == 1)
                        QMessageBox::information(this,tr("Информация"),tr("Шифр-текст не кратен 2"));
                    else
                    {
                        if(det < 0)
                            x = - ext_gcdx(abs(det), str.size(), 0, 1);
                        else
                            x = ext_gcdx(det, str.size(), 0, 1);
                        if(det > 0 && x < 0) x += str.size();
                        else if(det < 0 && x < 0) x = -x;

                        b_1_1 = (a_2_2 * x) % str.size();
                        b_1_2 = (- a_1_2 * x) % str.size();
                        b_2_1 = (- a_2_1 * x) % str.size();
                        b_2_2 = (a_1_1 * x) % str.size();

                        if(b_1_1 < 0) b_1_1+=str.size();
                        if(b_1_2 < 0) b_1_2+=str.size();
                        if(b_2_1 < 0) b_2_1+=str.size();
                        if(b_2_2 < 0) b_2_2+=str.size();

                        for (int i = 0; i < text.size(); i+=2)
                        {
                            result.append(str[(str.indexOf(text[i]) * b_1_1 + str.indexOf(text[i+1]) * b_2_1) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_2 + str.indexOf(text[i+1]) * b_2_2) % str.size()]);
                        }

                        ui->lineEdit_5->setText(result);
                    }

                }

            }
        }
        if(ui->comboBox->currentText() == "3x3")
        {
            det = a_1_1 * (a_2_2 * a_3_3 - a_2_3 * a_3_2) -
                  a_1_2 * (a_2_1 * a_3_3 - a_2_3 * a_3_1) +
                  a_1_3 * (a_2_1 * a_3_2 - a_2_2 * a_3_1);
            if(det == 0)
                QMessageBox::information(this,tr("Информация"),tr("Определитель матрицы нулевой"));
            else
            {
                QString str = ui->lineEdit->text();
                QString text = ui->lineEdit_4->text();
                QString result;
                if(ui->radioButton_6->isChecked())
                {
                    if(text.size() % 3 == 2) text.append(" ");
                    if(text.size() % 3 == 1) text.append("  ");
                    for (int i = 0; i < text.size(); i+=3)
                    {
                        result.append(str[(str.indexOf(text[i]) * a_1_1 + str.indexOf(text[i+1]) * a_2_1 + str.indexOf(text[i+2]) * a_3_1) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_2 + str.indexOf(text[i+1]) * a_2_2 + str.indexOf(text[i+2]) * a_3_2) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_3 + str.indexOf(text[i+1]) * a_2_3 + str.indexOf(text[i+2]) * a_3_3) % str.size()]);
                    }
                    ui->lineEdit_5->setText(result);
                }
                else
                {
                    if(text.size() % 3 == 0)
                    {
                        if(det < 0)
                            x = - ext_gcdx(abs(det), str.size(), 0, 1);
                        else
                            x = ext_gcdx(det, str.size(), 0, 1);
                        if(det > 0 && x < 0) x += str.size();
                        else if(det < 0 && x < 0) x = -x;

                        b_1_1 = ((a_2_2 * a_3_3 - a_2_3 * a_3_2) * x) % str.size();                        
                        b_1_2 = ((a_1_3 * a_3_2 - a_1_2 * a_3_3) * x) % str.size();
                        b_1_3 = ((a_1_2 * a_2_3 - a_1_3 * a_2_2) * x) % str.size();
                        b_2_1 = ((a_2_3 * a_3_1 - a_2_1 * a_3_3) * x) % str.size();
                        b_2_2 = ((a_1_1 * a_3_3 - a_1_3 * a_3_1) * x) % str.size();
                        b_2_3 = ((a_1_3 * a_2_1 - a_1_1 * a_2_3) * x) % str.size();
                        b_3_1 = ((a_2_1 * a_3_2 - a_2_2 * a_3_1) * x) % str.size();
                        b_3_2 = ((a_1_2 * a_3_1 - a_1_1 * a_3_2) * x) % str.size();
                        b_3_3 = ((a_1_1 * a_2_2 - a_1_2 * a_2_1) * x) % str.size();

                        //qDebug() << (a_2_2 * a_3_3 - a_2_3 * a_3_2) << (a_1_3 * a_3_2 - a_1_2 * a_3_3) << (a_1_2 * a_2_3 - a_1_3 * a_2_2);
                        //qDebug() << (a_2_3 * a_3_1 - a_2_1 * a_3_3) << (a_1_1 * a_3_3 - a_1_3 * a_3_1) << (a_1_3 * a_2_1 - a_1_1 * a_2_3);
                        //qDebug() << (a_2_1 * a_3_2 - a_2_2 * a_3_1) << (a_1_2 * a_3_1 - a_1_1 * a_3_2) << (a_1_1 * a_2_2 - a_1_2 * a_2_1);
                        //qDebug() << "  ";

                        //qDebug() << (a_2_2 * a_3_3 - a_2_3 * a_3_2)% str.size() << (a_1_3 * a_3_2 - a_1_2 * a_3_3)% str.size() << (a_1_2 * a_2_3 - a_1_3 * a_2_2)% str.size();
                        //qDebug() << (a_2_3 * a_3_1 - a_2_1 * a_3_3)% str.size() << (a_1_1 * a_3_3 - a_1_3 * a_3_1)% str.size() << (a_1_3 * a_2_1 - a_1_1 * a_2_3)% str.size();
                        //qDebug() << (a_2_1 * a_3_2 - a_2_2 * a_3_1)% str.size() << (a_1_2 * a_3_1 - a_1_1 * a_3_2)% str.size() << (a_1_1 * a_2_2 - a_1_2 * a_2_1)% str.size();
                        //qDebug() << "  ";

                        //qDebug() << (a_2_2 * a_3_3 - a_2_3 * a_3_2)% str.size()* x << (a_1_3 * a_3_2 - a_1_2 * a_3_3)% str.size()* x << (a_1_2 * a_2_3 - a_1_3 * a_2_2)% str.size()* x;
                        //qDebug() << (a_2_3 * a_3_1 - a_2_1 * a_3_3)% str.size()* x << (a_1_1 * a_3_3 - a_1_3 * a_3_1)% str.size()* x << (a_1_3 * a_2_1 - a_1_1 * a_2_3)% str.size()* x;
                        //qDebug() << (a_2_1 * a_3_2 - a_2_2 * a_3_1)% str.size()* x << (a_1_2 * a_3_1 - a_1_1 * a_3_2)% str.size()* x << (a_1_1 * a_2_2 - a_1_2 * a_2_1)% str.size()* x;

                        if(b_1_1 < 0) b_1_1+=str.size();
                        if(b_1_2 < 0) b_1_2+=str.size();
                        if(b_1_3 < 0) b_1_3+=str.size();
                        if(b_2_1 < 0) b_2_1+=str.size();
                        if(b_2_2 < 0) b_2_2+=str.size();
                        if(b_2_3 < 0) b_2_3+=str.size();
                        if(b_3_1 < 0) b_3_1+=str.size();
                        if(b_3_2 < 0) b_3_2+=str.size();
                        if(b_3_3 < 0) b_3_3+=str.size();

                        //qDebug() << b_1_1 << b_1_2 << b_1_3;
                        //qDebug() << b_2_1 << b_2_2 << b_2_3;
                        //qDebug() << b_3_1 << b_3_2 << b_3_3;

                        for (int i = 0; i < text.size(); i+=3)
                        {
                            result.append(str[(str.indexOf(text[i]) * b_1_1 + str.indexOf(text[i+1]) * b_2_1 + str.indexOf(text[i+2]) * b_3_1) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_2 + str.indexOf(text[i+1]) * b_2_2 + str.indexOf(text[i+2]) * b_3_2) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_3 + str.indexOf(text[i+1]) * b_2_3 + str.indexOf(text[i+2]) * b_3_3) % str.size()]);
                        }
                        ui->lineEdit_5->setText(result);
                    }
                    else
                        QMessageBox::information(this,tr("Информация"),tr("Шифр-текст не кратен 3"));
                }
            }
        }
        if(ui->comboBox->currentText() == "4x4")
        {
            det = a_1_1 * (a_2_2 * (a_3_3 * a_4_4 - a_3_4 * a_4_3) -
                           a_2_3 * (a_3_2 * a_4_4 - a_3_4 * a_4_2) +
                           a_2_4 * (a_3_2 * a_4_3 - a_3_3 * a_4_2))
                - a_1_2 * (a_2_1 * (a_3_3 * a_4_4 - a_3_4 * a_4_3) -
                           a_2_3 * (a_3_1 * a_4_4 - a_3_4 * a_4_1) +
                           a_2_4 * (a_3_1 * a_4_3 - a_3_3 * a_4_1))
                + a_1_3 * (a_2_1 * (a_3_2 * a_4_4 - a_3_4 * a_4_2) -
                           a_2_2 * (a_3_1 * a_4_4 - a_3_4 * a_4_1) +
                           a_2_4 * (a_3_1 * a_4_2 - a_3_2 * a_4_1))
                - a_1_4 * (a_2_1 * (a_3_2 * a_4_3 - a_3_3 * a_4_2) -
                           a_2_2 * (a_3_1 * a_4_3 - a_3_3 * a_4_1) +
                           a_2_3 * (a_3_1 * a_4_2 - a_3_2 * a_4_1));
            if(det == 0)
                QMessageBox::information(this,tr("Информация"),tr("Определитель матрицы нулевой"));
            else
            {
                QString str = ui->lineEdit->text();
                QString text = ui->lineEdit_4->text();
                QString result;
                if(ui->radioButton_6->isChecked())
                {
                    if(text.size() % 4 == 1) text.append("   ");
                    if(text.size() % 4 == 2) text.append("  ");
                    if(text.size() % 4 == 3) text.append(" ");
                    for (int i = 0; i < text.size(); i+=4)
                    {
                        result.append(str[(str.indexOf(text[i]) * a_1_1 + str.indexOf(text[i+1]) * a_2_1 + str.indexOf(text[i+2]) * a_3_1 + str.indexOf(text[i+3]) * a_4_1) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_2 + str.indexOf(text[i+1]) * a_2_2 + str.indexOf(text[i+2]) * a_3_2 + str.indexOf(text[i+3]) * a_4_2) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_3 + str.indexOf(text[i+1]) * a_2_3 + str.indexOf(text[i+2]) * a_3_3 + str.indexOf(text[i+3]) * a_4_3) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_4 + str.indexOf(text[i+1]) * a_2_4 + str.indexOf(text[i+2]) * a_3_4 + str.indexOf(text[i+3]) * a_4_4) % str.size()]);
                    }
                    ui->lineEdit_5->setText(result);
                }
                else
                {
                    if(text.size() % 4 == 0)
                    {
                        if(det < 0)
                            x = - ext_gcdx(abs(det), str.size(), 0, 1);
                        else
                            x = ext_gcdx(det, str.size(), 0, 1);
                        if(det > 0 && x < 0) x += str.size();
                        else if(det < 0 && x < 0) x = -x;

                        b_1_1 = ((a_2_2 * (a_3_3 * a_4_4 - a_3_4 * a_4_3) -
                                  a_2_3 * (a_3_2 * a_4_4 - a_3_4 * a_4_2) +
                                  a_2_4 * (a_3_2 * a_4_3 - a_3_3 * a_4_2)) * x) % str.size();
                        b_1_2 = ((- a_1_2 * (a_3_3 * a_4_4 - a_3_4 * a_4_3) +
                                  a_1_3 * (a_3_2 * a_4_4 - a_3_4 * a_4_2) -
                                  a_1_4 * (a_3_2 * a_4_3 - a_3_3 * a_4_2)) * x) % str.size();
                        b_1_3 = ((a_1_2 * (a_2_3 * a_4_4 - a_2_4 * a_4_3) -
                                  a_1_3 * (a_2_2 * a_4_4 - a_2_4 * a_4_2) +
                                  a_1_4 * (a_2_2 * a_4_3 - a_2_3 * a_4_2)) * x) % str.size();
                        b_1_4 = ((- a_1_2 * (a_2_3 * a_3_4 - a_2_4 * a_3_3) +
                                  a_1_3 * (a_2_2 * a_3_4 - a_2_4 * a_3_2) -
                                  a_1_4 * (a_2_2 * a_3_3 - a_2_3 * a_3_2)) * x) % str.size();
                        b_2_1 = ((- a_2_1 * (a_3_3 * a_4_4 - a_3_4 * a_4_3) +
                                  a_2_3 * (a_3_1 * a_4_4 - a_3_4 * a_4_1) -
                                  a_2_4 * (a_3_1 * a_4_3 - a_3_3 * a_4_1)) * x) % str.size();
                        b_2_2 = ((a_1_1 * (a_3_3 * a_4_4 - a_3_4 * a_4_3) -
                                  a_1_3 * (a_3_1 * a_4_4 - a_3_4 * a_4_1) +
                                  a_1_4 * (a_3_1 * a_4_3 - a_3_3 * a_4_1)) * x) % str.size();
                        b_2_3 = ((- a_1_1 * (a_2_3 * a_4_4 - a_2_4 * a_4_3) +
                                  a_1_3 * (a_2_1 * a_4_4 - a_2_4 * a_4_1) -
                                  a_1_4 * (a_2_1 * a_4_3 - a_2_3 * a_4_1)) * x) % str.size();
                        b_2_4 = ((a_1_1 * (a_2_3 * a_3_4 - a_2_4 * a_3_3) -
                                  a_1_3 * (a_2_1 * a_3_4 - a_2_4 * a_3_1) +
                                  a_1_4 * (a_2_1 * a_3_3 - a_2_3 * a_3_1)) * x) % str.size();
                        b_3_1 = ((a_2_1 * (a_3_2 * a_4_4 - a_3_4 * a_4_2) -
                                  a_2_2 * (a_3_1 * a_4_4 - a_3_4 * a_4_1) +
                                  a_2_4 * (a_3_1 * a_4_2 - a_3_2 * a_4_1)) * x) % str.size();
                        b_3_2 = ((- a_1_1 * (a_3_2 * a_4_4 - a_3_4 * a_4_2) +
                                  a_1_2 * (a_3_1 * a_4_4 - a_3_4 * a_4_1) -
                                  a_1_4 * (a_3_1 * a_4_2 - a_3_2 * a_4_1)) * x) % str.size();
                        b_3_3 = ((a_1_1 * (a_2_2 * a_4_4 - a_2_4 * a_4_2) -
                                  a_1_2 * (a_2_1 * a_4_4 - a_2_4 * a_4_1) +
                                  a_1_4 * (a_2_1 * a_4_2 - a_2_2 * a_4_1)) * x) % str.size();
                        b_3_4 = ((- a_1_1 * (a_2_2 * a_3_4 - a_2_4 * a_3_2) +
                                  a_1_2 * (a_2_1 * a_3_4 - a_2_4 * a_3_1) -
                                  a_1_4 * (a_2_1 * a_3_2 - a_2_2 * a_3_1)) * x) % str.size();
                        b_4_1 = ((- a_2_1 * (a_3_2 * a_4_3 - a_3_3 * a_4_2) +
                                  a_2_2 * (a_3_1 * a_4_3 - a_3_3 * a_4_1) -
                                  a_2_3 * (a_3_1 * a_4_2 - a_3_2 * a_4_1)) * x) % str.size();
                        b_4_2 = ((a_1_1 * (a_3_2 * a_4_3 - a_3_3 * a_4_2) -
                                  a_1_2 * (a_3_1 * a_4_3 - a_3_3 * a_4_1) +
                                  a_1_3 * (a_3_1 * a_4_2 - a_3_2 * a_4_1)) * x) % str.size();
                        b_4_3 = ((-a_1_1 * (a_2_2 * a_4_3 - a_2_3 * a_4_2) +
                                  a_1_2 * (a_2_1 * a_4_3 - a_2_3 * a_4_1) -
                                  a_1_3 * (a_2_1 * a_4_2 - a_2_2 * a_4_1)) * x) % str.size();
                        b_4_4 = ((a_1_1 * (a_2_2 * a_3_3 - a_2_3 * a_3_2) -
                                  a_1_2 * (a_2_1 * a_3_3 - a_2_3 * a_3_1) +
                                  a_1_3 * (a_2_1 * a_3_2 - a_2_2 * a_3_1)) * x) % str.size();

                        if(b_1_1 < 0) b_1_1+=str.size();
                        if(b_1_2 < 0) b_1_2+=str.size();
                        if(b_1_3 < 0) b_1_3+=str.size();
                        if(b_1_4 < 0) b_1_4+=str.size();
                        if(b_2_1 < 0) b_2_1+=str.size();
                        if(b_2_2 < 0) b_2_2+=str.size();
                        if(b_2_3 < 0) b_2_3+=str.size();
                        if(b_2_4 < 0) b_2_4+=str.size();
                        if(b_3_1 < 0) b_3_1+=str.size();
                        if(b_3_2 < 0) b_3_2+=str.size();
                        if(b_3_3 < 0) b_3_3+=str.size();
                        if(b_3_4 < 0) b_3_4+=str.size();
                        if(b_4_1 < 0) b_4_1+=str.size();
                        if(b_4_2 < 0) b_4_2+=str.size();
                        if(b_4_3 < 0) b_4_3+=str.size();
                        if(b_4_4 < 0) b_4_4+=str.size();

                        for (int i = 0; i < text.size(); i+=4)
                        {
                            result.append(str[(str.indexOf(text[i]) * b_1_1 + str.indexOf(text[i+1]) * b_2_1 + str.indexOf(text[i+2]) * b_3_1 + str.indexOf(text[i+3]) * b_4_1) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_2 + str.indexOf(text[i+1]) * b_2_2 + str.indexOf(text[i+2]) * b_3_2 + str.indexOf(text[i+3]) * b_4_2) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_3 + str.indexOf(text[i+1]) * b_2_3 + str.indexOf(text[i+2]) * b_3_3 + str.indexOf(text[i+3]) * b_4_3) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_4 + str.indexOf(text[i+1]) * b_2_4 + str.indexOf(text[i+2]) * b_3_4 + str.indexOf(text[i+3]) * b_4_4) % str.size()]);
                        }

                        ui->lineEdit_5->setText(result);
                    }
                    else
                        QMessageBox::information(this,tr("Информация"),tr("Шифр-текст не кратен 4"));
                }
            }
        }
    }
    else
        QMessageBox::information(this,tr("Информация"),tr("Количество символов в алфавите не является простым числом"));
}

bool MainWindow::IsPrime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0 && i != number)
            return false;
    }
    return true;
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1 == "  ") hide();
    if(arg1 == "2x2")
    {
        ui->spinBox_a_1_1->show();
        ui->spinBox_a_1_2->show();
        ui->spinBox_a_1_3->hide();
        ui->spinBox_a_1_4->hide();
        ui->spinBox_a_2_1->show();
        ui->spinBox_a_2_2->show();
        ui->spinBox_a_2_3->hide();
        ui->spinBox_a_2_4->hide();
        ui->spinBox_a_3_1->hide();
        ui->spinBox_a_3_2->hide();
        ui->spinBox_a_3_3->hide();
        ui->spinBox_a_3_4->hide();
        ui->spinBox_a_4_1->hide();
        ui->spinBox_a_4_2->hide();
        ui->spinBox_a_4_3->hide();
        ui->spinBox_a_4_4->hide();
        ui->spinBox_b_1_1->show();
        ui->spinBox_b_1_2->show();
        ui->spinBox_b_1_3->hide();
        ui->spinBox_b_1_4->hide();
        ui->spinBox_b_2_1->show();
        ui->spinBox_b_2_2->show();
        ui->spinBox_b_2_3->hide();
        ui->spinBox_b_2_4->hide();
        ui->spinBox_b_3_1->hide();
        ui->spinBox_b_3_2->hide();
        ui->spinBox_b_3_3->hide();
        ui->spinBox_b_3_4->hide();
        ui->spinBox_b_4_1->hide();
        ui->spinBox_b_4_2->hide();
        ui->spinBox_b_4_3->hide();
        ui->spinBox_b_4_4->hide();
    }
    if(arg1 == "3x3")
    {
        ui->spinBox_b_1_1->show();
        ui->spinBox_b_1_2->show();
        ui->spinBox_b_1_3->show();
        ui->spinBox_b_1_4->hide();
        ui->spinBox_b_2_1->show();
        ui->spinBox_b_2_2->show();
        ui->spinBox_b_2_3->show();
        ui->spinBox_b_2_4->hide();
        ui->spinBox_b_3_1->show();
        ui->spinBox_b_3_2->show();
        ui->spinBox_b_3_3->show();
        ui->spinBox_b_3_4->hide();
        ui->spinBox_b_4_1->hide();
        ui->spinBox_b_4_2->hide();
        ui->spinBox_b_4_3->hide();
        ui->spinBox_b_4_4->hide();
        ui->spinBox_a_1_1->show();
        ui->spinBox_a_1_2->show();
        ui->spinBox_a_1_3->show();
        ui->spinBox_a_1_4->hide();
        ui->spinBox_a_2_1->show();
        ui->spinBox_a_2_2->show();
        ui->spinBox_a_2_3->show();
        ui->spinBox_a_2_4->hide();
        ui->spinBox_a_3_1->show();
        ui->spinBox_a_3_2->show();
        ui->spinBox_a_3_3->show();
        ui->spinBox_a_3_4->hide();
        ui->spinBox_a_4_1->hide();
        ui->spinBox_a_4_2->hide();
        ui->spinBox_a_4_3->hide();
        ui->spinBox_a_4_4->hide();
    }
    if(arg1 == "4x4")
    {
        ui->spinBox_a_1_1->show();
        ui->spinBox_a_1_2->show();
        ui->spinBox_a_1_3->show();
        ui->spinBox_a_1_4->show();
        ui->spinBox_a_2_1->show();
        ui->spinBox_a_2_2->show();
        ui->spinBox_a_2_3->show();
        ui->spinBox_a_2_4->show();
        ui->spinBox_a_3_1->show();
        ui->spinBox_a_3_2->show();
        ui->spinBox_a_3_3->show();
        ui->spinBox_a_3_4->show();
        ui->spinBox_a_4_1->show();
        ui->spinBox_a_4_2->show();
        ui->spinBox_a_4_3->show();
        ui->spinBox_a_4_4->show();
        ui->spinBox_b_1_1->show();
        ui->spinBox_b_1_2->show();
        ui->spinBox_b_1_3->show();
        ui->spinBox_b_1_4->show();
        ui->spinBox_b_2_1->show();
        ui->spinBox_b_2_2->show();
        ui->spinBox_b_2_3->show();
        ui->spinBox_b_2_4->show();
        ui->spinBox_b_3_1->show();
        ui->spinBox_b_3_2->show();
        ui->spinBox_b_3_3->show();
        ui->spinBox_b_3_4->show();
        ui->spinBox_b_4_1->show();
        ui->spinBox_b_4_2->show();
        ui->spinBox_b_4_3->show();
        ui->spinBox_b_4_4->show();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    //bool a = IsPrime(ui->lineEdit->text().size());
    bool a = true;
    if(a)
    {
        if(ui->comboBox_2->currentText() == "  ")
            QMessageBox::information(this,tr("Информация"),tr("Матрица не задана"));

        int temp = 0;
        QString text = ui->lineEdit_6->text();
        QString str = ui->lineEdit->text();
        QString result;

        if(ui->comboBox_2->currentText() == "2x2" && text.size() % 2 == 1)
            text.append(" ");

        if(ui->comboBox_2->currentText() == "3x3" && text.size() % 3 == 1)
            text.append("  ");

        if(ui->comboBox_2->currentText() == "3x3" && text.size() % 3 == 2)
            text.append(" ");

        if(ui->comboBox_2->currentText() == "4x4" && text.size() % 4 == 1)
            text.append("   ");

        if(ui->comboBox_2->currentText() == "4x4" && text.size() % 4 == 2)
            text.append("  ");

        if(ui->comboBox_2->currentText() == "4x4" && text.size() % 4 == 3)
            text.append(" ");

        if(ui->comboBox_2->currentText() == "2x2")
            temp = text.size() / 2;
        if(ui->comboBox_2->currentText() == "3x3")
            temp = text.size() / 3;
        if(ui->comboBox_2->currentText() == "4x4")
            temp = text.size() / 4;

        int *a_1_1 = new int[temp-1];
        int *a_1_2 = new int[temp-1];
        int *a_1_3 = new int[temp-1];
        int *a_1_4 = new int[temp-1];
        int *a_2_1 = new int[temp-1];
        int *a_2_2 = new int[temp-1];
        int *a_2_3 = new int[temp-1];
        int *a_2_4 = new int[temp-1];
        int *a_3_1 = new int[temp-1];
        int *a_3_2 = new int[temp-1];
        int *a_3_3 = new int[temp-1];
        int *a_3_4 = new int[temp-1];
        int *a_4_1 = new int[temp-1];
        int *a_4_2 = new int[temp-1];
        int *a_4_3 = new int[temp-1];
        int *a_4_4 = new int[temp-1];

        int *b_1_1 = new int[temp-1];
        int *b_1_2 = new int[temp-1];
        int *b_1_3 = new int[temp-1];
        int *b_1_4 = new int[temp-1];
        int *b_2_1 = new int[temp-1];
        int *b_2_2 = new int[temp-1];
        int *b_2_3 = new int[temp-1];
        int *b_2_4 = new int[temp-1];
        int *b_3_1 = new int[temp-1];
        int *b_3_2 = new int[temp-1];
        int *b_3_3 = new int[temp-1];
        int *b_3_4 = new int[temp-1];
        int *b_4_1 = new int[temp-1];
        int *b_4_2 = new int[temp-1];
        int *b_4_3 = new int[temp-1];
        int *b_4_4 = new int[temp-1];

        int *det = new int[temp-1];
        int *x = new int[temp-1];

        a_1_1[0] = ui->spinBox_a_1_1->value();
        a_1_2[0] = ui->spinBox_a_1_2->value();
        a_1_3[0] = ui->spinBox_a_1_3->value();
        a_1_4[0] = ui->spinBox_a_1_4->value();
        a_2_1[0] = ui->spinBox_a_2_1->value();
        a_2_2[0] = ui->spinBox_a_2_2->value();
        a_2_3[0] = ui->spinBox_a_2_3->value();
        a_2_4[0] = ui->spinBox_a_2_4->value();
        a_3_1[0] = ui->spinBox_a_3_1->value();
        a_3_2[0] = ui->spinBox_a_3_2->value();
        a_3_3[0] = ui->spinBox_a_3_3->value();
        a_3_4[0] = ui->spinBox_a_3_4->value();
        a_4_1[0] = ui->spinBox_a_4_1->value();
        a_4_2[0] = ui->spinBox_a_4_2->value();
        a_4_3[0] = ui->spinBox_a_4_3->value();
        a_4_4[0] = ui->spinBox_a_4_4->value();

        a_1_1[1] = ui->spinBox_b_1_1->value();
        a_1_2[1] = ui->spinBox_b_1_2->value();
        a_1_3[1] = ui->spinBox_b_1_3->value();
        a_1_4[1] = ui->spinBox_b_1_4->value();
        a_2_1[1] = ui->spinBox_b_2_1->value();
        a_2_2[1] = ui->spinBox_b_2_2->value();
        a_2_3[1] = ui->spinBox_b_2_3->value();
        a_2_4[1] = ui->spinBox_b_2_4->value();
        a_3_1[1] = ui->spinBox_b_3_1->value();
        a_3_2[1] = ui->spinBox_b_3_2->value();
        a_3_3[1] = ui->spinBox_b_3_3->value();
        a_3_4[1] = ui->spinBox_b_3_4->value();
        a_4_1[1] = ui->spinBox_b_4_1->value();
        a_4_2[1] = ui->spinBox_b_4_2->value();
        a_4_3[1] = ui->spinBox_b_4_3->value();
        a_4_4[1] = ui->spinBox_b_4_4->value();

        if(ui->comboBox_2->currentText() == "2x2")
        {
            for(int i = 2; i < temp; i++)
            {
                a_1_1[i] = (a_1_1[i-1] * a_1_1[i-2] + a_1_2[i-1] * a_2_1[i-2]) % str.size();
                a_1_2[i] = (a_1_1[i-1] * a_1_2[i-2] + a_1_2[i-1] * a_2_2[i-2]) % str.size();
                a_2_1[i] = (a_2_1[i-1] * a_1_1[i-2] + a_2_2[i-1] * a_2_1[i-2]) % str.size();
                a_2_2[i] = (a_2_1[i-1] * a_1_2[i-2] + a_2_2[i-1] * a_2_2[i-2]) % str.size();
            }

            for(int i = 0; i < temp; i++)
            {
                det[i] = a_1_1[i] * a_2_2[i] - a_1_2[i] * a_2_1[i];
            }
            if(det[0] == 0 || det[1] == 0)
                QMessageBox::information(this,tr("Информация"),tr("Определитель одной из матриц нулевой"));
            else
            {
               if(ui->radioButton_7->isChecked())
                {                    
                    for (int i = 0, j= 0; i < text.size(); i+=2, j++)
                    {
                        result.append(str[(str.indexOf(text[i]) * a_1_1[j] + str.indexOf(text[i+1]) * a_2_1[j]) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_2[j] + str.indexOf(text[i+1]) * a_2_2[j]) % str.size()]);
                    }
                    ui->lineEdit_7->setText(result);
                }
                else
                {
                    if(text.size() % 2 == 1)
                        QMessageBox::information(this,tr("Информация"),tr("Шифр-текст не кратен 2"));
                    else
                    {
                        for(int i = 0; i < temp; i++)
                        {
                            if(det[i] < 0)
                                x[i] = - ext_gcdx(abs(det[i]), str.size(), 0, 1);
                            else
                                x[i] = ext_gcdx(det[i], str.size(), 0, 1);
                            if(det[i] > 0 && x[i] < 0) x[i] += str.size();
                            else if(det[i] < 0 && x[i] < 0) x[i] = -x[i];
                        }

                        for(int i = 0; i < 2; i++)
                        {
                            b_1_1[i] = (a_2_2[i] * x[i]) % str.size();
                            b_1_2[i] = (- a_1_2[i] * x[i]) % str.size();
                            b_2_1[i] = (- a_2_1[i] * x[i]) % str.size();
                            b_2_2[i] = (a_1_1[i] * x[i]) % str.size();

                            if(b_1_1[i] < 0) b_1_1[i]+=str.size();
                            if(b_1_2[i] < 0) b_1_2[i]+=str.size();
                            if(b_2_1[i] < 0) b_2_1[i]+=str.size();
                            if(b_2_2[i] < 0) b_2_2[i]+=str.size();
                        }

                        for(int i = 2; i < temp; i++)
                        {
                            b_1_1[i] = (b_1_1[i-2] * b_1_1[i-1] + b_1_2[i-2] * b_2_1[i-1]) % str.size();
                            b_1_2[i] = (b_1_1[i-2] * b_1_2[i-1] + b_1_2[i-2] * b_2_2[i-1]) % str.size();
                            b_2_1[i] = (b_2_1[i-2] * b_1_1[i-1] + b_2_2[i-2] * b_2_1[i-1]) % str.size();
                            b_2_2[i] = (b_2_1[i-2] * b_1_2[i-1] + b_2_2[i-2] * b_2_2[i-1]) % str.size();
                        }

                        for (int i = 0, j= 0; i < text.size(); i+=2, j++)
                        {
                            result.append(str[(str.indexOf(text[i]) * b_1_1[j] + str.indexOf(text[i+1]) * b_2_1[j]) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_2[j] + str.indexOf(text[i+1]) * b_2_2[j]) % str.size()]);
                        }

                        ui->lineEdit_7->setText(result);

                    }

                }

            }
        }
        if(ui->comboBox_2->currentText() == "3x3")
        {
            for(int i = 2; i < temp; i++)
            {
                a_1_1[i] = (a_1_1[i-1] * a_1_1[i-2] + a_1_2[i-1] * a_2_1[i-2] + a_1_3[i-1] * a_3_1[i-2]) % str.size();
                a_1_2[i] = (a_1_1[i-1] * a_1_2[i-2] + a_1_2[i-1] * a_2_2[i-2] + a_1_3[i-1] * a_3_2[i-2]) % str.size();
                a_1_3[i] = (a_1_1[i-1] * a_1_3[i-2] + a_1_2[i-1] * a_2_3[i-2] + a_1_3[i-1] * a_3_3[i-2]) % str.size();
                a_2_1[i] = (a_2_1[i-1] * a_1_1[i-2] + a_2_2[i-1] * a_2_1[i-2] + a_2_3[i-1] * a_3_1[i-2]) % str.size();
                a_2_2[i] = (a_2_1[i-1] * a_1_2[i-2] + a_2_2[i-1] * a_2_2[i-2] + a_2_3[i-1] * a_3_2[i-2]) % str.size();
                a_2_3[i] = (a_2_1[i-1] * a_1_3[i-2] + a_2_2[i-1] * a_2_3[i-2] + a_2_3[i-1] * a_3_3[i-2]) % str.size();
                a_3_1[i] = (a_3_1[i-1] * a_1_1[i-2] + a_3_2[i-1] * a_2_1[i-2] + a_3_3[i-1] * a_3_1[i-2]) % str.size();
                a_3_2[i] = (a_3_1[i-1] * a_1_2[i-2] + a_3_2[i-1] * a_2_2[i-2] + a_3_3[i-1] * a_3_2[i-2]) % str.size();
                a_3_3[i] = (a_3_1[i-1] * a_1_3[i-2] + a_3_2[i-1] * a_2_3[i-2] + a_3_3[i-1] * a_3_3[i-2]) % str.size();
            }

            for(int i = 0; i < temp; i++)
            {
                det[i] = a_1_1[i] * (a_2_2[i] * a_3_3[i] - a_2_3[i] * a_3_2[i]) -
                        a_1_2[i] * (a_2_1[i] * a_3_3[i] - a_2_3[i] * a_3_1[i]) +
                        a_1_3[i] * (a_2_1[i] * a_3_2[i] - a_2_2[i] * a_3_1[i]);
            }
            if(det[0] == 0 || det[1] == 0)
                QMessageBox::information(this,tr("Информация"),tr("Один из определителей матриц нулевой"));
            else
            {
                if(ui->radioButton_7->isChecked())
                {
                    for (int i = 0, j = 0; i < text.size(); i+=3, j++)
                    {
                        result.append(str[(str.indexOf(text[i]) * a_1_1[j] + str.indexOf(text[i+1]) * a_2_1[j] + str.indexOf(text[i+2]) * a_3_1[j]) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_2[j] + str.indexOf(text[i+1]) * a_2_2[j] + str.indexOf(text[i+2]) * a_3_2[j]) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_3[j] + str.indexOf(text[i+1]) * a_2_3[j] + str.indexOf(text[i+2]) * a_3_3[j]) % str.size()]);
                    }
                    ui->lineEdit_7->setText(result);
                }
                else
                {
                    if(text.size() % 3 == 0)
                    {
                        for(int i = 0; i < temp; i++)
                        {
                            if(det[i] < 0)
                                x[i] = - ext_gcdx(abs(det[i]), str.size(), 0, 1);
                            else
                                x[i] = ext_gcdx(det[i], str.size(), 0, 1);
                            if(det[i] > 0 && x[i] < 0) x[i] += str.size();
                            else if(det[i] < 0 && x[i] < 0) x[i] = -x[i];
                        }


                        for(int i = 0; i < 2; i++)
                        {
                            b_1_1[i] = ((a_2_2[i] * a_3_3[i] - a_2_3[i] * a_3_2[i]) * x[i]) % str.size();
                            b_1_2[i] = ((a_1_3[i] * a_3_2[i] - a_1_2[i] * a_3_3[i]) * x[i]) % str.size();
                            b_1_3[i] = ((a_1_2[i] * a_2_3[i] - a_1_3[i] * a_2_2[i]) * x[i]) % str.size();
                            b_2_1[i] = ((a_2_3[i] * a_3_1[i] - a_2_1[i] * a_3_3[i]) * x[i]) % str.size();
                            b_2_2[i] = ((a_1_1[i] * a_3_3[i] - a_1_3[i] * a_3_1[i]) * x[i]) % str.size();
                            b_2_3[i] = ((a_1_3[i] * a_2_1[i] - a_1_1[i] * a_2_3[i]) * x[i]) % str.size();
                            b_3_1[i] = ((a_2_1[i] * a_3_2[i] - a_2_2[i] * a_3_1[i]) * x[i]) % str.size();
                            b_3_2[i] = ((a_1_2[i] * a_3_1[i] - a_1_1[i] * a_3_2[i]) * x[i]) % str.size();
                            b_3_3[i] = ((a_1_1[i] * a_2_2[i] - a_1_2[i] * a_2_1[i]) * x[i]) % str.size();

                            if(b_1_1[i] < 0) b_1_1[i]+=str.size();
                            if(b_1_2[i] < 0) b_1_2[i]+=str.size();
                            if(b_1_3[i] < 0) b_1_3[i]+=str.size();
                            if(b_2_1[i] < 0) b_2_1[i]+=str.size();
                            if(b_2_2[i] < 0) b_2_2[i]+=str.size();
                            if(b_2_3[i] < 0) b_2_3[i]+=str.size();
                            if(b_3_1[i] < 0) b_3_1[i]+=str.size();
                            if(b_3_2[i] < 0) b_3_2[i]+=str.size();
                            if(b_3_3[i] < 0) b_3_3[i]+=str.size();
                        }

                        for(int i = 2; i < temp; i++)
                        {
                            b_1_1[i] = (b_1_1[i-2] * b_1_1[i-1] + b_1_2[i-2] * b_2_1[i-1] + b_1_3[i-2] * b_3_1[i-1]) % str.size();
                            b_1_2[i] = (b_1_1[i-2] * b_1_2[i-1] + b_1_2[i-2] * b_2_2[i-1] + b_1_3[i-2] * b_3_2[i-1]) % str.size();
                            b_1_3[i] = (b_1_1[i-2] * b_1_3[i-1] + b_1_2[i-2] * b_2_3[i-1] + b_1_3[i-2] * b_3_3[i-1]) % str.size();
                            b_2_1[i] = (b_2_1[i-2] * b_1_1[i-1] + b_2_2[i-2] * b_2_1[i-1] + b_2_3[i-2] * b_3_1[i-1]) % str.size();
                            b_2_2[i] = (b_2_1[i-2] * b_1_2[i-1] + b_2_2[i-2] * b_2_2[i-1] + b_2_3[i-2] * b_3_2[i-1]) % str.size();
                            b_2_3[i] = (b_2_1[i-2] * b_1_3[i-1] + b_2_2[i-2] * b_2_3[i-1] + b_2_3[i-2] * b_3_3[i-1]) % str.size();
                            b_3_1[i] = (b_3_1[i-2] * b_1_1[i-1] + b_3_2[i-2] * b_2_1[i-1] + b_3_3[i-2] * b_3_1[i-1]) % str.size();
                            b_3_2[i] = (b_3_1[i-2] * b_1_2[i-1] + b_3_2[i-2] * b_2_2[i-1] + b_3_3[i-2] * b_3_2[i-1]) % str.size();
                            b_3_3[i] = (b_3_1[i-2] * b_1_3[i-1] + b_3_2[i-2] * b_2_3[i-1] + b_3_3[i-2] * b_3_3[i-1]) % str.size();
                        }

                        for (int i = 0, j = 0; i < text.size(); i+=3, j++)
                        {
                            result.append(str[(str.indexOf(text[i]) * b_1_1[j] + str.indexOf(text[i+1]) * b_2_1[j] + str.indexOf(text[i+2]) * b_3_1[j]) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_2[j] + str.indexOf(text[i+1]) * b_2_2[j] + str.indexOf(text[i+2]) * b_3_2[j]) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_3[j] + str.indexOf(text[i+1]) * b_2_3[j] + str.indexOf(text[i+2]) * b_3_3[j]) % str.size()]);
                        }

                        ui->lineEdit_7->setText(result);
                    }
                    else
                        QMessageBox::information(this,tr("Информация"),tr("Шифр-текст не кратен 3"));
                }
            }
        }
        if(ui->comboBox_2->currentText() == "4x4")
        {
            for(int i = 2; i < temp; i++)
            {
                a_1_1[i] = (a_1_1[i-1] * a_1_1[i-2] + a_1_2[i-1] * a_2_1[i-2] + a_1_3[i-1] * a_3_1[i-2] + a_1_4[i-1] * a_4_1[i-2]) % str.size();
                a_1_2[i] = (a_1_1[i-1] * a_1_2[i-2] + a_1_2[i-1] * a_2_2[i-2] + a_1_3[i-1] * a_3_2[i-2] + a_1_4[i-1] * a_4_2[i-2]) % str.size();
                a_1_3[i] = (a_1_1[i-1] * a_1_3[i-2] + a_1_2[i-1] * a_2_3[i-2] + a_1_3[i-1] * a_3_3[i-2] + a_1_4[i-1] * a_4_3[i-2]) % str.size();
                a_1_4[i] = (a_1_1[i-1] * a_1_4[i-2] + a_1_2[i-1] * a_2_4[i-2] + a_1_3[i-1] * a_3_4[i-2] + a_1_4[i-1] * a_4_4[i-2]) % str.size();
                a_2_1[i] = (a_2_1[i-1] * a_1_1[i-2] + a_2_2[i-1] * a_2_1[i-2] + a_2_3[i-1] * a_3_1[i-2] + a_2_4[i-1] * a_4_1[i-2]) % str.size();
                a_2_2[i] = (a_2_1[i-1] * a_1_2[i-2] + a_2_2[i-1] * a_2_2[i-2] + a_2_3[i-1] * a_3_2[i-2] + a_2_4[i-1] * a_4_2[i-2]) % str.size();
                a_2_3[i] = (a_2_1[i-1] * a_1_3[i-2] + a_2_2[i-1] * a_2_3[i-2] + a_2_3[i-1] * a_3_3[i-2] + a_2_4[i-1] * a_4_3[i-2]) % str.size();
                a_2_4[i] = (a_2_1[i-1] * a_1_4[i-2] + a_2_2[i-1] * a_2_4[i-2] + a_2_3[i-1] * a_3_4[i-2] + a_2_4[i-1] * a_4_4[i-2]) % str.size();
                a_3_1[i] = (a_3_1[i-1] * a_1_1[i-2] + a_3_2[i-1] * a_2_1[i-2] + a_3_3[i-1] * a_3_1[i-2] + a_3_4[i-1] * a_4_1[i-2]) % str.size();
                a_3_2[i] = (a_3_1[i-1] * a_1_2[i-2] + a_3_2[i-1] * a_2_2[i-2] + a_3_3[i-1] * a_3_2[i-2] + a_3_4[i-1] * a_4_2[i-2]) % str.size();
                a_3_3[i] = (a_3_1[i-1] * a_1_3[i-2] + a_3_2[i-1] * a_2_3[i-2] + a_3_3[i-1] * a_3_3[i-2] + a_3_4[i-1] * a_4_3[i-2]) % str.size();
                a_3_4[i] = (a_3_1[i-1] * a_1_4[i-2] + a_3_2[i-1] * a_2_4[i-2] + a_3_3[i-1] * a_3_4[i-2] + a_3_4[i-1] * a_4_4[i-2]) % str.size();
                a_4_1[i] = (a_4_1[i-1] * a_1_1[i-2] + a_4_2[i-1] * a_2_1[i-2] + a_4_3[i-1] * a_3_1[i-2] + a_4_4[i-1] * a_4_1[i-2]) % str.size();
                a_4_2[i] = (a_4_1[i-1] * a_1_2[i-2] + a_4_2[i-1] * a_2_2[i-2] + a_4_3[i-1] * a_3_2[i-2] + a_4_4[i-1] * a_4_2[i-2]) % str.size();
                a_4_3[i] = (a_4_1[i-1] * a_1_3[i-2] + a_4_2[i-1] * a_2_3[i-2] + a_4_3[i-1] * a_3_3[i-2] + a_4_4[i-1] * a_4_3[i-2]) % str.size();
                a_4_4[i] = (a_4_1[i-1] * a_1_4[i-2] + a_4_2[i-1] * a_2_4[i-2] + a_4_3[i-1] * a_3_4[i-2] + a_4_4[i-1] * a_4_4[i-2]) % str.size();
            }

            for(int i = 0; i < temp; i++)
            {
                det[i] = a_1_1[i] * (a_2_2[i] * (a_3_3[i] * a_4_4[i] - a_3_4[i] * a_4_3[i]) -
                               a_2_3[i] * (a_3_2[i] * a_4_4[i] - a_3_4[i] * a_4_2[i]) +
                               a_2_4[i] * (a_3_2[i] * a_4_3[i] - a_3_3[i] * a_4_2[i]))
                        - a_1_2[i] * (a_2_1[i] * (a_3_3[i] * a_4_4[i] - a_3_4[i] * a_4_3[i]) -
                                   a_2_3[i] * (a_3_1[i] * a_4_4[i] - a_3_4[i] * a_4_1[i]) +
                                   a_2_4[i] * (a_3_1[i] * a_4_3[i] - a_3_3[i] * a_4_1[i]))
                        + a_1_3[i] * (a_2_1[i] * (a_3_2[i] * a_4_4[i] - a_3_4[i] * a_4_2[i]) -
                                   a_2_2[i] * (a_3_1[i] * a_4_4[i] - a_3_4[i] * a_4_1[i]) +
                                   a_2_4[i] * (a_3_1[i] * a_4_2[i] - a_3_2[i] * a_4_1[i]))
                        - a_1_4[i] * (a_2_1[i] * (a_3_2[i] * a_4_3[i] - a_3_3[i] * a_4_2[i]) -
                                   a_2_2[i] * (a_3_1[i] * a_4_3[i] - a_3_3[i] * a_4_1[i]) +
                                   a_2_3[i] * (a_3_1[i] * a_4_2[i] - a_3_2[i] * a_4_1[i]));
            }
            if(det[0] == 0 || det[1] == 0)
                QMessageBox::information(this,tr("Информация"),tr("Один из определителей матриц нулевой"));
            else
            {                
                if(ui->radioButton_7->isChecked())
                {                    
                    for (int i = 0, j = 0; i < text.size(); i+=4, j++)
                    {
                        result.append(str[(str.indexOf(text[i]) * a_1_1[j] + str.indexOf(text[i+1]) * a_2_1[j] + str.indexOf(text[i+2]) * a_3_1[j] + str.indexOf(text[i+3]) * a_4_1[j]) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_2[j] + str.indexOf(text[i+1]) * a_2_2[j] + str.indexOf(text[i+2]) * a_3_2[j] + str.indexOf(text[i+3]) * a_4_2[j]) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_3[j] + str.indexOf(text[i+1]) * a_2_3[j] + str.indexOf(text[i+2]) * a_3_3[j] + str.indexOf(text[i+3]) * a_4_3[j]) % str.size()]);
                        result.append(str[(str.indexOf(text[i]) * a_1_4[j] + str.indexOf(text[i+1]) * a_2_4[j] + str.indexOf(text[i+2]) * a_3_4[j] + str.indexOf(text[i+3]) * a_4_4[j]) % str.size()]);
                    }
                    ui->lineEdit_7->setText(result);
                }
                else
                {
                    if(text.size() % 4 == 0)
                    {
                        for(int i = 0; i < temp; i++)
                        {
                            if(det[i] < 0)
                                x[i] = - ext_gcdx(abs(det[i]), str.size(), 0, 1);
                            else
                                x[i] = ext_gcdx(det[i], str.size(), 0, 1);
                            if(det[i] > 0 && x[i] < 0) x[i] += str.size();
                            else if(det[i] < 0 && x[i] < 0) x[i] = -x[i];
                        }

                        for(int i = 0; i < 2; i++)
                        {
                            b_1_1[i] = ((a_2_2[i] * (a_3_3[i] * a_4_4[i] - a_3_4[i] * a_4_3[i]) -
                                      a_2_3[i] * (a_3_2[i] * a_4_4[i] - a_3_4[i] * a_4_2[i]) +
                                      a_2_4[i] * (a_3_2[i] * a_4_3[i] - a_3_3[i] * a_4_2[i])) * x[i]) % str.size();
                            b_1_2[i] = ((- a_1_2[i] * (a_3_3[i] * a_4_4[i] - a_3_4[i] * a_4_3[i]) +
                                      a_1_3[i] * (a_3_2[i] * a_4_4[i] - a_3_4[i] * a_4_2[i]) -
                                      a_1_4[i] * (a_3_2[i] * a_4_3[i] - a_3_3[i] * a_4_2[i])) * x[i]) % str.size();
                            b_1_3[i] = ((a_1_2[i] * (a_2_3[i] * a_4_4[i] - a_2_4[i] * a_4_3[i]) -
                                      a_1_3[i] * (a_2_2[i] * a_4_4[i] - a_2_4[i] * a_4_2[i]) +
                                      a_1_4[i] * (a_2_2[i] * a_4_3[i] - a_2_3[i] * a_4_2[i])) * x[i]) % str.size();
                            b_1_4[i] = ((- a_1_2[i] * (a_2_3[i] * a_3_4[i] - a_2_4[i] * a_3_3[i]) +
                                      a_1_3[i] * (a_2_2[i] * a_3_4[i] - a_2_4[i] * a_3_2[i]) -
                                      a_1_4[i] * (a_2_2[i] * a_3_3[i] - a_2_3[i] * a_3_2[i])) * x[i]) % str.size();
                            b_2_1[i] = ((- a_2_1[i] * (a_3_3[i] * a_4_4[i] - a_3_4[i] * a_4_3[i]) +
                                      a_2_3[i] * (a_3_1[i] * a_4_4[i] - a_3_4[i] * a_4_1[i]) -
                                      a_2_4[i] * (a_3_1[i] * a_4_3[i] - a_3_3[i] * a_4_1[i])) * x[i]) % str.size();
                            b_2_2[i] = ((a_1_1[i] * (a_3_3[i] * a_4_4[i] - a_3_4[i] * a_4_3[i]) -
                                      a_1_3[i] * (a_3_1[i] * a_4_4[i] - a_3_4[i] * a_4_1[i]) +
                                      a_1_4[i] * (a_3_1[i] * a_4_3[i] - a_3_3[i] * a_4_1[i])) * x[i]) % str.size();
                            b_2_3[i] = ((- a_1_1[i] * (a_2_3[i] * a_4_4[i] - a_2_4[i] * a_4_3[i]) +
                                      a_1_3[i] * (a_2_1[i] * a_4_4[i] - a_2_4[i] * a_4_1[i]) -
                                      a_1_4[i] * (a_2_1[i] * a_4_3[i] - a_2_3[i] * a_4_1[i])) * x[i]) % str.size();
                            b_2_4[i] = ((a_1_1[i] * (a_2_3[i] * a_3_4[i] - a_2_4[i] * a_3_3[i]) -
                                      a_1_3[i] * (a_2_1[i] * a_3_4[i] - a_2_4[i] * a_3_1[i]) +
                                      a_1_4[i] * (a_2_1[i] * a_3_3[i] - a_2_3[i] * a_3_1[i])) * x[i]) % str.size();
                            b_3_1[i] = ((a_2_1[i] * (a_3_2[i] * a_4_4[i] - a_3_4[i] * a_4_2[i]) -
                                      a_2_2[i] * (a_3_1[i] * a_4_4[i] - a_3_4[i] * a_4_1[i]) +
                                      a_2_4[i] * (a_3_1[i] * a_4_2[i] - a_3_2[i] * a_4_1[i])) * x[i]) % str.size();
                            b_3_2[i] = ((- a_1_1[i] * (a_3_2[i] * a_4_4[i] - a_3_4[i] * a_4_2[i]) +
                                      a_1_2[i] * (a_3_1[i] * a_4_4[i] - a_3_4[i] * a_4_1[i]) -
                                      a_1_4[i] * (a_3_1[i] * a_4_2[i] - a_3_2[i] * a_4_1[i])) * x[i]) % str.size();
                            b_3_3[i] = ((a_1_1[i] * (a_2_2[i] * a_4_4[i] - a_2_4[i] * a_4_2[i]) -
                                      a_1_2[i] * (a_2_1[i] * a_4_4[i] - a_2_4[i] * a_4_1[i]) +
                                      a_1_4[i] * (a_2_1[i] * a_4_2[i] - a_2_2[i] * a_4_1[i])) * x[i]) % str.size();
                            b_3_4[i] = ((- a_1_1[i] * (a_2_2[i] * a_3_4[i] - a_2_4[i] * a_3_2[i]) +
                                      a_1_2[i] * (a_2_1[i] * a_3_4[i] - a_2_4[i] * a_3_1[i]) -
                                      a_1_4[i] * (a_2_1[i] * a_3_2[i] - a_2_2[i] * a_3_1[i])) * x[i]) % str.size();
                            b_4_1[i] = ((- a_2_1[i] * (a_3_2[i] * a_4_3[i] - a_3_3[i] * a_4_2[i]) +
                                      a_2_2[i] * (a_3_1[i] * a_4_3[i] - a_3_3[i] * a_4_1[i]) -
                                      a_2_3[i] * (a_3_1[i] * a_4_2[i] - a_3_2[i] * a_4_1[i])) * x[i]) % str.size();
                            b_4_2[i] = ((a_1_1[i] * (a_3_2[i] * a_4_3[i] - a_3_3[i] * a_4_2[i]) -
                                      a_1_2[i] * (a_3_1[i] * a_4_3[i] - a_3_3[i] * a_4_1[i]) +
                                      a_1_3[i] * (a_3_1[i] * a_4_2[i] - a_3_2[i] * a_4_1[i])) * x[i]) % str.size();
                            b_4_3[i] = ((-a_1_1[i] * (a_2_2[i] * a_4_3[i] - a_2_3[i] * a_4_2[i]) +
                                      a_1_2[i] * (a_2_1[i] * a_4_3[i] - a_2_3[i] * a_4_1[i]) -
                                      a_1_3[i] * (a_2_1[i] * a_4_2[i] - a_2_2[i] * a_4_1[i])) * x[i]) % str.size();
                            b_4_4[i] = ((a_1_1[i] * (a_2_2[i] * a_3_3[i] - a_2_3[i] * a_3_2[i]) -
                                      a_1_2[i] * (a_2_1[i] * a_3_3[i] - a_2_3[i] * a_3_1[i]) +
                                      a_1_3[i] * (a_2_1[i] * a_3_2[i] - a_2_2[i] * a_3_1[i])) * x[i]) % str.size();

                            if(b_1_1[i] < 0) b_1_1[i]+=str.size();
                            if(b_1_2[i] < 0) b_1_2[i]+=str.size();
                            if(b_1_3[i] < 0) b_1_3[i]+=str.size();
                            if(b_1_4[i] < 0) b_1_4[i]+=str.size();
                            if(b_2_1[i] < 0) b_2_1[i]+=str.size();
                            if(b_2_2[i] < 0) b_2_2[i]+=str.size();
                            if(b_2_3[i] < 0) b_2_3[i]+=str.size();
                            if(b_2_4[i] < 0) b_2_4[i]+=str.size();
                            if(b_3_1[i] < 0) b_3_1[i]+=str.size();
                            if(b_3_2[i] < 0) b_3_2[i]+=str.size();
                            if(b_3_3[i] < 0) b_3_3[i]+=str.size();
                            if(b_3_4[i] < 0) b_3_4[i]+=str.size();
                            if(b_4_1[i] < 0) b_4_1[i]+=str.size();
                            if(b_4_2[i] < 0) b_4_2[i]+=str.size();
                            if(b_4_3[i] < 0) b_4_3[i]+=str.size();
                            if(b_4_4[i] < 0) b_4_4[i]+=str.size();
                        }

                        for(int i = 2; i < temp; i++)
                        {
                            b_1_1[i] = (b_1_1[i-2] * b_1_1[i-1] + b_1_2[i-2] * b_2_1[i-1] + b_1_3[i-2] * b_3_1[i-1] + b_1_4[i-2] * b_4_1[i-1]) % str.size();
                            b_1_2[i] = (b_1_1[i-2] * b_1_2[i-1] + b_1_2[i-2] * b_2_2[i-1] + b_1_3[i-2] * b_3_2[i-1] + b_1_4[i-2] * b_4_2[i-1]) % str.size();
                            b_1_3[i] = (b_1_1[i-2] * b_1_3[i-1] + b_1_2[i-2] * b_2_3[i-1] + b_1_3[i-2] * b_3_3[i-1] + b_1_4[i-2] * b_4_3[i-1]) % str.size();
                            b_1_4[i] = (b_1_1[i-2] * b_1_4[i-1] + b_1_2[i-2] * b_2_4[i-1] + b_1_3[i-2] * b_3_4[i-1] + b_1_4[i-2] * b_4_4[i-1]) % str.size();
                            b_2_1[i] = (b_2_1[i-2] * b_1_1[i-1] + b_2_2[i-2] * b_2_1[i-1] + b_2_3[i-2] * b_3_1[i-1] + b_2_4[i-2] * b_4_1[i-1]) % str.size();
                            b_2_2[i] = (b_2_1[i-2] * b_1_2[i-1] + b_2_2[i-2] * b_2_2[i-1] + b_2_3[i-2] * b_3_2[i-1] + b_2_4[i-2] * b_4_2[i-1]) % str.size();
                            b_2_3[i] = (b_2_1[i-2] * b_1_3[i-1] + b_2_2[i-2] * b_2_3[i-1] + b_2_3[i-2] * b_3_3[i-1] + b_2_4[i-2] * b_4_3[i-1]) % str.size();
                            b_2_4[i] = (b_2_1[i-2] * b_1_4[i-1] + b_2_2[i-2] * b_2_4[i-1] + b_2_3[i-2] * b_3_4[i-1] + b_2_4[i-2] * b_4_4[i-1]) % str.size();
                            b_3_1[i] = (b_3_1[i-2] * b_1_1[i-1] + b_3_2[i-2] * b_2_1[i-1] + b_3_3[i-2] * b_3_1[i-1] + b_3_4[i-2] * b_4_1[i-1]) % str.size();
                            b_3_2[i] = (b_3_1[i-2] * b_1_2[i-1] + b_3_2[i-2] * b_2_2[i-1] + b_3_3[i-2] * b_3_2[i-1] + b_3_4[i-2] * b_4_2[i-1]) % str.size();
                            b_3_3[i] = (b_3_1[i-2] * b_1_3[i-1] + b_3_2[i-2] * b_2_3[i-1] + b_3_3[i-2] * b_3_3[i-1] + b_3_4[i-2] * b_4_3[i-1]) % str.size();
                            b_3_4[i] = (b_3_1[i-2] * b_1_4[i-1] + b_3_2[i-2] * b_2_4[i-1] + b_3_3[i-2] * b_3_4[i-1] + b_3_4[i-2] * b_4_4[i-1]) % str.size();
                            b_4_1[i] = (b_4_1[i-2] * b_1_1[i-1] + b_4_2[i-2] * b_2_1[i-1] + b_4_3[i-2] * b_3_1[i-1] + b_4_4[i-2] * b_4_1[i-1]) % str.size();
                            b_4_2[i] = (b_4_1[i-2] * b_1_2[i-1] + b_4_2[i-2] * b_2_2[i-1] + b_4_3[i-2] * b_3_2[i-1] + b_4_4[i-2] * b_4_2[i-1]) % str.size();
                            b_4_3[i] = (b_4_1[i-2] * b_1_3[i-1] + b_4_2[i-2] * b_2_3[i-1] + b_4_3[i-2] * b_3_3[i-1] + b_4_4[i-2] * b_4_3[i-1]) % str.size();
                            b_4_4[i] = (b_4_1[i-2] * b_1_4[i-1] + b_4_2[i-2] * b_2_4[i-1] + b_4_3[i-2] * b_3_4[i-1] + b_4_4[i-2] * b_4_4[i-1]) % str.size();
                        }

                        for (int i = 0, j = 0; i < text.size(); i+=4, j++)
                        {
                            result.append(str[(str.indexOf(text[i]) * b_1_1[j] + str.indexOf(text[i+1]) * b_2_1[j] + str.indexOf(text[i+2]) * b_3_1[j] + str.indexOf(text[i+3]) * b_4_1[j]) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_2[j] + str.indexOf(text[i+1]) * b_2_2[j] + str.indexOf(text[i+2]) * b_3_2[j] + str.indexOf(text[i+3]) * b_4_2[j]) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_3[j] + str.indexOf(text[i+1]) * b_2_3[j] + str.indexOf(text[i+2]) * b_3_3[j] + str.indexOf(text[i+3]) * b_4_3[j]) % str.size()]);
                            result.append(str[(str.indexOf(text[i]) * b_1_4[j] + str.indexOf(text[i+1]) * b_2_4[j] + str.indexOf(text[i+2]) * b_3_4[j] + str.indexOf(text[i+3]) * b_4_4[j]) % str.size()]);
                        }

                        ui->lineEdit_7->setText(result);
                    }
                    else
                        QMessageBox::information(this,tr("Информация"),tr("Шифр-текст не кратен 4"));
                }
            }
        }
    }
    else
        QMessageBox::information(this,tr("Информация"),tr("Количество символов в алфавите не является простым числом"));
}

void MainWindow::on_pushButton_5_clicked(bool checked)
{    
    QString alphabet = ui->lineEdit->text();
    QString key = ui->lineEdit_8->text();
    QString input = ui->lineEdit_9->text();
    QString output;

    while(key.size() < input.size())
        key+=key;

    if(ui->radioButton_9->isChecked())
    {
        for(int i = 0; i < input.size(); ++i)
        {
            output.append(alphabet[(alphabet.indexOf(input[i])+alphabet.indexOf(key[i])) % alphabet.size()]);
            qDebug() << alphabet.indexOf(input[i]) << " + " << alphabet.indexOf(key[i]) << " % " << alphabet.size() << " = " << (alphabet.indexOf(input[i])+alphabet.indexOf(key[i])) % alphabet.size();
        }

        ui->lineEdit_10->setText(output);
    }
    else
    {
        int temp;
        for(int i = 0; i < input.size(); ++i)
        {
            temp = (alphabet.indexOf(input[i])-alphabet.indexOf(key[i])) % alphabet.size();
            if(temp < 0) temp+=alphabet.size();
            output.append(alphabet[temp]);
            qDebug() << alphabet.indexOf(input[i]) << " - " << alphabet.indexOf(key[i]) << " % " << alphabet.size() << " = " << temp;
        }

        ui->lineEdit_10->setText(output);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString alphabet = ui->lineEdit->text();
    QString input = ui->lineEdit_12->text();
    QString output;
    int gamma = ui->spinBox->value() % alphabet.size();

    if(ui->radioButton_11->isChecked())
    {
        for(int i = 0; i < input.size(); ++i)
        {
            qDebug() << gamma;
            output.append(alphabet[(alphabet.indexOf(input[i]) + gamma) % alphabet.size()]);            
            qDebug() << alphabet.indexOf(input[i]) << " + " << gamma << " % " << alphabet.size() << " = " << (alphabet.indexOf(input[i]) + gamma) % alphabet.size();
            gamma = alphabet.indexOf(output[i]);
        }

        ui->lineEdit_13->setText(output);
    }
    else
    {
        for(int i = 0; i < input.size(); ++i)
        {
            int temp = (alphabet.indexOf(input[i]) - gamma) % alphabet.size();
            if(temp < 0) temp+=alphabet.size();
            qDebug() << gamma;
            output.append(alphabet[temp]);            
            qDebug() << alphabet.indexOf(input[i]) << " - " << gamma << " % " << alphabet.size() << " = " << temp;
            gamma = alphabet.indexOf(input[i]);
        }
        ui->lineEdit_13->setText(output);
    }
}

int MainWindow::sundaram(int n)
{
    int *a = new int [n], i, j, k;
        memset(a, 0, sizeof(int) * n);
        for(i = 1; 3*i+1 < n; i++)
        {
          for(j = 1; (k = i+j+2*i*j) < n && j <= i; j++)
          {
            a[k] = 1;
          }
        }
        for(i = n - 1; i >= 1; i--)
        {
          if(a[i] == 0)
          {
              delete [] a;
              return(2 * i + 1);              
          }
        }

}

void MainWindow::on_pushButton_7_clicked()
{
    int n = sundaram(ui->spinBox_2->value());
    qDebug() << n << " " << ui->spinBox_2->value();
    ui->spinBox_2->setValue(n);
}
