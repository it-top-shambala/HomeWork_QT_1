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

void MainWindow::on_Save_to_File_clicked()
{
    QFile file("test.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        return;
    }
    QTextStream out(&file);
    setlocale(LC_ALL, "RUS");
    out << ui->Family1->text(); out << "\n";
    out << ui->Name1->text(); out << " ";
    out << ui->Patronymic1->text(); out << "\n";
    out << "Пол: "; out << ui->Gender1; out << "\n"; //не удается приобразовать в строку выбор в ComboBox
    out << "Дата рождения: "; out << ui->Date_Of_Birth1->text(); out << "\n";
    out << "Семейный статус: "; out << ui->Family_status_2; out << "\n";//не удается приобразовать в строку выбор в ComboBox
    out << "Дополнительная информация: "; out << ui->Additional_information_2; out << "\n";

    file.close();
}
