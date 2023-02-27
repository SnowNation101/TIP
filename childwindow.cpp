#include "childwindow.h"
#include "ui_childwindow.h"
#include <QMessageBox>
#include<QDebug>


class scenic {
public:
    int key;
    int hot;
    QString name;
    scenic(){};
    scenic(QString a, int b, int c) {
        name = a;
        key = b;
        hot = c;
    }
    scenic(const scenic& a) {
        name = a.name;
        key = a.key;
        hot = a.hot;
    }

};

void Sort(scenic sce[], int n) {//排序
    int i, j;
    scenic t("寿康宫", 1, 10);
    for (j = 0; j < n - 1; j++) {
        for (i = 0; i < n - 1 - j; i++) {
            if (sce[i].hot < sce[i + 1].hot) {
                t = sce[i + 1];
                sce[i + 1] = sce[i];
                sce[i] = t;
            }
        }
    }
}
void add(scenic sce[],int key) {//加一
    for (int i= 0; i < 24; i++) {
        if (key == sce[i].key)
            sce[i].hot++;
    }

}
//初始化
scenic sce[24] = {scenic("寿康宫",1,14),scenic("慈宁宫",2,15),scenic("慈宁宫花园",3,5),scenic("武英殿",4,6),scenic("西华门",5,12),
                  scenic("午门",6,25),scenic("金水桥",7,19),scenic("太和门",8,20),scenic("太和殿",9,25),scenic("中和殿",10,26),
                  scenic("保和殿",11,17),scenic("隆宗门",12,19),scenic("养心殿",13,30),scenic("斋宫",14,21),scenic("景运门",15,23),
                  scenic("奉先殿",16,13),scenic("皇极殿",17,15),scenic("九龙壁",18,7),scenic("东华门",19,5),scenic("文华殿",20,8),scenic("箭亭",21,10),
                 scenic("东角楼",22,3),scenic("西角楼",23,6),scenic("乾清门",24,7)
                 };

ChildWindow::ChildWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChildWindow)
{
    ui->setupUi(this);
    //设置窗体相关属性
    setWindowTitle("Guider of the Imperial Palace");//标题
    //按钮美化
    ui->button_exit->
    //翻页按钮操作
    connect(ui->button_Search,&QPushButton::clicked,this,&ChildWindow::button_search_clicked);
    connect(ui->button_minpath,&QPushButton::clicked,this,&ChildWindow::button_minpath_clicked);
    connect(ui->button_recommend,&QPushButton::clicked,this,&ChildWindow::button_recommend_clicked);
    connect(ui->button_hotrank,&QPushButton::clicked,this,&ChildWindow::button_hotrank_clicked);
    connect(ui->button_exit,&QPushButton::clicked,this,[=](){
        exit(0);
    });

    spot.addAtTail("寿康宫",17);spot.addAtTail("慈宁宫",0);spot.addAtTail("慈宁宫花园",16);spot.addAtTail("武英殿",10);spot.addAtTail("西华门",20);spot.addAtTail("午门",2);
    spot.addAtTail("金水桥",3);spot.addAtTail("太和门",4);spot.addAtTail("太和殿",5);spot.addAtTail("中和殿",6); spot.addAtTail("保和殿",7);spot.addAtTail("隆宗门",22);
    spot.addAtTail("养心殿",26);spot.addAtTail("斋宫",41);spot.addAtTail("景运门",35);spot.addAtTail("奉先殿",38);spot.addAtTail("皇极殿",37);spot.addAtTail("九龙壁",36);
    spot.addAtTail("东华门",29);spot.addAtTail("文华殿",27);spot.addAtTail("箭亭",34);spot.addAtTail("东角楼",30);spot.addAtTail("西角楼",21);spot.addAtTail("乾清门",8);

    //景点简介
    connect(ui->pushButton_1,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("寿康宫，位于内廷外西路，慈宁宫西侧。清雍正十三年(1735年)始建，至乾隆元年(1736年)建成，嘉庆二十五年(1820年)、光绪十六年(1890年)重修。寿康宫南北三进院，院墙外东、西、北三面均有夹道，西夹道外有房数间。");
        MBox.setIconPixmap(QPixmap("://point001.jpg"));
        MBox.exec();
        add(sce,1);
    });

    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("慈宁宫位于内廷外西路隆宗门西侧，始建于明嘉靖十五年（1536年），万历年间因灾重建，清代屡加修葺，乾隆三十四年（1769年）改造为今天所见形制。宫与慈宁门、大佛堂、徽音左右门及东西廊庑组成一个二进院落。");
        MBox.setIconPixmap(QPixmap("://point002.jpg"));
        MBox.exec();
        add(sce,2);
    });

    connect(ui->pushButton_3,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("九龙壁烧造于乾隆三十七年(1772年），是我国现存同类建筑中最精巧的一座。九龙壁长29.4米，高3.5米，下为汉白玉石须弥座。壁面以云水为底纹，分饰蓝、绿两色，烘托出水天相连的磅礴气势。壁心采用高浮雕手法雕刻着九条蟠龙。");
        MBox.setIconPixmap(QPixmap("://point003.jpg"));
        MBox.exec();
        add(sce,18);
    });

    connect(ui->pushButton_4,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("慈宁宫花园位于内廷外西路慈宁宫西南，始建于明代，是明清太皇太后，皇太后及太妃嫔们游憩、礼佛之处。花园中原有临溪观、咸若亭等建筑，万历十一年(1583年)改名为临溪亭、咸若馆。");
        MBox.setIconPixmap(QPixmap("://point004.jpg"));
        MBox.exec();
        add(sce,3);
    });

    connect(ui->pushButton_5,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("隆宗门，明永乐十八年（1420年）建，后屡次重修。它是乾清门广场西面的重要禁门，是内廷与禁城西路及城西苑的主要通道。“隆宗”取国本兴盛之意。");
        MBox.setIconPixmap(QPixmap("://point005.jpg"));
        MBox.exec();
        add(sce,12);
    });

    connect(ui->pushButton_6,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("武英殿位于外朝熙和门以西，建于明初，为帝王斋居和召见大臣的地方。崇祯年间后千秋、命妇朝贺仪也在此举行。明末农民起义军领袖李自成入住紫禁城后在武英殿举行了即位仪式。");
        MBox.setIconPixmap(QPixmap("://point006.jpg"));
        MBox.exec();
        add(sce,4);
    });

    connect(ui->pushButton_7,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("西华门是紫禁城西门，始建于明永乐十八年（1420年），与东华门遥相对应，门外设有下马碑石。门楼用于安放阅兵用的棉甲、盔甲。西面檐下“西华门”匾额原为满、蒙、汉三种文字，后减为满、汉两种，辛亥革命后只余铜质汉字。");
        MBox.setIconPixmap(QPixmap("://point007.jpg"));
        MBox.exec();
        add(sce,5);
    });

    connect(ui->pushButton_8,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("角楼是位于紫禁城垣四隅之上，是城池的一部分，它与城垣、城门楼及护城河同属于皇宫的防卫设施。建成于明永乐十八年(1420年)，清代重修。");
        MBox.setIconPixmap(QPixmap("://point008.jpg"));
        MBox.exec();
        add(sce,23);
    });

    connect(ui->pushButton_9,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("角楼是位于紫禁城垣四隅之上，是城池的一部分，它与城垣、城门楼及护城河同属于皇宫的防卫设施。建成于明永乐十八年(1420年)，清代重修。");
        MBox.setIconPixmap(QPixmap("://point009.jpg"));
        MBox.exec();
        add(sce,22);
    });


    connect(ui->pushButton_10,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("东华门是紫禁城的东门，与西华门遥相对应，始建于明永乐十八年（1420年）。它与西华门形制相同，平面矩形，红色城台，白玉须弥座，当中辟3座券门，城台上建有城楼。");
        MBox.setIconPixmap(QPixmap("://point010.jpg"));
        MBox.exec();
        add(sce,19);
    });

    connect(ui->pushButton_11,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("午门为紫禁城正门，在南面城垣的正中，是紫禁城四座城门中最大的一座，也是紫禁城最高的建筑。于明永乐十八年（1420年）建成。");
        MBox.setIconPixmap(QPixmap("://point011.jpg"));
        MBox.exec();
        add(sce,6);
    });

    connect(ui->pushButton_12,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("金水桥分外金水桥和内金水桥。内金水桥位于故宫内太和门前广场内金水河上，系五座并列单孔拱券式汉白玉石桥；横亘在天安门前外金水河上的三孔拱券式汉白玉石桥为外金水桥，重建于清康熙二十九年。");
        MBox.setIconPixmap(QPixmap("://point012.jpg"));
        MBox.exec();
        add(sce,7);
    });

    connect(ui->pushButton_13,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("太和门是紫禁城外朝庄严的门户，明永乐年建成，初称奉天门，在明代是帝早朝御门听政的场所，且洪熙、宣德、正统三朝帝即在此门登基即位，所以在明代此门又被称为大朝门。清顺治入主北京后始名太和门。");
        MBox.setIconPixmap(QPixmap("://point013.jpg"));
        MBox.exec();
        add(sce,8);
    });

    connect(ui->pushButton_14,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("太和殿，俗称“金銮殿”，位于紫禁城南北主轴线的显要位置，明永乐十八年(1420年)建成，称奉天殿。太和殿是紫禁城内体量最大、等级最高的建筑物，建筑规制之高，装饰手法之精，堪列中国古代建筑之首。");
        MBox.setIconPixmap(QPixmap("://point014.jpg"));
        MBox.exec();
        add(sce,9);
    });

    connect(ui->pushButton_15,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("中和殿位处太和殿与保和殿之间，仿佛古代尊贵的“工”字形殿中间穿廊的作用。初建于明永乐年间，初名华盖殿，后几经灾毁和重建。明嘉靖年间重建后改名中极殿，清顺治帝入主紫禁城后改名中和殿，意为秉中庸之道，求天下和顺。");
        MBox.setIconPixmap(QPixmap("://point015.jpg"));
        MBox.exec();
        add(sce,10);
    });

    connect(ui->pushButton_16,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("保和殿是三台上的第三座大殿，初建于明永乐年，后来几经灾毁和重建。原名谨身殿，后改称建极殿，清代最终定名为保和殿，意为保持心志纯一，共享天下和谐。");
        MBox.setIconPixmap(QPixmap("://point016.jpg"));
        MBox.exec();
        add(sce,11);
    });

    connect(ui->pushButton_17,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("皇极殿是宁寿宫区的正殿，“极”出自《尚书》“建其有极”，意为天子为天下建立最高准则。初建于清康熙年，取名宁寿宫。乾隆四十一年（1776年）改建，作为乾隆帝归政后临朝受贺的地方。");
        MBox.setIconPixmap(QPixmap("://point017.jpg"));
        MBox.exec();
        add(sce,17);
    });

    connect(ui->pushButton_18,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("奉先殿，位于紫禁城内廷东侧，为明清皇室祭祀祖先的家庙，始建于明初。清沿明制，于清顺治十四年(1657年)重建，后又多次修缮。奉先殿为建立在白色须弥座上的工字形建筑，四周缭以高垣。");
        MBox.setIconPixmap(QPixmap("://point018.jpg"));
        MBox.exec();
        add(sce,16);
    });


    connect(ui->pushButton_19,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("斋宫位于紫禁城东六宫之南，毓庆宫西，是皇帝在祭天、祭地、祈谷、常萼典礼前斋戒住宿的地方。与雍正九年（1731年）修筑，以便先在宫里行斋戒礼，直到行祭祀礼时再出宫。");
        MBox.setIconPixmap(QPixmap("://point019.jpg"));
        MBox.exec();
        add(sce,14);
    });

    connect(ui->pushButton_20,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("文华殿始建于明朝永乐年间，是紫禁城外朝东路的正殿，与西路的武英殿一文一武，遥相呼应。明末李自成攻入紫禁城后，文华殿几乎焚毁殆尽，清康熙二十二年（1683年）依照旧制重建文华殿。");
        MBox.setIconPixmap(QPixmap("://point020.jpg"));
        MBox.exec();
        add(sce,20);
    });

    connect(ui->pushButton_21,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("景运门位于乾清门前广场的东侧，与西侧的隆宗门相呼应，形制相同。始建于明永乐十八年（1420年），清顺治十二年（1655年）重修。“景运”意喻国运光大。");
        MBox.setIconPixmap(QPixmap("://point021.jpg"));
        MBox.exec();
        add(sce,15);
    });

    connect(ui->pushButton_22,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("箭亭位于紫禁城东部景运门外、奉先殿南一片开活的平地上，始建于清雍正八年(1730年)，是清代皇帝及其子孙练习骑马射箭的地方。箭亭名为“亭”，实质上是一座独立的大殿。");
        MBox.setIconPixmap(QPixmap("://point022.jpg"));
        MBox.exec();
        add(sce,21);
    });

    connect(ui->pushButton_23,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("乾清宫，内廷后三宫之一。始建于明代永乐十八年(1420年)，明清两代曾因数次被焚毁而重建，现有建筑为清代嘉庆三年(1798年)所建。其建筑规模为内廷之首，作为明代皇帝的寝宫。");
        MBox.setIconPixmap(QPixmap("://point023.jpg"));
        MBox.exec();
        add(sce,24);
    });

    connect(ui->pushButton_24,&QPushButton::clicked,this,[=](){
        QMessageBox MBox;
        MBox.setWindowTitle("Introduction");
        MBox.setText("养心殿，明代嘉靖年建，位于内廷乾清宫西侧。清初顺治帝病逝于此地。康熙年间，这里曾经作为宫中造办处的作坊，自从清雍正朝开始，这里作为帝的主要居所和日常理政之处，遂成清代帝实际上的正寝。");
        MBox.setIconPixmap(QPixmap("://point024.jpg"));
        MBox.exec();
        add(sce,13);
    });
    ui->button_gui->setText("刷新");

    ui->label_map_img->update();

}

ChildWindow::~ChildWindow()
{
    delete ui;
}

//定义button_search的槽函数--景点查找
void ChildWindow::button_search_clicked(){
    //通过对widget布局进行选择性隐藏，实现翻页效果
    ui->textBrowser_init->hide();
    ui->widget_search->show();
    ui->widget_minpath->hide();
    ui->widget_recommend->hide();
    ui->widget_hotrank->hide();

    ui->label_map_img->edgeNum=ui->label_map_img->treeEdgeNum=0;
    ui->shortestPath->setText("");//切到其他窗口回来最小路径窗口刷新
    ui->label_map_img->update();
    //此处续写算法操作，以下槽函数相同
}

//定义button_minpath的槽函数--最小路径搜索
void ChildWindow::button_minpath_clicked(){
    ui->shortestPath->setText("");
    ui->textBrowser_init->hide();
    ui->widget_search->hide();
    ui->widget_minpath->show();
    ui->widget_recommend->hide();
    ui->widget_hotrank->hide();

    ui->label_map_img->treeEdgeNum=0;//切换其他页面时，不保留最小生成树
    ui->edit_Search->setText("");
    ui->label_map_img->searchNum=0;
    ui->label_SearchEnd->setText("");//切到其他窗口回来搜索窗口刷新
    ui->label_map_img->update();
}

//定义button_recommend的槽函数--推荐游览路线
void ChildWindow::button_recommend_clicked(){
    ui->textBrowser_init->hide();
    ui->widget_search->hide();
    ui->widget_minpath->hide();
    ui->widget_recommend->show();
    ui->widget_hotrank->hide();

    ui->label_map_img->treeEdgeNum=0;
    ui->edit_Search->setText("");
    ui->label_map_img->searchNum=0;
    ui->label_SearchEnd->setText("");//切到其他窗口回来搜索窗口刷新
    ui->label_map_img->edgeNum=0;//切到其他窗口回来最小路径窗口刷新
    ui->shortestPath->setText("");
    ui->label_map_img->update();
    /*
    相关按钮的点击操作在
    ChildWindow::ChildWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChildWindow)里面编辑
    */
}

//定义button_hotrank的槽函数--热度排序
void ChildWindow::button_hotrank_clicked(){
    ui->textBrowser_init->hide();
    ui->widget_search->hide();
    ui->widget_minpath->hide();
    ui->widget_recommend->hide();
    ui->widget_hotrank->show();

    ui->tableWidget_rank->setRowCount(24);

    ui->tableWidget_rank->clearContents();//只清除工作区，不清除表头

    Sort(sce, 24);//排序
    int row = 0;
    for(int i = 0; i < 24; i++){
         //必须先设置item,然后再获取,因为默认是空的
         QTableWidgetItem *item0 = new QTableWidgetItem(sce[i].name);
         QTableWidgetItem *item1 = new QTableWidgetItem(tr("%1").arg(sce[i].hot));
         ui->tableWidget_rank->setItem(row,0,item0);
         ui->tableWidget_rank->setItem(row,1,item1);
         row = row + 1;
    }
    ui->label_map_img->treeEdgeNum=0;
    ui->edit_Search->setText("");
    ui->label_map_img->searchNum=0;
    ui->label_SearchEnd->setText("");//切到其他窗口回来搜索窗口刷新
    ui->label_map_img->edgeNum=0;//切到其他窗口回来最小路径窗口刷新
    ui->shortestPath->setText("");
    ui->label_map_img->update();
}

void ChildWindow::on_button_ensure_2_clicked()
{
    ui->label_map_img->treeEdgeNum=0;//防止画出最小生成树
    shortestPath=0;
    int time;
    QString num1="";
    QString num2="";
    int from_=ui->comboBox_start_2->currentIndex();
    int to_=ui->comboBox_end_2->currentIndex();
    int match[24]={17,26,36,0,16,22,10,20,21,30,2,3,4,5,6,7,8,41,35,38,37,34,27,29};
    ui->label_map_img->pointSet=ui->label_map_img->G.dijkstra(match[from_],match[to_]);
    for(unsigned int i=0;i<ui->label_map_img->pointSet.size()-1;i++)
    {
        shortestPath+=ui->label_map_img->weightOfLine(QLine(ui->label_map_img->pointSet[i],ui->label_map_img->pointSet[i+1]));
    }
    //qDebug()<<shortestPath;
    num1=QString::number(shortestPath,10);
    time=static_cast<int>(shortestPath/1.2/60+0.5);
    num2=QString::number(time,10);
    QString str="最短路径长度：";
    str.append(num1);
    str=str+"\n步行到达大约需要"+num2+"分钟";
    ui->shortestPath->setText(str);
    ui->label_map_img->edgeNum=ui->label_map_img->pointSet.size()-1;
    ui->label_map_img->update();
}

void ChildWindow::on_ifShowWeight_stateChanged(int arg1)
{
    bool status=ui->ifShowWeight->isChecked();
    if(status==true){
        ui->label_map_img->showOrNot=true;
        ui->label_map_img->update();
    }
    else if(status==false){
        ui->label_map_img->showOrNot=false;
        ui->label_map_img->update();
    }
}


void ChildWindow::on_button_gui_clicked()
{
    ui->button_gui->setText("刷新");
    ui->tableWidget_rank->clearContents();//只清除工作区，不清除表头

    Sort(sce, 24);//排序
    int row = 0;
    for(int i = 0; i < 24; i++){
         //必须先设置item,然后再获取,因为默认是空的
         QTableWidgetItem *item0 = new QTableWidgetItem(sce[i].name);
         QTableWidgetItem *item1 = new QTableWidgetItem(tr("%1").arg(sce[i].hot));
         ui->tableWidget_rank->setItem(row,0,item0);
         ui->tableWidget_rank->setItem(row,1,item1);
         row = row + 1;
    }
}

void ChildWindow::on_button_SearchBegin_clicked()
{
    QString temp=ui->edit_Search->text();
    spot.arr.clear();
    spot.codeArr.clear();
    spot.search(temp);
    ui->label_map_img->searchNum=spot.arr.size();
    QString searchShow;
    if(!spot.arr.size()){
        ui->label_SearchEnd->setText("搜索失败！");
    }
    else{
        for(int i=0;i<spot.arr.size();i++){
            ui->label_map_img->searchSet[i]=spot.codeArr[i];
        }
        ui->label_map_img->update();
        for(int i=0;i<spot.arr.size();i++){
            searchShow=searchShow+spot.arr[i];
            if(i!=spot.arr.size()-1){
                searchShow=searchShow+"/";
            }
        }
        searchShow="您是否要找:"+searchShow+"?";
        ui->label_SearchEnd->setText(searchShow);
    }
}

void ChildWindow::on_button_prim_clicked()
{
    ui->label_map_img->treeSet.clear();
    ui->label_map_img->edgeNum=0;//防止画出最小路径
    ui->label_map_img->treeEdgeNum=39;
    int MINTREE[] = { 1,19,2,3,3,31,4,3,5,6,6,7,7,22,8,7,9,10,10,11,11,12,12,14,14,1,15,1,16,15,17,18,18,19,19,0,20,9,21,20,22,14,23,22,24,23,25,24,26,25,27,28,28,32,29,28,30,29,31,11,32,3,34,35,35,7,36,34,37,36,38,39,39,35,40,8,41,40};
    for(auto i:MINTREE){
        ui->label_map_img->treeSet.push_back(ui->label_map_img->q[i]);
    }
     ui->label_map_img->update();
}


void ChildWindow::on_button_re1_clicked()
{
    ui->label_map_img->pointSet.clear();
    ui->label_map_img->treeEdgeNum=0;//防止画出最小生成树
    int temp_edgeNum=0;
    int recommend_path1[]={2,3,4,5,6,7,8,41};
    for(auto i:recommend_path1){
        ui->label_map_img->pointSet.push_back(ui->label_map_img->q[i]);
        temp_edgeNum++;
    }
    temp_edgeNum--;
    ui->label_map_img->edgeNum=temp_edgeNum;
    ui->label_map_img->update();
}


void ChildWindow::on_button_re2_clicked()
{
    ui->label_map_img->pointSet.clear();
    ui->label_map_img->treeEdgeNum=0;//防止画出最小生成树
    int temp_edgeNum=0;
    int recommend_path2[]={2,3,32,28,27,33,32,3,4,5,6,7,8,7,35,36,37};
    for(auto i:recommend_path2){
        ui->label_map_img->pointSet.push_back(ui->label_map_img->q[i]);
        temp_edgeNum++;
    }
    temp_edgeNum--;
    ui->label_map_img->edgeNum=temp_edgeNum;
    ui->label_map_img->update();
    //ui->label_map_img->edgeNum=ui->label_map_img->treeEdgeNum=0;
}


void ChildWindow::on_button_re3_clicked()
{
    ui->label_map_img->treeSet.clear();
    ui->label_map_img->edgeNum=0;//防止画出最小路径
    int temp_edgeNum=0;
    int recommend_path3[]={2,3,3,32,32,28,28,27,27,33,33,32,3,31,31,9,9,10,10,11,11,31,3,4,4,5,5,6,6,7,7,8,8,40,40,41,7,35,35,36,7,22,22,14,14,1,1,15,15,16};
    for(auto i:recommend_path3){
        ui->label_map_img->treeSet.push_back(ui->label_map_img->q[i]);
        temp_edgeNum++;
    }
    temp_edgeNum/=2;
    ui->label_map_img->treeEdgeNum=temp_edgeNum;
    ui->label_map_img->update();
}

