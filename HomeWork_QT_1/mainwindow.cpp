#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDateEdit>

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
    QString sex = ui->comboBox_setSex->currentText();
    QString dateBirth = ui->setDateBirth->text();
    QString status = ui->comboBox_setStatus->currentText();
    QString info = ui->setInfo->text();

    QString filename = "test.txt";
    QFile file(filename);
    QTextStream out(stdout);
    if(file.open(QIODevice::Append)) {
        QTextStream out(&file);
        out << name << Qt::endl;
        out << surname << Qt::endl;
        out << patronomyc << Qt::endl;
        out << sex << Qt::endl;
        out << dateBirth<< Qt::endl;
        out << status << Qt::endl;
        out << info << Qt::endl;
        QMessageBox::information(this, "Запись в файл", "Информация была успешно сохранена в файл!");
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
    ui->comboBox_setSex->setCurrentIndex(-1);
    ui->setDateBirth->setDate(QDate(1900,1,1));
    ui->comboBox_setStatus->setCurrentIndex(-1);
    ui->setInfo->clear();
}

void MainWindow::on_add_clicked()
{
    ui->listWidget->addItem(ui->setName->text());
}

void MainWindow::on_load_clicked()
{
    QTextStream out(stdout);
    QString filename = "test.txt";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Ошибка чтения файла", "Файл для чтения не найден!");
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString name = in.readLine();
        //ui->setName->setText(name);
        QString surname = in.readLine();
        //ui->setSurname->setText(surname);
        QString patronomyc = in.readLine();
        //ui->setPatronomyc->setText(patronomyc);
        QString sex = in.readLine();
        //ui->comboBox_setSex->setCurrentText(sex);
        QString dateBirth = in.readLine();
        //ui->setDateBirth->
        //TO DO конвертация даты из string
        QString status = in.readLine();
        //ui->comboBox_setStatus->setCurrentText(status);
        QString info = in.readLine();
        //ui->setInfo->setText(info);
        QString line = name + " " + surname + " " + patronomyc;
        ui->listWidget->addItem(line);
    }
    file.close();
}

void MainWindow::on_deleteFile_clicked()
{
    QString filename = "test.txt";
    QFile file(filename);
    if(!file.exists()) {
        QMessageBox::critical(this, "Ошибка удаления файла", "Файл для удаления не найден!");
    } else {
        QFile(filename).remove();
        QMessageBox::information(this, "Удаление файлов", "Файл " + filename + " был успешно удален!");
    }
}

void MainWindow::on_deletePosition_clicked()
{
    delete ui->listWidget->currentItem();
}

//TO DO Сохранить переделать, редактирование сделать
