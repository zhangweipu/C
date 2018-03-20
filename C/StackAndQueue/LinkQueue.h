//
// Created by zwp on 17-9-1.
//

#ifndef CLION_LINKQUEUE_H
#define CLION_LINKQUEUE_H

#define MaxSize 20

typedef int ElemType;

//数据节点类型
typedef struct qnode{
    ElemType data;
    struct qnode *next;
}QNode;

typedef struct{
    QNode *front;
    QNode *rear;
}LinkQueue;

#endif //CLION_LINKQUEUE_H
