#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked(bool checked);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;

    void enCription();

    void hide();

    void hide_2();

    void deCription();

    bool IsPrime(int number);

    int sundaram(int n);

    void enCriptionRec();

    void deCriptionRec();

    int ext_gcd(int a, int b, int x, int y);

    int ext_gcdx(int a, int b, int x, int y);
};

#endif // MAINWINDOW_H
