
#ifndef CLION_SQ_H
#define CLION_SQ_H
#define MaxSize 50
    typedef int ElemType;
    typedef struct SqList{
        ElemType data[MaxSize];
        int length;
    };
    struct SqList;
    void createList(SqList * &L,ElemType a[],int n);
    void initList(SqList *&L);
    void destroyList(SqList *L);
    bool emptyList(SqList *L);
    int listLength(SqList *L);
    void showList(SqList *L);
    bool getElem(SqList *L,int i,ElemType &e);
    int locateElem(SqList *L, ElemType e);
    int insertElem(SqList *L,int i,ElemType e);
    int deleteElem(SqList *L,int i);
    int deleteSameElem(SqList *L,ElemType e);
    int deleteSameElem2(SqList *L,ElemType e);
    int deleteSameElem3(SqList *L,ElemType e);
    int moveNum(SqList *L);
#endif //CLION_SQ_H
