//
// Created by zwp on 17-9-21.
//
#include <stdio.h>

int sum(int n){
    if(n==1){
        return 1;
    }else{
        return sum(n-1)+n;
    }
}

void deep(int n,char x,char y,char z){
    if(n==1){
        printf("第%d从%c转移到%c",n,x,z);
    } else{
        deep(n-1,x,z,y);
        deep(n-1,y,x,z);
    }
}

//
//int main(void){
//    int n=5;
//    printf("%d",sum(n));
//}
