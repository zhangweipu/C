#include <stdio.h>
#include "Sq.h"

//删除相同元素这个地方＂游标需要弄清＂
int deleteSameElem(SqList *L,ElemType e){
    if(L->length==0){
        return 0;
    }
    int i=0;
    do{
        if(e==L->data[i]){
            deleteElem(L,i+1);//实际和地址中的顺序有差
            i=0;
        }
        i++;
    }while(i<L->length);
    return 1;
}
//删除相同２
int deleteSameElem2(SqList *L,ElemType e){
    if(L->length==0){
        return 0;
    }
    for (int i = 0; i <L->length ; i++) {
        if(e==L->data[i]){
            for (int j = i; j < L->length; j++) {
                L->data[j]=L->data[j+1];
            }
            L->length--;
            i--;
        }
    }
}
//来自课本中的算法 比我的好多了 书中没有把多余的去掉
int deleteSameElem3(SqList *L,ElemType e){
    int k=0;
    int len=L->length;
    for (int i = 0; i <L->length ; i++) {
        if(e!=L->data[i]){
            L->data[k]=L->data[i];
            k++;
        }
    }
    for (int j = k; j < len; j++) {
        L->data[j]=0;
    }
    L->length=k;
}

//移动数
int moveNum(SqList *L){
    int i=0,j=L->length-1;
    int pivot=L->data[0];
    int temp=0;
    while(i<j){
        while (i<j && L->data[j]>=pivot){
            j--;
        }
        while (i<j && L->data[i]<=pivot){
            i++;
        }
        if(i<j){
             temp=L->data[i];
            L->data[i]=L->data[j];
            L->data[j]=temp;
        }
    }
    temp=L->data[j];
    L->data[j]=pivot;
    L->data[0]=temp;
    return 1;
}

//
int move2(SqList *L){
    int i=0,j=L->length;
    int pivot=L->data[0];
    while (i<j){
        while(i<j && L->data[j]>pivot){
            j--;
        }
        L->data[i]=L->data[j];
        i++;
        while (i<j && L->data[i]<=pivot){
            i++;
        }
        L->data[j]=L->data[i];
        j--;
    }
    L->data[i]=pivot;
    return 1;
}