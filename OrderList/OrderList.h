//
// Created by zwp on 17-8-19.
//

#ifndef CLION_ORDERLIST_H
#define CLION_ORDERLIST_H
//#define MaxSize 50
//
//typedef int Element;
//
////顺序表
//typedef struct{
//    Element data[MaxSize];
//    int length;
//}sqList;
//
////单链表
//typedef struct LNode{
//    Element data;
//    struct LNode *next;
//}LinkList;
//
////双链表
//typedef struct DNode{
//    Element data;
//    struct DNode *prior;
//    struct DNode *next;
//}DLinkList;

void listInsert1(SqList *&L,ElemType e);
void listInsert(LinkList *&L,ElemType e);
void unionList(SqList *&LA,SqList *&LB,SqList *&LC);
void unionList(LinkList *&LA,LinkList *&LB,LinkList *&LC);
void commNode(LinkList *&La,LinkList *&Lb,LinkList *&Lc);
void delS(LinkList *&L);

#endif //CLION_ORDERLIST_H
