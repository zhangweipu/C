#include <stdio.h>
#include "Sq.h"

int main(){
    int a[]={7,1,2,5,5,7,8};
    SqList *L;
    createList(L,a,7);
    showList(L);
//    int len=listLength(L);
//    printf("\n%d",len);
//    insertElem(L,2,6);
//    showList(L);
//
//    deleteElem(L,1);
//    showList(L);
//    ElemType e=7;
//    int loc=locateElem(L,e);
//    printf("%d\n",loc);
//
//    getElem(L,3,e);
//    printf("%d",e);

//    deleteSameElem3(L,5);
//    showList(L);

    moveNum(L);
    showList(L);
}
