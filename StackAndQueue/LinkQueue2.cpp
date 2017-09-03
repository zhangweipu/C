//只有尾指针的队
// Created by zwp on 17-9-3.
//
#include <stdio.h>
#include <cstdlib>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}LNode;

/**
 *
 * @param q
 */
void init(LNode *&q){
    q=NULL;
}

/**
 * 环形队进队
 * @param rear
 * @param e
 */
void enQueue(LNode *&rear,ElemType e){
    LNode *p;
    p=(LNode *)malloc(sizeof(LNode));
    p->data=e;
    if(rear==NULL){
        p->next=p; //构成循环
        rear=p;
    } else{
        p->next=rear->next;
        rear->next=p;
        rear=p;
    }
}

/**
 * 环形队出队
 * @param rear
 * @param e
 * @return
 */
bool deQueue(LNode *&rear,ElemType &e){
    LNode *q;
    if(rear==NULL){
        return false;
    } else if(rear->next==rear){
        e=rear->data;
        free(rear);
        rear=NULL;
    }else{
        q=rear->next;
        e=q->data;
        rear->next=q->next;
        free(q);
    }
    return true;
}

/**
 * 判断环形队是否为空
 * @param rear
 * @return
 */
bool EmptyQueue(LNode *rear){
    return rear==NULL;
}