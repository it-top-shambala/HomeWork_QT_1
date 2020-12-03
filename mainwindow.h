#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class window_Main; }
QT_END_NAMESPACE

class window_Main : public QMainWindow
{
    Q_OBJECT

public:
    window_Main(QWidget *parent = nullptr);
    ~window_Main();

private slots:
    void on_buttonSave_clicked();

private:
    Ui::window_Main *ui;
};
#endif // MAINWINDOW_H
