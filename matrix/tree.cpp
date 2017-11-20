//
// Created by zwp on 17-10-8.
//

#include <stdio.h>
#include <cstdlib>

typedef struct DNode{
    int data;
    struct DNode *rChild;
    struct DNode *lChild;
}Tree;

void initTree(Tree *&t){
    t=(Tree *)malloc(sizeof(Tree));
    t->lChild=NULL;
}



