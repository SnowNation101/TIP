#include "paintlabel.h"
#include<QDebug>
#include<iostream>
int PaintLabel::weightOfLine(QLine a)
{
    int b=static_cast<int>(sqrt((a.p1().x()-a.p2().x())*(a.p1().x()-a.p2().x())+(a.p1().y()-a.p2().y())*(a.p1().y()-a.p2().y()))+0.5);
    return b;
}
PaintLabel::PaintLabel(QWidget *parent):QLabel(parent)
{
    searchNum=0;
    edgeNum=0;
    for(int i=0;i<42;i++)//插入点
    {
        G.insert(q[i]);
    }
    G.insertUndirected(l[0],weightOfLine(l[0]),0,19);
    G.insertUndirected(l[1],weightOfLine(l[1]),1,19);
    G.insertUndirected(l[2],weightOfLine(l[2]),2,3);
    G.insertUndirected(l[3],weightOfLine(l[3]),3,4);
    G.insertUndirected(l[4],weightOfLine(l[4]),4,5);
    G.insertUndirected(l[5],weightOfLine(l[5]),5,6);
    G.insertUndirected(l[6],weightOfLine(l[6]),6,7);
    G.insertUndirected(l[7],weightOfLine(l[7]),7,8);
    G.insertUndirected(l[8],weightOfLine(l[8]),3,31);
    G.insertUndirected(l[9],weightOfLine(l[9]),31,9);
    G.insertUndirected(l[10],weightOfLine(l[10]),9,10);
    G.insertUndirected(l[11],weightOfLine(l[11]),10,11);
    G.insertUndirected(l[12],weightOfLine(l[12]),11,12);
    G.insertUndirected(l[13],weightOfLine(l[13]),12,13);
    G.insertUndirected(l[14],weightOfLine(l[14]),12,14);
    G.insertUndirected(l[15],weightOfLine(l[15]),1,14);
    G.insertUndirected(l[16],weightOfLine(l[16]),1,13);
    G.insertUndirected(l[17],weightOfLine(l[17]),1,15);
    G.insertUndirected(l[18],weightOfLine(l[18]),15,16);
    G.insertUndirected(l[19],weightOfLine(l[19]),17,18);
    G.insertUndirected(l[20],weightOfLine(l[20]),18,19);
    G.insertUndirected(l[21],weightOfLine(l[21]),20,21);
    G.insertUndirected(l[22],weightOfLine(l[22]),9,20);
    G.insertUndirected(l[23],weightOfLine(l[23]),14,22);
    G.insertUndirected(l[24],weightOfLine(l[24]),22,23);
    G.insertUndirected(l[25],weightOfLine(l[25]),14,23);
    G.insertUndirected(l[26],weightOfLine(l[26]),23,24);
    G.insertUndirected(l[27],weightOfLine(l[27]),24,25);
    G.insertUndirected(l[28],weightOfLine(l[28]),25,26);
    G.insertUndirected(l[29],weightOfLine(l[29]),27,28);
    G.insertUndirected(l[30],weightOfLine(l[30]),3,32);
    G.insertUndirected(l[31],weightOfLine(l[31]),32,28);
    G.insertUndirected(l[32],weightOfLine(l[32]),28,29);
    G.insertUndirected(l[33],weightOfLine(l[33]),29,30);
    G.insertUndirected(l[34],weightOfLine(l[34]),11,31);
    G.insertUndirected(l[35],weightOfLine(l[35]),32,33);
    G.insertUndirected(l[36],weightOfLine(l[36]),27,33);
    G.insertUndirected(l[37],weightOfLine(l[37]),33,34);
    G.insertUndirected(l[38],weightOfLine(l[38]), 7,22);
    G.insertUndirected(l[39],weightOfLine(l[39]), 7,35);
    G.insertUndirected(l[40],weightOfLine(l[40]),34,35);
    G.insertUndirected(l[41],weightOfLine(l[41]),36,37);
    G.insertUndirected(l[42],weightOfLine(l[42]),34,36);
    G.insertUndirected(l[43],weightOfLine(l[43]),35,36);
    G.insertUndirected(l[44],weightOfLine(l[44]),38,39);
    G.insertUndirected(l[45],weightOfLine(l[45]),35,39);
    G.insertUndirected(l[46],weightOfLine(l[46]), 8,40);
    G.insertUndirected(l[47],weightOfLine(l[47]),40,41);
    /*for(int i=0;i<48;i++)
    {
        qDebug()<<i<<weightOfLine(l[i]);
    }*/
    //G.showGraph(
}
void PaintLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter p(this);
    QPen pen;
    pen.setWidth(3);//设置线的宽度
    pen.setColor(Qt::white);
    //pen.setColor(QColor(14,9,234));RGB设置颜色
    pen.setStyle(Qt::SolidLine);//设置风格
    //把画笔交给画家
    p.setPen(pen);
    //画直线
    p.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform); //抗锯齿和使用平滑转换算法
    p.drawLine(q[0].rx(),q[0].ry(),q[19].rx(),q[19].ry());
    p.drawLine(q[1].rx(),q[1].ry(),q[19].rx(),q[19].ry());
    p.drawLine(q[2].rx(),q[2].ry(),q[3].rx(),q[3].ry());
    p.drawLine(q[3].rx(),q[3].ry(),q[4].rx(),q[4].ry());
    p.drawLine(q[4].rx(),q[4].ry(),q[5].rx(),q[5].ry());
    p.drawLine(q[5].rx(),q[5].ry(),q[6].rx(),q[6].ry());
    p.drawLine(q[6].rx(),q[6].ry(),q[7].rx(),q[7].ry());
    p.drawLine(q[7].rx(),q[7].ry(),q[8].rx(),q[8].ry());
    p.drawLine(q[3].rx(),q[3].ry(),q[31].rx(),q[31].ry());
    p.drawLine(q[31].rx(),q[31].ry(),q[9].rx(),q[9].ry());
    p.drawLine(q[9].rx(),q[9].ry(),q[10].rx(),q[10].ry());
    p.drawLine(q[10].rx(),q[10].ry(),q[11].rx(),q[11].ry());
    p.drawLine(q[11].rx(),q[11].ry(),q[12].rx(),q[12].ry());
    p.drawLine(q[12].rx(),q[12].ry(),q[13].rx(),q[13].ry());
    p.drawLine(q[12].rx(),q[12].ry(),q[14].rx(),q[14].ry());
    p.drawLine(q[1].rx(),q[1].ry(),q[14].rx(),q[14].ry());
    p.drawLine(q[1].rx(),q[1].ry(),q[13].rx(),q[13].ry());
    p.drawLine(q[1].rx(),q[1].ry(),q[15].rx(),q[15].ry());
    p.drawLine(q[15].rx(),q[15].ry(),q[16].rx(),q[16].ry());
    p.drawLine(q[17].rx(),q[17].ry(),q[18].rx(),q[18].ry());
    p.drawLine(q[18].rx(),q[18].ry(),q[19].rx(),q[19].ry());
    p.drawLine(q[20].rx(),q[20].ry(),q[21].rx(),q[21].ry());
    p.drawLine(q[9].rx(),q[9].ry(),q[20].rx(),q[20].ry());
    p.drawLine(q[14].rx(),q[14].ry(),q[22].rx(),q[22].ry());
    p.drawLine(q[22].rx(),q[22].ry(),q[23].rx(),q[23].ry());
    p.drawLine(q[14].rx(),q[14].ry(),q[23].rx(),q[23].ry());
    p.drawLine(q[23].rx(),q[23].ry(),q[24].rx(),q[24].ry());
    p.drawLine(q[24].rx(),q[24].ry(),q[25].rx(),q[25].ry());
    p.drawLine(q[25].rx(),q[25].ry(),q[26].rx(),q[26].ry());
    p.drawLine(q[27].rx(),q[27].ry(),q[28].rx(),q[28].ry());
    p.drawLine(q[3].rx(),q[3].ry(),q[28].rx(),q[28].ry());
    p.drawLine(q[28].rx(),q[28].ry(),q[29].rx(),q[29].ry());
    p.drawLine(q[29].rx(),q[29].ry(),q[30].rx(),q[30].ry());
    p.drawLine(q[11].rx(),q[11].ry(),q[31].rx(),q[31].ry());
    p.drawLine(q[32].rx(),q[32].ry(),q[33].rx(),q[33].ry());
    p.drawLine(q[27].rx(),q[27].ry(),q[33].rx(),q[33].ry());
    p.drawLine(q[33].rx(),q[33].ry(),q[34].rx(),q[34].ry());
    p.drawLine(q[7].rx(),q[7].ry(),q[22].rx(),q[22].ry());
    p.drawLine(q[7].rx(),q[7].ry(),q[35].rx(),q[35].ry());
    p.drawLine(q[34].rx(),q[34].ry(),q[35].rx(),q[35].ry());
    p.drawLine(q[36].rx(),q[36].ry(),q[37].rx(),q[37].ry());
    p.drawLine(q[34].rx(),q[34].ry(),q[36].rx(),q[36].ry());
    p.drawLine(q[35].rx(),q[35].ry(),q[36].rx(),q[36].ry());
    p.drawLine(q[38].rx(),q[38].ry(),q[39].rx(),q[39].ry());
    p.drawLine(q[35].rx(),q[35].ry(),q[39].rx(),q[39].ry());
    p.drawLine(q[8].rx(),q[8].ry(),q[40].rx(),q[40].ry());
    p.drawLine(q[40].rx(),q[40].ry(),q[41].rx(),q[41].ry());

    if(showOrNot){
        for(int i=0;i<48;i++){
            pen.setColor(Qt::black);
            p.setPen(pen);
            p.drawText((l[i].p1().x()+l[i].p2().x())/2,(l[i].p1().y()+l[i].p2().y())/2,QString::number(weightOfLine(l[i]),10)+"m");
        }
    }
    for(int i=0;i<edgeNum;i++)
    {
        pen.setWidth(5);//加粗
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawLine(pointSet[i].rx(),pointSet[i].ry(),pointSet[i+1].rx(),pointSet[i+1].ry());
    }

    for(int i=0;i<searchNum;i++){//搜索圈出来的地方
        pen.setWidth(3);//加粗
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawEllipse(q[searchSet[i]].rx()-25,q[searchSet[i]].ry()-25,50,50);
    }
    for(int i=0;i<treeEdgeNum*2;i=i+2)//打印最小生成树
    {
        pen.setWidth(5);//加粗
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawLine(treeSet[i].rx(),treeSet[i].ry(),treeSet[i+1].rx(),treeSet[i+1].ry());
    }

}
