//
// Created by zwp on 17-8-30.
//迷宫问题
//
#include<stdio.h>

#define MaxSize 50

typedef struct{
    int i;
    int j;
    int di;
}box;

typedef struct{
    box data[MaxSize];
    int top;
}StType;


int mg[10][10]={
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
};


/**
 * 求解路径   有bug还没认真去调试
 * @param xi
 * @param yi
 * @param xe
 * @param ye
 * @result (xi,yi)->(xe,ye)
 * @return
 */
bool mgPath(int xi,int yi,int xe,int ye){
    int i,j,k,di,find;
    StType st;
    st.top=-1;
    st.top++;
    st.data[st.top].i=xi;
    st.data[st.top].j=yi;
    st.data[st.top].di=-1;
    while (st.top>-1){
        i=st.data[st.top].i;
        j=st.data[st.top].j;
        di=st.data[st.top].di;
        if(i==xe && j==ye){
            printf("迷宫路径如下");
            for(k=0;k<=st.top;k++){
                printf("\t %d %d",st.data[k].i,st.data[k].j);
                if((k+1)%5==0){
                    printf("\n");
                }
            }
            printf("\n");
            return true;
        }

        find=0;
        while (di<4 && find==0){
            di++;
            switch (di){
                case 0:i=st.data[st.top].i-1;
                    j=st.data[st.top].j;
                    break;
                case 1:i=st.data[st.top].i;
                    j=st.data[st.top].j+1;
                    break;
                case 2:i=st.data[st.top].i+1;
                    j=st.data[st.top].j;
                    break;
                case 3:i=st.data[st.top].i;
                    j=st.data[st.top].j-1;
                    break;
            }
            if(mg[i][j]==0){
                find=1;
            }
        }
        if(find==1){
            st.data[st.top].di=di;
            st.top++;
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=-1;
            mg[i][j]=-1;
        } else{
            mg[st.data[st.top].i][st.data[st.top].j]=0;
            st.top--;
        }

    }
    return false;
}

//int main(){
//    if(!mgPath(1,1,8,8));
//    printf("无解");
//}