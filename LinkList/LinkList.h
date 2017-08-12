//
// Created by zwp on 17-8-11.
//

#ifndef CLION_LINKLIST_H
#define CLION_LINKLIST_H

typedef int ElemType;

//单链表节点  结构数组名　结构数组变量名
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList;

//双链表节点
typedef struct Node{

}DLinkList;

void initLinkList(LinkList *&L);
void createLinkF(LinkList *&L,ElemType a[],int n);
void createLinkR(LinkList *&L,int a[],int n);
void destroyLinkList(LinkList *&L);
bool emptyList(LinkList *L);
int lengthList(LinkList *L);
void displayList(LinkList *L);
bool getElem(LinkList *L,int i,ElemType &e);
int LocateElem(LinkList *L,ElemType e);
bool insertList(LinkList *&L,int i,ElemType e);
bool deleteElem(LinkList *&L,int i,ElemType e);
#endif //CLION_LINKLIST_H
