#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "childwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //声明槽函数
    void button_login_clicked();

private:
    Ui::MainWindow *ui;
private:
    ChildWindow *cw;//定义一个子窗口类的私有成员
};
#endif // MAINWINDOW_H
