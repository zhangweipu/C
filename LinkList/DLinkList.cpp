#include <stdio.h>
#include <cstdlib>
#include "DLinkList.h"

//头插法
void createListF(DLinkList * &L,int a[],int n){
    DLinkList *S;
    L=(DLinkList *)malloc(sizeof(DLinkList));
    L->prior=L->next=NULL;
    for(int i=0;i<n;i++){
        S=(DLinkList *)malloc(sizeof(DLinkList));
        S->data=a[i];
        S->next=L->next;
        if(L->next!=NULL){
            L->next->prior=S;
        }
        L->next=S;
        S->prior=L;
    }
}

//尾插法
void createListR(DLinkList * &L,int a[],int n){
    DLinkList *s,*r;
    L=(DLinkList *)malloc(sizeof(DLinkList));
    r=L;
    for(int i=0;i<n;i++){
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=NULL;
}

//插入
bool listInsert(DLinkList *&L,int i,Element e){
    DLinkList *s,*p=L;
    int j=0;
    while(j<i-1 && p!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    }else{
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=e;
        s->next=p->next;
        if(p->next!=NULL){
            p->next->prior=s;
        }
        s->prior=p;
        p->next=s;
        return true;
    }

}
//删除第ｉ个
bool listDelete(DLinkList *&L,int i,Element &e){
    DLinkList *s=L,*p;
    int j=0;
    while(j<i-1 && s!=NULL){
        j++;
        s=s->next;
    }
    if(s==NULL){
        return false;
    } else{
        p=s->next;
        if(p==NULL){
            return false;
        }
        e=p->data;
        s->next=p->next;
        if(p->next!=NULL){
            p->next->prior=s;
        }
        free(p);
        return true;
    }

}

//倒置
void reverse(DLinkList *&L){
    DLinkList *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL){
        q=p->next;
        p->next=L->next;
        if(L->next!=NULL){
            L->next->prior=p;
        }
        p->prior=L;
        L->next=p;
        p=q;
    }
}

//排序
void sort(DLinkList *&L){
    DLinkList *p,*pre,*q;
    p=L->next->next;
    pre=L;
    L->next->next=NULL;
    while (p!=NULL){
        q=p->next;
        while (pre->next!=NULL && pre->next->data<p->data){
            pre=pre->next;
        }
        p->next=pre->next;
        if(pre->next!=NULL){
            pre->next->prior=p;
        }
        pre->next=p;
        p->prior=pre;
        p=q;
    }
}

//删除第一个为Ｘ的元素
bool delElemX(DLinkList *&L,Element e){
    DLinkList *q=L->next;
    while (q!=L && q->data!=e){
        q-q->next;
    }
    if(q!=L){
        q->next->prior=q->prior;
        q->prior->next=q->next;
        free(q);
        return true;
    } else{
        return false;
    }
}