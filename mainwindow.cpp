#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFileInfo>

window_Main::window_Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window_Main)
{
    ui->setupUi(this);
}

window_Main::~window_Main()
{
    delete ui;
}


void window_Main::on_buttonSave_clicked()
{
    QString filename = "C:\\text.txt";
    QFile file(filename);

    QString name=ui->lineName->text();
    QString familia=ui->lineFamilia->text();
    QString patronimic=ui->linePatronimic->text();
    QString any=ui->textAny->toPlainText();
    QDate birthDay=ui->dateBirthDay->date();
    QString gender;
    QString matrimony;

    if(ui->radioMale->isChecked()){
       gender="М";
    }else{
        gender="Ж";
    }

    if(ui->radioFree->isChecked()){
       if(gender=="М"){
           matrimony="холост";
       }else{
           matrimony="не замужем";
       }
    }else{if(gender=="М"){
        matrimony="женат";
        }else{
            matrimony="замужем";
        }
    }

    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);

        out << familia.toUtf8() << Qt::endl;
        out << name.toUtf8() << Qt::endl;
        out << patronimic.toUtf8() << Qt::endl;
        out << birthDay.toString().toUtf8() << Qt::endl;
        out << gender.toUtf8() << Qt::endl;
        out << matrimony.toUtf8() << Qt::endl;
        out << any.toUtf8() << Qt::endl;

        file.close();
    }
    // К сожалению файл не пишется.
}

