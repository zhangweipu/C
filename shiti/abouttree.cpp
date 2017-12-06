//
// Created by zwp on 17-11-24.
//
#include <cstdlib>
#include <stdio.h>

#define MAXSIZE 50

typedef int ElemType;

typedef struct tnode{
    ElemType data;
    struct tnode *son[MAXSIZE];
}TNode;

typedef struct node{
    ElemType data;
    struct node *lchild;
    struct node *rchild;
}BTNode;

//线索二叉树
typedef struct snode{
    ElemType data;
    int ltag,rtag;
    struct snode *lchild;
    struct snode *rchild;
}BSTree;

void initTree(TNode *&b,ElemType a[],int n){
    b=(TNode *)malloc(sizeof(TNode));
    for (int i = 1; i <n; i++) {
       b->son[i]->data=a[i];
    }
}

BTNode initTree2(ElemType a[],int n){
    BTNode *b;
    char stack[MAXSIZE];
    int top=-1;
    int i=0;

    do{
        if(a[i]=='('){
        top++;
        stack[top]=a[i];
        } else if(a[i]==')'){
            top--;
        }
        i++;
    }while (top!=-1);

}


//int main(){
//    printf("sss");
//}