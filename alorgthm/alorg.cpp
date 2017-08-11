//
// Created by zwp on 17-8-11.
//
#include <stdio.h>

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
