//
// Created by zwp on 17-11-20.
//

#include <stdio.h>
#include <malloc.h>

typedef int Elem;

typedef struct list{
    Elem data;
    struct list *next;
}LinkList;


void createList(LinkList *&L,Elem a[],int n){
    LinkList *q,*r;
    L=(LinkList *)malloc(sizeof(LinkList));
    r=L;
    int i;
    for(i=0;i<n;i++){
        q=(LinkList *)malloc(sizeof(LinkList));
        q->data=a[i];
        r->next=q;
        r=q;
    }
    r->next=NULL;
}

void showList(LinkList *L){
    LinkList *q;
    q=L->next;
    while (q){
        printf("%d",q->data);
        q=q->next;
    }
}

bool huiwen(char a[],int m,int n){
    if(n==m || (m+1)==n){
        return true;
    }
    if(m<n && a[n]==a[m]){
        return huiwen(a,++m,--n);
    } else{
        return false;
    }
}
bool trys(char a[],int m,int n){
    for(int i=m;i<=n;i++){
        printf("%c",a[i]);
    }
}

int main(){
    int a[]={1,2,4,5,2,1,4};
    char c[]={'a','b','a','d','a'};
    for(int i=0;i<=2;i++){
        printf("%c",c[i]);
    }
    if(huiwen(c,0,2)){
        printf("\n");
    }
   trys(c,0,2);
}