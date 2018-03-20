#include <stdio.h>
#include <cstdlib>
#include "LinkList.h"

//L1,L2的插入方式不一样
void spilt(LinkList *&L,LinkList *&L1,LinkList *&L2){
    LinkList *p=L->next,*q,*r1;
    L1=L;
    r1=L1;
    L2=(LinkList *)malloc(sizeof(LinkList));
    L2->next=NULL;
    while (p!=NULL){
        r1->next=p;
        r1=p;
        p=p->next;
        q=p->next;
        p->next=L2->next;
        L2->next=p;
        p=q;
    }
    r1->next=NULL;
}

//保存前节点
void delMaxNode(LinkList *&L){
    LinkList *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
    while (p!=NULL){
        if(maxp->data<p->data){
            maxp=p;
            maxp=pre;
        }
        pre=p;
        p=p->next;
    }
    maxpre->next=maxp->next;
    free(maxp);
}

//排序
void sort(LinkList *&L){
    LinkList *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while(p!=NULL){
        q=p->next;
        pre=L;
        while (pre->next!=NULL && pre->next->data<p->data){
            pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=q;

    }


}

//int main(){
//    int a[]={2,3,1,9,4,5,8};
//    LinkList *L;
//    createLinkR(L,a,7);
//    sort(L);
//    displayList(L);
//}