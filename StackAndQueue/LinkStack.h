//
//使用链表创建栈
// Created by zwp on 17-8-22.
//

#ifndef CLION_STACK_H
#define CLION_STACK_H

typedef int ElemType;

typedef struct linkNode{
    ElemType data;
    struct linkNode *next;
}LinkStack;
/**
 *
 * @param s
 */
void initStack(LinkStack *&s);
/**
 *
 * @param s
 */
void destroyStack(LinkStack *&s);
/**
 *
 * @param s
 * @return
 */
bool emptyStack(LinkStack *s);
/**
 *
 * @param s
 * @param e
 * @return
 */
bool push(LinkStack *&s,ElemType e);
/**
 *
 * @param s
 * @param e
 * @return
 */
bool pop(LinkStack *&s,ElemType &e);
/**
 *
 * @param s
 * @param e
 * @return
 */
bool getTop(LinkStack *s,ElemType &e);

#endif //CLION_STACK_H
