//
// Created by zwp on 17-9-10.
//

#include <cstdlib>

#define M 5
#define N 5
#define MaxSize 5

typedef int ElemType;

typedef struct{
    int r;//行号
    int c;//列号
    ElemType d;
}TupNode;  //三元组定义

typedef struct{
    int rows;//行数
    int cols;//列数
    int nums;//非零元素个数
    TupNode *data[MaxSize];
}TupMatrix;

void createMatrix(TupNode *&node,TupMatrix *&Matrix,ElemType array[M][N],int n){
    int j,i,k=0;
    TupNode *p;
    TupMatrix *q;
    q=(TupMatrix *)malloc(sizeof(TupMatrix));
    q->nums=M;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(array[i][j]!=NULL){
                p=(TupNode *)malloc(sizeof(TupNode));
                p->r=i;
                p->c=j;
                p->d=array[i][j];
            }
            q->rows=i;
            q->cols=j;
            q->data[k]=p;
            k++;
        }
    }
}