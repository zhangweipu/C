//
// Created by zwp on 17-8-22.
//
#include <stdio.h>
#include <cstdlib>
#include "SqSatck.h"

/**
 * 初始化栈
 * @param s
 */
void initStack(SqStack *&s){
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

/**
 * 销毁栈　和顺序表一样　数据是存在一个＂节点＂中的
 * @param s
 */
void destroyStack(SqStack *&s){
    free(s);
}

/**
 * 判断栈是否为空
 * @param s
 * @return
 */
bool stackEmpty(SqStack *s){
    return (s->top==-1);
}

/**
 * 进栈
 * @param s
 * @param e
 */
bool push(SqStack *&s,Element e){
    if(s->top==MaxSize-1){
        return false;
    }
    s->top++;
    s->data[s->top]=e;
    return true;
}

/**
 * 出栈
 * @param s
 * @param e
 * @return
 */
bool pop(SqStack *&s,Element &e){
    if(s->top==-1){
        return false;
    }
    e=s->data[s->top];
    s->top--;
    return true;
}

/**
 * 获取栈定元素
 * @param s
 * @param e
 * @return
 */
bool getTop(SqStack *s,Element &e){
    if(s->top==-1){
        return false;
    }
    e=s->data[s->top];

    return true;
}