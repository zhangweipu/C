//
// Created by zwp on 17-11-20.
//

#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 50

typedef char Elem;

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

void showList3(LinkList *L){
    LinkList *q;
    q=L->next;
    while (q){
        printf("%c",q->data);
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

void reverse(LinkList *&L1,LinkList *&L2){

    LinkList *q,*p,*pre,*temp;
    if(L1==NULL || L2==NULL) return;
    pre=L1;
    q=L1->next; p=L2->next;

    while (q!=NULL){
        while (q->next!=NULL && p->next!=NULL && q->data==p->data){
            q=q->next;
            p=p->next;
        }
        if(p->data==q->data){
            break;
        }
        if(p->next==NULL || q->next==NULL){
            break;
        } else{
            pre=pre->next;
            q=pre->next;
            p=L2->next;
        }
    }

    LinkList *stack[MAX_SIZE];
    int top=-1;
    LinkList *s, *o=L2->next;
    while (o!=NULL){
        top++;
        stack[top]=o;
        o=o->next;
        s=stack[top];
        s->next=NULL;
    }
    if(p->next!=NULL){
        printf("没有匹配的字符串");
        return;
    } else{
        while(top != -1){
        temp=stack[top];
        temp->next=pre->next->next;
        pre->next=temp;
        pre=temp;
            top--;
        }
    }

}

int main(){
    int a[]={1,2,4,5,2,1,4};

    char c[]={'q','a','c','y','d','a','m','t','t'};
    char d[]={'y','d','a'};
    LinkList *L1,*L2;
    createList(L1,c,9);
    createList(L2,d,3);
    reverse(L1,L2);
    showList3(L1);
}