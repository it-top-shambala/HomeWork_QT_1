#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <fstream>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   ui->lineEdit_5->setText(Save());
}

QString MainWindow::Save()
{
    QFile outputStream("SaveData.txt");

    if(outputStream.open( QIODevice::WriteOnly))
    {
        QTextStream stream( &outputStream );
        stream << ui->lineEdit->text() <<"\n";
        stream << ui->lineEdit_2->text() <<"\n";
        stream << ui->lineEdit_3->text() <<"\n";
        stream << ui->lineEdit_4->text() <<"\n";
        stream << ui->lineEdit_6->text() <<"\n";
        stream << ui->lineEdit_7->text() <<"\n";
        stream << ui->lineEdit_8->text() <<"\n";

    }

    outputStream.close();

    return "Файл сохранен!";
}

