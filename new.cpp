#include <stdio.h>
#include <cstdlib>

#define MAX_SIZE 50
typedef int ElementType;

typedef struct linkNode {
    ElementType data;
    struct linkNode *next;
} linkList;

typedef struct {
    ElementType data[MAX_SIZE];
    int top;
} list;

typedef struct tnode {
    ElementType data;
    struct tnode *lchild;
    struct tnode *rchild;
} tree;

void insertTree(tree *&t, ElementType a) {
    if (t == NULL) {
        t = (tree *) malloc(sizeof(tree));
        t->data = a;
        t->lchild = NULL;
        t->rchild = NULL;
    } else{

    }

}

void createTree(tree *&t) {
    int a[] = {1, 2, 4, 6, 7};
    tree *p;
    t = (tree *) malloc(sizeof(tree));
    t->data = 5;
    t->rchild = NULL;
    t->lchild = NULL;
    p = t;
    int i = 0;
    while (i < 5) {

    }
}

void preOrder(tree *t) {
    if (t == NULL) {
        return;
    }
    printf("%d", t->data);
    preOrder(t->lchild);
    preOrder(t->rchild);
}
