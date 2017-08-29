//
// Created by zwp on 17-8-29.
//
#include <stdio.h>
#include "LinkStack.h"

#define MaxSize 50
#define  MaxOp 7

struct {
    char ch;
    int pri;
}lpri[]={{'=',0},{'(',1},{'+',3},{'-',3},{'*',5},{'/',5},{')',6}},
 rpri[]={{'=',0},{'(',6},{'+',2},{'-',2},{'*',4},{'/',4},{')',1}};

/**
 * 求左运算符ｏｐ的优先级
 * @param op
 * @return
 */
int leftPri(char op){
    for(int i=0;i<MaxOp;i++){
        if(rpri[i].ch==op){
            return rpri[i].pri;
        }
    }
}

/**
 * 求右运算符op的优先级
 * @param op
 * @return
 */
int rightPri(char op){
    for(int i=0;i<MaxOp;i++){
        if(rpri[i].ch==op){
            return rpri[i].pri;
        }
    }
}

/**
 * 判断字符是否为运算符
 * @param ch
 * @return
 */
bool InOp(char ch){
    if(ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return true;
    } else{
        return false;
    }
}

/**
 * op1 op2运算符优先级比较结果
 * @param op1
 * @param op2
 * @return
 */
int Precede(char op1,char op2){
    if(leftPri(op1) == rightPri(op2)){
        return 0;
    } else if(leftPri(op1) < rightPri(op2)){
        return -1;
    } else if(leftPri(op1) > rightPri(op2)){
        return 1;
    }
}

/**
 * 将算术表达式　转化成后缀表达式
 * @param exp
 * @param postexp
 */
void trans(char *exp,char postexp[]){
    //栈
    struct {
        char data[MaxSize];
        int top;
    }op;
    int i=0;
    op.top=-1;
    op.top++;
    op.data[op.top]='=';
    while (*exp !='\0'){
        if(!InOp(*exp)){
            while (*exp>=0 && *exp<=9){
                postexp[i++]=*exp;
                exp++;
            }
            postexp[i++]='#';
        } else{
            switch (Precede(op.data[op.top],*exp)){
                case -1:
                    op.top++;
                    op.data[op.top]=*exp;
                    exp++;
                    break;
                case 0:
                    op.top--;
                    exp++;
                    break;
                case 1:
                    postexp[i++]=op.data[op.top];
                    op.top--;
                    break;
            }
        }
    }
    while (op.data[op.top]!='='){
        postexp[i++]=op.data[op.top];
        op.top--;
    }
    postexp[i]='\0';
}