//
// Created by zwp on 17-9-5.
//
#include <stdio.h>
#include "Queue.h"

void number(int n){
    ElemType  e;
    SqQueue q;
    q.front=q.rear=0;
    for(int i=1;i<=n;i++){
        q.rear=(q.rear+1)%MaxSize;
        q.data[q.rear]=i;
    }
    printf("报数顺序:");
    while (q.front!=q.rear){
        q.front=(q.front+1)%MaxSize;
        e=q.data[q.front];
        printf("%d",e);
        if(q.front!=q.rear){
            q.front=(q.front+1)%MaxSize;
            e=q.data[q.front];
            q.rear=(q.rear+1)%MaxSize;
            q.data[q.rear]=e;
        }
        printf("\n");
    }
}

