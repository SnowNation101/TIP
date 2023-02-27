#ifndef PAINTLABLE_H
#define PAINTLABLE_H
#include <QLabel>
#include <QPainter>
//#include<map.h>
#include <vector>
#include<graph.h>
using std::vector;
class PaintLabel :public QLabel
{
    Q_OBJECT
private:

public:
    bool showOrNot=false;
    int weightOfLine(QLine a);
    Graph<QPoint,QLine> G;
    QPoint q[50]={QPoint(112,81),QPoint(112,150),QPoint(300,522),QPoint(300,471),QPoint(300,401),QPoint(300,251),QPoint(300,201),QPoint(300,125),QPoint(300,91)
                    ,QPoint(125,471),QPoint(125,401),QPoint(193,401),QPoint(193,260),QPoint(112,260),QPoint(193,150),QPoint(75,150),QPoint(75,190),QPoint(57,50),
                    QPoint(57,110),QPoint(112,110),QPoint(27,450),QPoint(27,490),QPoint(200,125),QPoint(173,125),QPoint(173,52),QPoint(205,52),QPoint(205,0)
                    ,QPoint(453,390),QPoint(453,471),QPoint(570,450),QPoint(570,490),QPoint(205,471),QPoint(390,471),QPoint(420,390),QPoint(430,200),QPoint(390,125)
                    ,QPoint(537,160),QPoint(537,0),QPoint(455,30),QPoint(455,110),QPoint(300,55),QPoint(360,55)};
    QLine l[50]={QLine(q[0],q[19]),
                 QLine(q[1],q[19]),
                 QLine(q[2],q[3]),
                 QLine(q[3],q[4]),
                 QLine(q[4],q[5]),
                 QLine(q[5],q[6]),
                 QLine(q[6],q[7]),
                 QLine(q[7],q[8]),
                 QLine(q[3],q[31]),
                 QLine(q[31],q[9]),
                 QLine(q[9],q[10]),
                 QLine(q[10],q[11]),
                 QLine(q[11],q[12]),
                 QLine(q[12],q[13]),
                 QLine(q[12],q[14]),
                 QLine(q[1],q[14]),
                 QLine(q[1],q[13]),
                 QLine(q[1],q[15]),
                 QLine(q[15],q[16]),
                 QLine(q[17],q[18]),
                 QLine(q[18],q[19]),
                 QLine(q[20],q[21]),
                 QLine(q[9],q[20]),
                 QLine(q[14],q[22]),
                 QLine(q[22],q[23]),
                 QLine(q[14],q[23]),
                 QLine(q[23],q[24]),
                 QLine(q[24],q[25]),
                 QLine(q[25],q[26]),
                 QLine(q[27],q[28]),
                 QLine(q[3],q[32]),
                 QLine(q[32],q[28]),
                 QLine(q[28],q[29]),
                 QLine(q[29],q[30]),
                 QLine(q[11],q[31]),
                 QLine(q[32],q[33]),
                 QLine(q[27],q[33]),
                 QLine(q[33],q[34]),
                 QLine(q[7],q[22]),
                 QLine(q[7],q[35]),
                 QLine(q[34],q[35]),
                 QLine(q[36],q[37]),
                 QLine(q[34],q[36]),
                 QLine(q[35],q[36]),
                 QLine(q[38],q[39]),
                 QLine(q[35],q[39]),
                 QLine(q[8],q[40]),
                 QLine(q[40],q[41])};
    int edgeNum;//边的数目
    int treeEdgeNum;//最小生成树边的数目
    int searchNum;//搜索结果圈出来的数目
    vector<QPoint>treeSet;
    vector<QPoint>pointSet;
    int searchSet[25];
    explicit PaintLabel(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // PAINTLABLE_H
