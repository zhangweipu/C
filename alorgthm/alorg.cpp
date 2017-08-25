//
// Created by zwp on 17-8-11.
//
#include <stdio.h>
#include <math.h>
/**
 * 计算数组中两数相加为某要求的数的位置　记不清了
 * @param nums
 * @param numsSize
 * @param target
 * @return
 */
int* sum(int *nums,int numsSize,int target){
    int temp=0;
    for(int i=0;i<numsSize;i++){
        temp=target-nums[i];
        for(int j=0;j<numsSize;j++){
            if(nums[j]==temp && j!=i){
                nums[0]=i;
                nums[1]=j;
            }
        }
    }
}

/**
 * 判断是否为素数
 * @param num
 * @return
 */
bool isPrimeNum(int num){
    int k,i;
    k=sqrt(num);
    for(i=2;i<=k;i++){
        if(num%i==0){
            break;
        }
    }
    if(i>k){
        printf("%d是素数",num);
        return true;
    } else{
        printf("%d是不是素数",num);
        return false;
    }

}

/**
 * 1000以内的水仙花数　
 */
void narcissusNum(){
    int i,j,k;
    for(int l=100;l<1000;l++){
        i=l/100;
        j=l%100/10;
        k=l%10;
        if(l==i*i*i+j*j*j+k*k*k){
            printf("%d\n",l);
        }
    }
}
/**
 * 如果一个数恰好等于它的因子之和，则称该数为“完全数”。
 * 1000以内的完数
 */
void perfectNum(){
    int s,m,i;
    for(m=2;m<1000;m++){
        s=0;
        for(i=1;i<m;i++){
            if(m%i==0){
                s=s+i;
            }
        }
        if(s==m){
            printf("%d是完数",m);
            for(i=1;i<m;i++){
                if(m%i==0){
                    printf("%d \t",i);
                }
            }
            printf("\n");
        }
    }
}
/**
 * 求出m n的最大公倍数,最小公约数
 * @param m
 * @param n
 */
void commonNum(int m,int n){
    int p,r,temp;
    if(n<m){
        temp=m;
        m=n;
        n=temp;
    }
    p=n*m;
    while (m!=0){
        r=n%m;
        n=m;
        m=r;
    }
    printf("最大公约数为:%d\n",n);
    printf("最小公倍数:%d",p/n);
}

/**
 * 一球从１００米的高度自由下落，每次落地反弹原高度的一半
 * 求在第十次落地时，共经过多少米，第十次的高度
 * @param times 反弹次数
 */
void jump(int times){
    float s=100,h=s/2;
    for(int i=2;i<=10;i++){
        s=s+2*s;
        h=h/2;
    }
    printf("第%d次经过%f",times,s);
    printf("第%d次高度%f",times,h);
}
/**
 * F1=1 (n=1)
 * F2=1 (n=2)
 * Fn=Fn-1 + Fn-2 (n>=3)
 * @param n 在n次
 */
void fn(int n){
    int F[n]={1,1};
    for(int i=2;i<n;i++){
        F[i]=F[i-1]+F[i-2];
    }
    for(int i=0;i<n;i++){
        printf("%d\n",F[i]);
    }
}
int main(){
    fn(4);
    return 0;
}