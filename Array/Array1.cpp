//
// Created by zwp on 17-9-8.
//
#include <stdio.h>
#define MaxSize 20


/**
 * 约瑟夫问题
 * @param n 总人数
 * @param m 从第ｍ个人出列
 */
void josephus(int n,int m){
    int p[MaxSize];
    int i,j,t;
    for(i=0;i<n;i++){
        p[i]=i+1;
    }
    printf("出列顺序");
    for(i=n;i>=1;i--){  //i为数组中的人数
        t=(t+m-1)%i;        //t为出列的编号
        printf("%d",p[t]);
        for(j=t+1;t<n;t++){
            p[j-1]=p[j];   //用加有可能会数组越界
        }
    }
    printf("\n");
}
