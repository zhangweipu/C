//
// Created by zwp on 17-8-16.
//矩阵

#ifndef CLION_MATRIX_H
#define CLION_MATRIX_H

#define MaxSize 50
//数据类型
typedef int Element;
//数据节点类型 ,书上起名还真随便
typedef struct Node1{
    Element data[MaxSize];
    struct Node1 *next;
}DList;

//头结点类型
typedef struct Node2{
    int row,col;
    DList *next; //后面的节点类型
}HList;
#endif //CLION_MATRIX_H
