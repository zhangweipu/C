#include <stdio.h>
#include <malloc.h>

/**
 * 在已排序数组中移除重复项，返回无重复数组的长度。
 * 数组：[1,2,3,4,4]
 * 结果数组：[1,2,3,4]
 * 返回len：4
 * @param nums
 * @param numsSize
 * @return
 */
int removeDuplicates(int *nums, int numsSize) {
    if(numsSize==0){
        return 0;
    }
    if(numsSize==1){
        return 1;
    }
    int count=1;
    int i=0;
    while(true){
        if((i+count)==numsSize){
            break;
        }
        if(nums[count-1]==nums[count]){
            for(int j=count;j<numsSize-1;j++){
                nums[j]=nums[j+1];
            }
            i++;
        }else{
            count++;
        }
    }
    return count;
}

/**
 * 算求最高利润
 * @param prices
 * @param pricesSize
 * @return
 */
int maxProfit(int *prices, int pricesSize) {
    int sum = 0;
    int buy = 0, sell = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i - 1] <= prices[i]) {
            sell = i;
            if (i == pricesSize - 1) {
                sum += (prices[sell] - prices[buy]);
                return sum;
            }
        } else {

            if (sell == 0 && buy == pricesSize - 1) {
                return 0;
            } else if (prices[i - 1] > prices[i]) {
                if (sell != 0 && sell > buy) {
                    sum += (prices[sell] - prices[buy]);
                }
                buy = i;
            }
        }
        if (buy == 0 && sell == pricesSize - 1) {
            return prices[sell] - prices[buy];

        }

    }
    return sum;
}

/**
 *
 * @param nums
 * @param numsSize
 * @param target
 * @return
 */
int *twoSum(int *nums, int numsSize, int target) {
    int *num = (int *) malloc(sizeof(int) * 2);
    int temp;
    for (int i = 0; i < numsSize; i++) {
        temp = target - nums[i];
        for (int j = i; j < numsSize; j++) {
            if (temp == nums[j]) {
                num[0] = i;
                num[1] = j;
            }
        }
    }
    return num;
}
/**
 * 数组旋转
 * @param nums
 * @param numsSize
 * @param k
 */
void rotate(int* nums, int numsSize, int k) {
    int temp;
    for(int i=0;i<k;i++){
        temp=nums[numsSize-1];
        //旋转
        for(int j=numsSize-1;j>0;j--){
            nums[j]=nums[j-1];
        }
        nums[0]=temp;
        for(int m=0;m<k;m++){
            printf("%d",nums[m]);
        }
    }
}

/**
 *定义hash数组
 */
typedef struct lnode{
    int data;
    struct lnode *next;
}list;
typedef struct node{
    list *hash[10];
}hash;
/**
 * 初始化hash
 * @param h
 */
void initHash(hash *&h){
    h=(hash*)malloc(sizeof(hash));
    for (int i = 0; i < 10; i++) {
        h->hash[i]=NULL;
    }
}
/**
 *查找数组中是否存在重复项，有返回false没有返回true
 * @param nums
 * @param numsSize
 * @return
 */
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize==0 || numsSize == 1){
        return false;
    }
    hash *h;
    //初始化
    initHash(h);
    //添加进hash数组
    for(int i=0;i<numsSize;i++){
        int key;
        key=abs(nums[i]%9);
        list *l=h->hash[key];
        //比较
        while (l!=NULL && l->next!=NULL){
            if(l->data==nums[i]){
                printf("%d",nums[i]);
                return true;
            }
            l=l->next;
        }
            //执行插入时，第一版出错，没理解空指针
            list *l1=(list *)malloc(sizeof(list));
            l1->data=nums[i];
            l1->next=NULL;
            list *t;
            if(h->hash[key]==NULL){
                h->hash[key]=l1;
            } else{
                t=h->hash[key]->next;
                h->hash[key]->next=l1;
                l1->next=t;
            }
    }
    return false;
}


int main() {
    int num[] = {};  if(containsDuplicate(num,0)){
        printf("%s","true");
    } else{
        printf("%s", "false");
    }
    return 0;
}