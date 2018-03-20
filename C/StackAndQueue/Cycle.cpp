//
// Created by zwp on 17-9-1.
//

#include <stdio.h>
#include <cstdlib>

#define MaxSize 20

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front;
    int count;
}SqQueue;
/**
 *
 * @param q
 */
void initQueue3(SqQueue *&q){
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=0;
    q->count=0;

}

/**
 *
 * @param q
 */
void destoryQueue3(SqQueue *&q){
    free(q);
}

/**
 *
 * @param q
 * @return
 */
bool EmptyQueue3(SqQueue *q){
    return q->count==0;
}

/**
 * 进队
 * @param q
 * @param e
 * @return
 */
bool enQueue3(SqQueue *&q,ElemType e){
    int rear;
    if(q->count==MaxSize){
        return false;
    } else{
        rear=(q->front+q->count)%MaxSize;
        rear=(rear+1)%MaxSize;
        q->data[rear]=e;
        q->count++;
        return true;
    }
}
/**
 *
 * @param q
 * @param e
 * @return
 */
bool deQueue3(SqQueue *&q,ElemType &e){
    if(q->count==0){
        return false;
    } else{
        q->front=(q->front+1)%MaxSize;
        e=q->data[q->front];
        q->count--;
        return true;
    }
}