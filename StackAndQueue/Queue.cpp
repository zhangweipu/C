//
// Created by zwp on 17-8-30.
//
#include <stdio.h>
#include <cstdlib>


#include "Queue.h"

/**
 * 初始化
 * @param q
 */
void initQueue(SqQueue *&q){
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->rear=q->front=-1;
}

/**
 * 销毁
 * @param q
 */
void destroyQueue(SqQueue *&q){
    free(q);
}

/**
 * 判断队列是否为空
 * @param q
 * @return
 */
bool emptyQueue(SqQueue *q){
    return (q->rear==q->front);
}

/**
 * 进队
 * @param q
 * @param e
 * @return
 */
bool enQueue(SqQueue *&q,ElemType e){
    if(q->rear==MaxSize-1){
        return false;
    }
    q->rear++;
    q->data[q->rear]=e;
    return true;
}

/**
 * 环型队列进队
 * 区别在队初始化　队首和队尾　为０
 * 判断队满　(q.rear+1)%MaxSize==q.front
 * @param e
 * @return
 */
bool enCycleQueue(SqQueue *&q,ElemType e){
    if((q->rear+1)%MaxSize==q->front){
        return false;
    }
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}


/**
 * 出队
 * @param q
 * @param e
 * @return
 */
bool deQueue(SqQueue *&q,ElemType &e){
    if(q->front==q->rear){
        return false;
    }
    q->front++;
    e=q->data[q->front];
    return true;
}
/**
 * 出队　０位置不存储数据
 * @param q
 * @param e
 * @return
 */
bool deCycleQueue(SqQueue *&q,ElemType &e){
    if(q->front==q->rear){
        return false;
    }
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}