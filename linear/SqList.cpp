//
// Created by zwp on 17-8-8.
//顺序表存储结构
//
#include <stdio.h>
#include <cstdlib>
#include "Sq.h"

//typedef int ElemType;



//建立顺序表
void createList(SqList * &L,ElemType a[],int n){
    L=(SqList *)malloc(sizeof(SqList));
    for (int j = 0; j < n ; j++) {
        L->data[j]=a[j];
    }
    L->length=n;
}

//初始化顺序表
void initList(SqList *&L){
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}

//销毁顺序表，使用ｆｒｅｅ
void destroyList(SqList *L){
    free(L);
}

//判断顺序表是否为空
bool emptyList(SqList *L){
    return L->length==0;
}

//判断顺序表长度
int listLength(SqList *L){
    return L->length;
}

//输出顺序表
void showList(SqList *L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

//还是查找第ｉ个数是啥
bool getElem(SqList *L,int i,ElemType &e){
    if(i<1 || i>L->length){
        return false;
    }
    e=L->data[i-1];
    return true;
}

//定位
int locateElem(SqList *L, ElemType e){
    int index[MaxSize];
    int i=0;
    while(i<L->length && L->data[i]!=e){
        i++;
    }
    if(i>L->length){
        return 0;
    } else {
        return i + 1;
    }
}

//插入
int insertElem(SqList *L,int i,ElemType e){
    if(i<1 || i>L->length-1 || L->length==MaxSize-1){
        return 0;
    }
    for(int j=L->length;j>i-1;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e;
    L->length++;
    return 1;
}

//删除元素
int deleteElem(SqList *L,int i){
    if(i<1 || i>L->length-1){
        return 0;
    }
    for(int j=i;j<=L->length;j++){
        L->data[j-1]=L->data[j];
    }
    L->length--;
    return 1;
}


