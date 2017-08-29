//
// Created by zwp on 17-8-27.
//
#include <stdio.h>
#include "LinkStack.h"

/**
 * 括号匹配算法
 * @param exp　输入字符串
 * @param n　字符串长度
 * @return
 */
bool match(char exp[],int n){
    int i=0; char e;
    bool match=true;
    LinkStack *s;
    initStack(s);
    while (i<n && match){
        if(exp[i]=='('){
            push(s,exp[i]);
        } else if(exp[i]==')'){
            if(getTop(s,e)== true){
                if(e!=exp[i]){
                    match= false;
                } else{
                    pop(s,e);
                }
            }
        }
        i++;
    }
    if(!emptyStack(s)){
        match= false;
    }
    destroyStack(s);

    return false;
}


