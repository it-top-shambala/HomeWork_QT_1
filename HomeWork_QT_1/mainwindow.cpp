#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_Save_clicked()
{

    QFile file("c:\\Programming\\Qt\\HomeWork_QT_1\\HomeWork_QT_1\\HomeWork_QT_1\\fileout.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
QString text = ui->lineEdit_Name->text() + "\n" + ui->lineEdit_Family->text()+ "\n" + ui->lineEdit_F_name->text()+ "\n" + ui->lineEdit_Sex->text()+ "\n" + ui->lineEdit_Status->text();

     out << text;

}
