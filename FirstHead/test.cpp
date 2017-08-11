//
// Created by zwp on 17-8-8.
//
#include <stdio.h>

struct test{
    int a=1;
    int b=2;
};

int sum(int &c,int &d){
    c=d;
    return 0;
}

//int main(){
//    test test1;
//    int a[]={1,2};
//    printf("%p\n",a);
//    printf("%p\n",&a);
//
//    int c=test1.a;
//    test *test2=&test1;
//    printf("%p\n",test2);
//    printf("%p\n",&test1);
//    printf("%p\n",c);
//
//    int f=1;
//    int e=4;
//    sum(f,e);
//
//    printf("%d",f);
//
//
//
//    return 0;
//}
