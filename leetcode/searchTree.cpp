//
//二叉收索树
// Created by zhang on 2018/5/8.
//
#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 50
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}Tree;

/**
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 *一个二叉搜索树具有如下特征：
 *节点的左子树只包含小于当前节点的数。
 *节点的右子树只包含大于当前节点的数。
 *所有左子树和右子树自身必须也是二叉搜索树。
 *思路一：使用中序递归遍历好像是行不通
 *思路二：不使用递归，中序遍历将数据放入数组中，然后判断是否有序
 * @param root
 * @return
 */
bool isValidBST(struct TreeNode* root) {
    int vals[50],i=0;
    //定义栈
    TreeNode *stack[50],*cur;
    int top=-1;
    //左子树进栈
    while (root){
        top++;
        stack[top]=root;
        root=root->left;
    }
    //出栈
    while (top!=-1){
        vals[i]=stack[top]->val;
        i++;
        cur=stack[top]->right;
        top--;
        //右子树进栈
        while (cur!=NULL){
            top++;
            stack[top]=cur;
            cur=cur->left;
        }
    }
    //判断有序
    for(int j=0;j<i-1;j++){
        if(vals[j]>vals[j+1]){
            return false;
        }
    }
    return true;
}

/**
 * todo:创建搜索二叉树
 * 当数组使用0为初始下标
 *使用递归进行创建，父和左子树的关系是2*i+1,和右子树的关系2*i+2 不可取，
 * 还有空的情况，碰到空就麻烦了，只对数组不存在NULL的情况有效
 * @param nums 数组
 * @param numsSize 数组长度
 * @param i 下标
 * @param t
 */
void createValidBST(int *nums,int numsSize,int i,Tree *&t){
    //判断是否越界
    if(!(i<numsSize)){
        return;
    }
    //判断数组存在NULL，并做处理,不会啊！！!!!!!
    if(nums[i]==NULL && i%2==0){
        createValidBST(nums,numsSize,i+2,t);
    } else if(nums[i] == NULL && i%2 == 1){

    }
    t=(Tree *)malloc(sizeof(Tree));
    t->val=nums[i];
    t->left=t->right=NULL;
    //左子树
    createValidBST(nums,numsSize,2*i+1,t->left);
    //右子树
    createValidBST(nums,numsSize,2*i+2,t->right);
}

void preTree(Tree *t){
    if(t==NULL){
        return;
    }
    printf("%d",t->val);
    preTree(t->left);
    preTree(t->right);
}
/**
 * 实现一个map的数据结构
 */
typedef struct mapNode{
    int key;
    int value;
    struct mapNode *next;
}map;
/**
 * 求摩取余发，model=10
 */
typedef struct hashNode{
    int len;
    struct mapNode *node[9];
}hashMap;

/**
 * 初始化map
 * @param m
 */
void initMap(hashMap *&m){
    m=(hashMap *)malloc(sizeof(hashMap));
    for (int i = 0; i < 10; ++i) {
        m->node[i]=NULL;
    }
}

/**
 *
 * @param m
 */
void insertMap(int k,int v,hashMap *&m){
    if(m==NULL){
        return;
    }
    //尾插法
    map *temp,*a=(map *)malloc(sizeof(map));
    a->key=k;
    a->value=v;
    a->next=NULL;
    int key=abs(k%10);
    temp=m->node[key];
    m->node[key]=a;
    a->next=temp;
}



/**
 * 查找是否c
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    int length;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {

}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {

}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {

}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {

}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */


int main(){
    int nums[]={2,NULL,1,3};
    Tree *t;
    createValidBST(nums,4,0,t);
    if(isValidBST(t)){
        printf("shi");
    } else{
        printf("bushi");
    }
    preTree(t);
}