#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
using namespace std;
/*
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QInputDialog>
#include <QTextCodec>
#include <string>
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗体相关属性
    setWindowTitle("Login");//标题
    this->setWindowIcon(QIcon("://gugong.png"));//图标
    //设置显示默认信息
    ui->input_user->setPlaceholderText("Username");
    ui->input_pwd->setPlaceholderText("Password");
    //按钮操作
    connect(ui->button_login,&QPushButton::clicked,this,&MainWindow::button_login_clicked);//登录按钮
    connect(ui->button_exit,&QPushButton::clicked,this,[=](){//退出按钮
        exit(0);
        //QMessageBox::about(this,tr("Information"),"我是黄伊婷");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//定义登录按钮的槽函数--判断账密是否正确
void MainWindow::button_login_clicked(){
    QString username = ui->input_user->text();
    std::cout << username.toStdString().data() << std::endl;
    if(ui->input_user->text() == "123"){
       if(ui->input_pwd->text() == "456"){
           cw = new ChildWindow(this);
           cw->show();//显示子窗口
           this->hide();//隐藏主窗口
       }
       else{
           QMessageBox::warning(this,tr("Warning"),tr("Wrong password!"),QMessageBox::Ok);
       }
    }else{
        QMessageBox::warning(this,tr("Warning"),tr("Wrong username!"),QMessageBox::Ok);
    }
}
