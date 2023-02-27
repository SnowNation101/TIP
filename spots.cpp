#include "spots.h"

Spots::Spots()
{
    spot = new ListNode("",0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
    size = 0;
}
void Spots::addAtTail(QString val,int code)
{
    ListNode* newNode = new ListNode(val,code);
    ListNode* cur = spot;
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = newNode;
    size++;
}
QString Spots::get(int index)
{
    ListNode* cur = spot->next;
    while(index--) { // 如果--index 就会陷入死循环
        cur = cur->next;
    }
    return cur->val;
}
void Spots::search(QString name_)
{
    ListNode* cur=spot;
    while (cur->next != nullptr) {
        if(cur->next->val.indexOf(name_,0)!=-1){//匹配成功
            arr.push_back(cur->next->val);
            codeArr.push_back(cur->next->code);
        }
        cur = cur->next;
    }
}
