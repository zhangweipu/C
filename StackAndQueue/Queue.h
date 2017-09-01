//
// Created by zwp on 17-8-30.
//

#ifndef CLION_QUEUE_H
#define CLION_QUEUE_H

#define MaxSize 50

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;
void initQueue(SqQueue *&q);
void destroyQueue(SqQueue *&q);
bool emptyQueue(SqQueue *q);
bool enQueue(SqQueue *&q,ElemType e);
bool enCycleQueue(SqQueue *&q,ElemType e);
bool deQueue(SqQueue *&q,ElemType &e);
bool deCycleQueue(SqQueue *&q,ElemType &e);

#endif //CLION_QUEUE_H
