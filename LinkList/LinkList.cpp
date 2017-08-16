#include <stdio.h>
#include <cstdlib>
#include "LinkList.h"

//创建单链表　头插法　length=sizeof(a)/sizeof(a[0]) 只能在定义数组的方法里起作用
void createLinkF(LinkList *&L,ElemType a[],int n){
    LinkList *s;
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    for(int i=0;i<n;i++){
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

//尾插法
void createLinkR(LinkList *&L,int a[],int n){
    LinkList *s,*r;
    L=(LinkList *)malloc(sizeof(LinkList));
    r=L;
    for(int i=0;i<n;i++){
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

//初始化单链表
void initLinkList(LinkList *&L){
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
}

//销毁单链表
void destroyLinkList(LinkList *&L){
    LinkList *pre=L,*p=L->next;
    while (p!=NULL){
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}

//判断链表有没有数据
bool emptyList(LinkList *L){
    return L->next == NULL;
}

//求线性表长度
int lengthList(LinkList *L){
    int n=0;
    LinkList *p=L;
    while (p->next!=NULL){
        n++;
        p=p->next;
    }
    return n;
}

//输出单链表
void displayList(LinkList *L){
    LinkList *p=L->next;
    while (p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

//判断地ｉ个节点的数据
bool getElem(LinkList *L,int i,ElemType &e){
    int j=0;
    LinkList *p=L;
    while (j<i && p!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    } else{
        e=p->data;
        return true;
    }
}

//按元素值查找
int LocateElem(LinkList *L,ElemType e){
    LinkList *p=L->next;
    int i;
    while (p!=NULL && p->data!=e){
        p=p->next;
        i++;
    }
    if(p==NULL){
        return 0;
    } else{
        return i;
    }
}

//插入数据
bool insertList(LinkList *&L,int i,ElemType e){
    int j=0;
    LinkList *p=L,*s;
    while (j<i-1 && p!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    } else{
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

//删除某节点
bool deleteElem(LinkList *&L,int i,ElemType e){
    int j=0;
    LinkList *p=L,*q;
    while (j<i-1 && p!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    } else{
        q=p->next;
        if(q==NULL){
            return false;
        }
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }

}

//循环链表
int count(LinkList *L,ElemType e){
    int n=0;
    LinkList *q=L->next;
    while (q!=L){
        if(q->data==e){
            n++;
            q=q->next;
        }
    }
    return n;
}

