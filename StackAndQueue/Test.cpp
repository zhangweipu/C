//
// Created by zwp on 17-8-22.
//
#include <stdio.h>
#include "SqSatck.h"

/**
 * 判断对称数组
 * @param str
 * @return
 */
bool symmetry(Element str[]){
    Element e;
    SqStack *s;
    initStack(s);
    for(int i=0;str[i]!='\0';i++){
        push(s,str[i]);
    }
    for(int i=0;str[i]!='\0';i++){
        pop(s,e);
        if(str[i]!=e){
            destroyStack(s);
            return false;
        }
    }
    destroyStack(s);
    return true;
}