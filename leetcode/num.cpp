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
    int length[10];
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
/**
 * 只出现一次的数字
 * 给定一个非空整数数组，除了某个元素只出现一次以外，
 * 其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 这是最差的办法了
 * @param nums
 * @param numsSize
 * @return
 */
int singleNumber1(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
        for (int j = 0; j <numsSize ; j++) {
            if(i!=j && nums[i]==nums[j]){
                nums[i]=NULL;
                nums[j]=NULL;
            }
        }
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=NULL){
            return nums[i];
        }
    }
    return 0;
}
/**
 * 一组数，只有一个单其他是双跳出单
 * 全部遍历一次，放入hash表，找出长度为一的....
 * 想复杂了。
 * 先排序，再一次走两步
 * @param nums
 * @param numsSize
 * @return
 */
int singleNumber(int* nums, int numsSize) {
    hash *h=(hash *)malloc(sizeof(hash));
    for (int i = 0; i < 10; i++) {
        h->length[i]=0;
        h->hash[i]=NULL;
    }
    for (int j = 0; j < numsSize; ++j) {
        list *child,*temp,*t;
        int key=abs(nums[j]%9);
        child=h->hash[key];
        if(child == NULL){
            temp=(list *)malloc(sizeof(list));
            temp->data=nums[j];
            temp->next=NULL;
            //因为child是NULL没有指向任何地方
            h->hash[key]=temp;
        } else{
            temp=(list *)malloc(sizeof(list));
            temp->data=nums[j];
            temp->next=NULL;
            //相同的放到相邻,不存在相同的肯定放在最后了,尾插法不行，
            //用头插法
            if(child->data==nums[j] && child->next != NULL){
                child=child->next;
            }
            while (child->next != NULL && child->data != nums[j]){
                child=child->next;
            }
            t=child->next;
            child->next=temp;
            temp->next=t;
        }
        h->length[key]++;
    }
    //找出不同
    for(int i=0;i<10;i++){
        if(h->hash[i]!=NULL && h->length[i]%2!=0){
            if(h->length[i]==1){
                return h->hash[i]->data;
            } else{
                list *last=h->hash[i];
                while (last->next!=NULL){
                    last=last->next;
                }
                return last->data;
            }

        }
    }
    return NULL;
}
int main() {
    int num[] = {10,186,-49,176,118,167,-61,189,6,-24,7,-93,71,112,187,45,-36,38,82,108,-46,112,51,165,-37,159,1,-53,7,38,90,181,-23,91,-42,172,-95,130,84,149,-47,68,126,-67,175,22,121,131,84,114,60,64,182,-75,-17,-71,69,-92,103,-91,-91,86,126,166,33,-36,-80,-37,118,-80,-18,127,36,-71,-82,-82,144,12,57,149,71,91,-83,-100,-30,45,186,16,-51,-72,-83,107,140,-97,-93,1,12,189,-61,-50,180,98,96,-29,193,167,57,-45,16,6,-76,4,109,-23,22,144,190,-97,193,-51,-99,-79,-47,142,107,175,109,121,190,90,34,32,63,-24,41,-53,41,89,130,-18,-99,103,86,127,-30,102,32,-49,181,-60,114,60,-29,182,-75,168,96,51,33,142,108,69,10,-57,166,48,82,161,-17,-50,102,63,-45,140,180,176,-95,36,-46,168,187,161,-72,-100,-42,165,-76,-67,89,159,64,34,98,4,-60,172,-79,68,48,131,-57
    };
    int s=singleNumber(num,1000);
    printf("%d",s);
    return 0;
}