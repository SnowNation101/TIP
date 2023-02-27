#ifndef SPOTS_H
#define SPOTS_H
#include<QString>
#include<vector>
using std::vector;
struct ListNode {
   QString val;  // 节点上存储的元素
   int code;
   ListNode *next;  // 指向下一个节点的指针
   ListNode(QString n,int m) : val(n), code(m),next(nullptr) {}  // 节点的构造函数
};
class Spots
{
public:
    int size;
    ListNode* spot;
    vector<QString> arr;
    vector<int> codeArr;
    Spots();
    QString get(int index);
    void addAtTail(QString val,int code);
    void search(QString name_);

};

#endif // SPOTS_H
