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
int singleNumber2(int* nums, int numsSize) {
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
/*
 * 定义链表
 */
typedef struct listNode{
    int data;
    struct listNode *next;
}List;

void listSort(int *nums,int numsSize,List *&l){
    List *head,*head2,*d;
    for(int i=0;i<numsSize;i++){
        head2=l;
        head=l->next;
        if(l->next==NULL){
            head=(List *)malloc(sizeof(List));
            head->data=nums[i];
            head->next=NULL;
            l->next=head;
        } else {
            //正序插入
            while (head != NULL && nums[i]>=head->data){
                head2=head;
                head=head->next;
            }
            //头插
            d=(List *)malloc(sizeof(List));
            d->data=nums[i];
            d->next=head;
            head2->next=d;
        }
    }
}

/**
 * 使用链表进行排序试试
 * @param nums
 * @param numsSize
 * @return
 */
int singleNumber(int* nums, int numsSize) {
    List *l,*head,*head2,*d;
    //想要赋值给别的指针先分配空间,分配了内存空间但是怎么判断有没有值啊
    //带头指针
    l=(List *)malloc(sizeof(List));
    l->next=NULL;
    for(int i=0;i<numsSize;i++){
        head2=l;
        head=l->next;
        if(l->next==NULL){
            head=(List *)malloc(sizeof(List));
            head->data=nums[i];
            head->next=NULL;
            l->next=head;
        } else {
               //正序插入
                while (head != NULL && nums[i]>=head->data){
                    head2=head;
                   head=head->next;
                }
            //头插
            d=(List *)malloc(sizeof(List));
            d->data=nums[i];
            d->next=head;
            head2->next=d;
        }
    }
    head=l->next;
    while (head->next){
        if(head->data != head->next->data){
            return head->data;
        }
        head=head->next->next;
    }
    return head->data;
}
int main() {
    int num[] = {4,1,2,1,2};
    int s=singleNumber(num,5);
    printf("%d",s);
    return 0;
}