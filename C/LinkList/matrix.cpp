//
// Created by zwp on 17-8-16.
//矩阵
#include <stdio.h>
#include <cstdlib>
#include "matrix.h"


/**
 *创建节点
 * @param L 头指针
 * @param a 数据
 * @param row 行数
 * @param col 列数
 */
void createTable(HList *&h,int a[][MaxSize],int row,int col){
    DList *r,*s;
    h=(HList *)malloc(sizeof(HList));
    h->row=row;
    h->col=col;
    for(int i=0;i<row;i++){
        s=(DList *)malloc(sizeof(DList));
        for(int j=0;j<col;j++){
            s->data[j]=a[i][j];
        }
        if(h->next==NULL){
            h->next=s;
        } else{
            r->next=s;
        }
        r=s;
    }
    r->next=NULL;
}

/**
 *销毁
 * @param h
 */
void destroyTable(HList *&h){
    DList *pre=h->next,*p=pre->next;
    while (p!=NULL){
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
    free(h);
}
/**
 * 显示
 * @param h
 */
void displayTable(HList *h){
    DList *p=h->next;
    while (p!=NULL){
        for(int i=0;i<h->col;i++){
            printf("%2d",p->data[i]);
        }
        printf("\n");
        p=p->next;
    }
}

/**
 * 连接两个表 尾插法
 * @param L1
 * @param L2
 * @param L
 */
void linkTable(HList *L1,HList *L2,HList *&L){
    int i,j;
    DList *q=L1->next,*p,*r,*s;
    L=(HList *)malloc(sizeof(HList));
    L->row=0;
    L->col=L1->col+L2->col;
    printf("请输入列序号");
    scanf("%d%d",&i,&j);
   while (q!=NULL){
       q=L2->next;
       while (q!=NULL){
           if(q->data[i-1]==p->data[j-1]){
               s=(DList *)malloc(sizeof(DList));
               for(int k=0;k<L1->col;k++){
                   s->data[k]=q->data[k];
               }
               for(int k=0;k<L2->col;k++){
                   s->data[L1->col+k]=p->data[k];
               }
               if(L->next==NULL){
                   L->next=s;
               } else{
                   r->next=s;
               }
               r=s;
               L->row++;
           }
           p=p->next;
       }
       q=q->next;
   }
    r->next=NULL;
}