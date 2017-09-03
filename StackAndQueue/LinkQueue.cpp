//
// Created by zwp on 17-9-1.
//

#include <stdio.h>
#include <cstdlib>
#include "LinkQueue.h"

/**
 * 初始化链队
 * @param q
 */
void init(LinkQueue *&q){
    q=(LinkQueue *)malloc(sizeof(LinkQueue));
    q->front=q->rear=NULL;
}

/**
 * 销毁
 * @param q
 */
void destroyQueue(LinkQueue *&q){
    QNode *p=q->front,*r;
    if(p=!NULL){
        r=p->next;
        while (r!=NULL){
            free(p);
            p=r;
            r=p->next;
        }
    }
    free(p);
    free(q);
}

/**
 *
 * @param q
 * @return
 */
bool EmptyQueue(LinkQueue *q){
    return q->rear!=NULL;
}

/**
 *
 * @param q
 * @param e
 */
void enQueue(LinkQueue *&q,ElemType e){
    QNode *p;
    p=(QNode *)malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL){
        q->front=q->rear=p;
    } else{
        q->rear->next=p;
        q->rear=p;
    }
}

/**
 *
 * @param q
 * @param e
 * @return
 */
bool deQueue(LinkQueue *&q,ElemType &e){
    QNode *t;
    if(q->rear==NULL){
        return false;
    }
    t=q->front;
    if(q->front==q->rear){
        q->front=q->rear=NULL;
    } else{
        q->front=q->front->next;
    }
    e=t->data;
    free(t);
    return true;
}

