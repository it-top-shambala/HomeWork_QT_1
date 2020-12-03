#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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


void MainWindow::on_save_clicked()
{
    QString name = ui->setName->text();
    QString surname = ui->setSurname->text();
    QString patronomyc = ui->setPatronomyc->text();
    QString sex = ui->setSex->text();
    QString dateBirth = ui->setDateBirth->text();
    QString status = ui->setStatus->text();
    QString info = ui->setInfo->text();

    QString filename = "test.txt";
    QFile file(filename);
    QTextStream out(stdout);
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << name << Qt::endl;
        out << surname << Qt::endl;
        out << patronomyc << Qt::endl;
        out << sex << Qt::endl;
        out << dateBirth<< Qt::endl;
        out << status << Qt::endl;
        out << info << Qt::endl;
    }
    else {
        QMessageBox::critical(this, "Ошибка чтения файла", "Файл для записи не найден!");
    }
    file.close();
}

void MainWindow::on_clear_clicked()
{
    ui->setName->clear();
    ui->setSurname->clear();
    ui->setPatronomyc->clear();
    ui->setSex->clear();
    ui->setDateBirth->clear();
    ui->setStatus->clear();
    ui->setInfo->clear();
}
