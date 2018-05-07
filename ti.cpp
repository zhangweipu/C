#include <stdio.h>

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//int main(){
//    int i,a[]={1,3,5,7,9};
//    swap(a,a+1);
//    for(int i=0;i<5;i++){
//        printf("%d",a[i]);
//    }
//    return 0;
//}

