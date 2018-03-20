#include <stdio.h>
#define MAXSIZE 50

struct stack{
    int a[MAXSIZE];
    int top;
}stack;

struct node{
    int data;
    struct node lchild;
    struct node rchild;
}tree;
