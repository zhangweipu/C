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
/**
 * 创建环
 * @param L
 * @param a
 */
void createRing(LinkList *&L,Elem a[]){
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    LinkList *q,*l;
    q=L;
    int i=0;
    while (a[i]!='\0'){
        l=(LinkList *)malloc(sizeof(LinkList));
        l->data=a[i];
        l->next=NULL;
        q->next=l;
        q=l;
        i++;
    }
    q->next=L;
}
bool judgeRing(LinkList *L);
void showRing(LinkList *L){
    LinkList *p=L->next;
    if(judgeRing(L)) {
        while (p != L) {
            printf("%c \t",p->data);
            p=p->next;
        }
    }
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

/**
 * 匹配字符串
 * @param L1
 * @param L2
 */
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

/**
 * 将两个含头结点的单链表，合成一个带头结点的循环链表
 * @param L1
 * @param L2
 * @return
 */
LinkList combineOne(LinkList *&L1,LinkList *&L2){
    LinkList *l1,*l2;
    l1=L1->next;
    l2=L2->next;
    while (l1){
        l1=l1->next;
    }
    while (l2){
        l1->next=l2;
        l2=l2->next;
    }
    l2->next=L1;
    free(L2);
}

/**
 * 判断链表环
 * @return
 */
bool judgeRing(LinkList *L){
    LinkList *fast,*low;
    if(L->next==L) return true;
    fast=L->next;
    low=L;
    while (fast->next!=NULL && fast->next->next!=NULL && fast!=low){
        fast=fast->next->next;
        low=low->next;
    }
    if(fast==low){
        printf("是环\n");
        return true;
    } else{
        return false;
    }
}
//int main(){
//    int a[]={1,2,4,5,2,1,4};
//
//    char c[]={'q','a','c','y','d','a','m'};
//    char d[]={'y','d','a'};
//    LinkList *L1,*L2;
//    createRing(L1,c);
//   showRing(L1);
//    createList(L2,c,7);
//    if(judgeRing(L2)){
//        printf("是环");
//    }
//}