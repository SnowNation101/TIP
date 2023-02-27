#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include<QString>
#include <QMainWindow>
#include<spots.h>
namespace Ui {
class ChildWindow;
}

class ChildWindow : public QMainWindow
{
    Q_OBJECT

public:
    int shortestPath;
    explicit ChildWindow(QWidget *parent = nullptr);
    ~ChildWindow();
    //声明槽函数
    void button_search_clicked();
    void button_minpath_clicked();
    void button_recommend_clicked();
    void button_hotrank_clicked();
    Spots spot;//搜索用
private slots:
    void on_button_ensure_2_clicked();

    void on_ifShowWeight_stateChanged(int arg1);


    void on_button_gui_clicked();

    void on_button_SearchBegin_clicked();

    void on_button_prim_clicked();

    void on_button_re1_clicked();

    void on_button_re2_clicked();

    void on_button_re3_clicked();

private:
    Ui::ChildWindow *ui;
};

#endif // CHILDWINDOW_H
