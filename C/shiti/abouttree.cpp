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

BTNode *createTree(char *in,char *post,int n){
    if(n<=0){
        return NULL;
    }
    BTNode *b; int k;
    b=(BTNode *)malloc(sizeof(BTNode));
    char e,*p;
    e=*(post+n-1);
    b->data=e;
    for(p=in;p<in+n-1;p++){
        if(*p==e){
            break;
        }
    }
    k=p-in;
    b->lchild=createTree(in,post,k);
    b->rchild=createTree(p+1,post+k,n-k-1);
    return b;
}

void display(BTNode *b){
    if(b==NULL){
        return;
    }
    printf("%c",b->data);
    display(b->lchild);
    display(b->rchild);
}

int main(){
    printf("sss");
    char in[]="DBEAFIHCG";
    char post[]="DEBHIFGCA";
    BTNode *b;
    b=createTree(in,post,9);

    display(b);
}