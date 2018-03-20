//
// Created by zwp on 17-10-31.
//
#include <stdio.h>

typedef struct Bitree{
    int data;
    struct Bitree *lchild;
    struct Bitree *rchild;
    struct Bitree *parent;
}bitree;

int preTravelTree(bitree *t,int key,bitree *parent){
    if(t!=NULL){
        t->parent=parent;
        if(t->data==key){
            return 1;
        }

        if(preTravelTree(t->lchild,key,t)!=1){
            preTravelTree(t->rchild,key,t);
        }
    }
    if(parent!=NULL){
        printf("%d",parent->data);
    }
}