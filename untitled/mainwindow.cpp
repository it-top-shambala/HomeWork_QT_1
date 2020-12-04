#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_pushSave_clicked()
{
    QString surname=ui->surname->text();
    QString name=ui->name->text();
    QString middleName=ui->middleName->text();
    QString dateBirthday=ui->dateBirthday->text();
    QString sex;
    if (ui->radioButtonSexM->isChecked())
    {
        sex="M";
    } else if (ui->radioButtonSexW->isChecked())
    {
        sex="Ж";
    }
    QString maritalStatus=ui->maritalStatus->text();
    QString others=ui->others->text();
    QFile fileHuman("Human.txt");
    if (fileHuman.open(QIODevice::WriteOnly)) {
        QTextStream outFile(&fileHuman);
        outFile << surname << Qt::endl;
        outFile << name << Qt::endl;
        outFile << middleName << Qt::endl;
        outFile << dateBirthday << Qt::endl;
        outFile << sex << Qt::endl;
        outFile << maritalStatus << Qt::endl;
        outFile << others << Qt::endl;
    QString resultSave;
                ui->resultSave->setText("Файл сохранен");
    }
    else {
            QString resultSave;
            ui->resultSave->setText("Ошибка сохранения");
    }
}
