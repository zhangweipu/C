//
// Created by zwp on 17-11-20.
//

#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 50

typedef int Elem;

typedef struct linkList{
    Elem data;
    struct linkList *next;
}LinkList;

typedef struct list{
   Elem data[MAX_SIZE];
   int length;
}List;

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

void createList2(Elem a[],List *&L){
    L=(List *)malloc(sizeof(List));
    L->length=0;
    int i=0;
    while (a[i]!='\0'){
        i++;
    }
    for(int j=0;j<i;j++){
        L->data[j]=a[j];
    }
    L->length=i;
}

void showList2(List *L){
    for (int i = 0; i <L->length ; i++) {
        printf("%d\t",L->data[i]);
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

// ??? 删除匹配的子串
void delSubStr(char a[],char b[]){
    char *d=b;
    while (*b!='\0' && *a!='\0') {
        if (*a == *b) {
            a++;
            b++;
        } else{
            a++;
            delSubStr(a,d);
        }
    }
    int count=0;
    if((*b=='\0' && *a!='\0')||(*b=='\0' && *a=='\0')){
        while (*b!='\0'){

        }
  }
    for (int i = count; i >0 ; i--) {

    }


}

void divideList(List *&L){
    if(L==NULL) return;
    Elem temp;
    int i=0,j=L->length-1;
    while (i<j){
        while (i<j && (L->data[j]%2==0)){
            j--;
        }
        while (i<j && (L->data[i]%2!=0)){
            i++;
        }
        temp=L->data[i];
        L->data[i]=L->data[j];
        L->data[j]=temp;
    }
}



int main(){
    int a[]={1,2,4,5,2,1,4};

    char c[]={'a','b','a','d','a'};
    char d[]={'a','d','a'};
    //delSubStr(c,d);
    List *L;
    createList2(a,L);
    divideList(L);
    showList2(L);
}