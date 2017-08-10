//
// Created by zwp on 17-8-8.
//顺序表存储结构
//
#include <stdio.h>
#include <cstdlib>

#define MaxSize 50

typedef int ElemType;

typedef struct SqList{
    ElemType data[MaxSize];
    int length;
};

//建立顺序表
void CreateList(SqList * &L,ElemType a[],int n){
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
    for(int i=0;i<L->length;i++){

    }
    return 0;
}
