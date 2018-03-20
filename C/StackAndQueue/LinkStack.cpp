//
// Created by zwp on 17-8-22.
//
#include <stdio.h>
#include <cstdlib>/*for function malloc*/

#include "LinkStack.h"

/**
 * 初始化栈
 * @param s
 */
void initStack(LinkStack *&s){
    s=(LinkStack *)malloc(sizeof(LinkStack));
    s->next=NULL;
};

/**
 * 销毁栈
 * @param s
 */
void destroyStack(LinkStack *&s){
    LinkStack *p=s,*q=s->next;
    while (q!=NULL){
        free(p);
        p=q;
        q=q->next;
    }
    free(p);
}

/**
 * 判断栈是否为空
 * @param s
 * @return
 */
bool emptyStack(LinkStack *s){
    return s->next==NULL;
}

/**
 * 插入到头结点之后头插法
 * @param s
 * @param e
 * @return
 */
 bool push(LinkStack *&s,ElemType e){
     LinkStack *p;
     p=(LinkStack *)malloc(sizeof(LinkStack));
     p->data=e;
     p->next=s->next;
     s->next=p;
 }

/**
 * 出栈
 * @param s
 * @param e
 * @return
 */
bool pop(LinkStack *&s,ElemType &e){
    LinkStack *p;
    if(s->next==NULL){
        return false;
    }
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
    return true;
}

/**
 *
 * @param s
 * @param e
 * @return
 */
bool getTop(LinkStack *s,ElemType &e){
    if(s->next==NULL){
        return false;
    }
    e=s->next->data;
    return true;
}

