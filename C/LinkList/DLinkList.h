
#ifndef CLION_DLINKLIST_H
#define CLION_DLINKLIST_H
typedef int Element;

typedef struct DNote{
    Element data;
    struct DNote *prior;
    struct DNote *next;
}DLinkList;


void createListF(DLinkList * &L,int a[],int n);
void createListR(DLinkList * &L,int a[],int n);
bool listInsert(DLinkList *&L,int i,Element e);
bool listDelete(DLinkList *&L,int i,Element &e);
void reverse(DLinkList *&L);
void sort(DLinkList *&L);
bool delElemX(DLinkList *&L,Element e);
#endif //CLION_DLINKLIST_H
