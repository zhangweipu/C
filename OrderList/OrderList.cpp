//
// Created by zwp on 17-8-19.
//
#include <stdio.h>
#include <cstdlib>

#include "../linear/Sq.h"
#include "../LinkList/LinkList.h"
#include "OrderList.h"
/**
 *有序表的顺序结构插入
 * @param L
 * @param e
 */
void listInsert1(SqList *&L,ElemType e){
    int i;
    while (i<L->length && L->data[i]<e){
        i++;
    }
    for(int j=listLength(L);j>i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
}

/**
 *有序表的单链表插入
 * @param L
 * @param e
 */
void listInsert(LinkList *&L,ElemType e){
    LinkList *pre=L,*p;
    while(pre->next!=NULL && pre->next->data<e){
        pre=pre->next;
    }
    p=(LinkList *)malloc(sizeof(LinkList));
    p->data=e;
    p->next=pre->next;
    pre->next=p;
}

/**
 * 有序表的归并算法 顺序表实现
 * @param LA
 * @param LB
 * @param LC 合并的表
 */
void unionList(SqList *&LA,SqList *&LB,SqList *&LC){
    int i=0,j=0,k=0;
    LC=(SqList *)malloc(sizeof(SqList));
    while(i<LA->length && j<LB->length){
        if(LA->data[i]<LB->data[j]){
            LC->data[k]=LA->data[i];
            i++;
            k++;
        } else{
            LC->data[k]=LB->data[j];
            j++;
            k++;
        }
    }
    while (i<LA->length){
        LC->data[k]=LA->data[i];
        i++;
        k++;
    }
    while (j<LB->length){
        LC->data[k]=LB->data[j];
        j++;
        k++;
    }
    LC->length=k;
}

/**
 * 有序表的归并算法　的单链表实现
 * @param LA
 * @param LB
 * @param LC
 */
void unionList(LinkList *&LA,LinkList *&LB,LinkList *&LC){
    LinkList *A=LA->next,*B=LB->next,*r,*s;
    LC=(LinkList *)malloc(sizeof(LinkList));
    r=LC;
    while (A!=NULL && B!=NULL){
        if(A->data<B->data){
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=A->data;
            r->next=s;
            r=s;
            A=A->next;
        } else{
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=B->data;
            r->next=s;
            r=s;
            B=B->next;
        }
    }

    while (A!=NULL){
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=A->data;
        r->next=s;
        r=s;
        A=A->next;
    }

    while (B!=NULL){
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=B->data;
        r->next=s;
        r=s;
        B=B->next;
    }
}
/**
 * 输入三个有序列表，输出只改变Ｌａ使la只剩下三个列表共有的
 * @param La
 * @param Lb
 * @param Lc
 */
void commNode(LinkList *&La,LinkList *&Lb,LinkList *&Lc){
    LinkList *a=La->next,*b=La->next,*c=Lc->next,*q,*r;
    La->next=NULL;
    r=La;
    while (a!=NULL){
        while (b!=NULL && a->data>b->data){
            b=b->next;
        }
        while (c!=NULL && a->next>c->next){
            c=c->next;
        }
        if(b!=NULL && c!=NULL && a->data==b->data && a->data==c->data){
            r->next=a;
            r=a;
            a=a->next;
        } else{
            q=a;
            a=a->next;
            free(q);
        }
    }
    r->next=NULL;
}

/**
 * 删除重复
 * @param L
 */
void delS(LinkList *&L){
    LinkList *p=L->next,*r;
    while(p!=NULL){
        if(p->data!=p->next->data){
            p=p->next;
        } else{
            r=p->next;
            p->next=r->next;
            free(r);
        }
    }
}