//
// Created by zwp on 17-8-22.
//

#ifndef CLION_SQSATCK_H
#define CLION_SQSATCK_H
#define MaxSize 50

typedef int Element;

typedef struct {
    Element data[MaxSize];
    int top;
}SqStack;
/**
 * init stack
 * @param s
 */
void initStack(SqStack *&s);
/**
 * 销毁栈
 * @param s
 */
void destroyStack(SqStack *&s);
/**
 * 判断是否为空
 * @param s
 * @return
 */
bool stackEmpty(SqStack *s);
/**
 * 出栈
 * @param s
 * @param e
 * @return
 */
bool push(SqStack *&s,Element e);
bool pop(SqStack *&s,Element &e);
bool getTop(SqStack *s,Element &e);
#endif //CLION_SQSATCK_H
