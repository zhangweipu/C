//
// Created by zwp on 17-10-22.
//
#include <stdio.h>

void insertSort(int r[],int n){
    int i,j;
    int tmp;
    for(i=1;i<n;i++){
        tmp=r[i];
        j=i-1;
        while (j>=0 && tmp<r[j]){
            r[j+1]=r[j];
            j--;
        }
        r[j+1]=tmp;
    }
}

void insertSort1(int R[],int n){
    int i,j,mid,low,high;
    int tmp;
    for(i=1;i<n;i++){
        tmp=R[i];
        low=0;high=i-1;
        while (low<=high){
            mid=(low+high)/2;
            if(tmp<R[mid]){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        for(j=i-1;j>=high+1;j--){
            R[j+1]=R[j];
        }
        R[high+1]=tmp;
    }

}

void shellSort(int R[],int n){
    int i,j,gap;
    int tmp;
    gap=n/2;
    while (gap>0){
        for(i=gap;i<n;i++){
            tmp=R[i];
            j=i-gap;
            while (j>=0&&tmp<R[j]){
                R[j+gap]=R[j];
                j=j-gap;
                printf("\t%d",j);
            };
            R[j+gap]=tmp;
        }
        gap=gap/2;
    }
}


void bubbleSort(int a[],int n){
    int i,j,tmp;
    for(i=0;i<n-1;i++){
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
            }
        }
    }
}


void quickSort(int a[],int s,int t){
    int i=s,j=t,tmp;
    if(s<t){
        tmp=a[s];
        while (i!=j){
            while (i<j && a[j]>=tmp){
                j--;
            }
            a[i]=a[j];
            while (i<j && a[i]<tmp){
                i++;
            }
            a[j]=a[i];
        }
        a[i]=tmp;
        quickSort(a,s,i-1);
        quickSort(a,i+1,t);
    }
}
//
//int main(){
//    int array[]={9,2,5,6,3,2,1,4};
//    int array2[]={9,8,7,6,5,5,4,3,2,1,0};
//
//    bubbleSort(array,8);
//    printf("\n");
//    for(int i=0;i<8;i++){
//        printf("%d",array[i]);
//    }
//
//}
