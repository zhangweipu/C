//
// Created by zwp on 17-12-6.
//

#include <stdio.h>
#include <cstring>

void delString(char *str1,char *str2){
    char *s1,*s2,*index;
    char *s3=str1,*s4=str2;
    s1=str1;s2=str2;
    int s1num=0,s2num=0;
    while (*s3!='\0'){
        s3++;
        s1num++;
    }
    while (*s4!='\0'){
        s4++;
        s2num++;
    }
    if(s1num < s2num){
        return;
    }
    while (*s1!='\0' && *s2!='\0'){
        if(*s1==*s2){
            s1++;
            s2++;
        } else{
            s2=str2;
            s1++;
        }

    }
    if(*s2=='\0' && s1!='\0'){
        index=s1-s2num;
    } else{
        return;
    }

    while(*s1!='\0'){
        *index++=*s1++;
    }
    *index='\0';
    delString(str1,str2);
}


//int main(){
////    int i=3,j=5,k,*r,*p,*q;
////    *(p=&k)=*(r=&i)* *(q=&j);
////    printf("%d",k);
//    char st1[]="aaddccffggaadd";
//    char st2[]="aa";
//    //delString(st1,st2);
//    int count=0;
////    while (*a!='\0'){
////        count++;
////        a++;
////    }
////    printf("%d",strlen(st2));
//    delString(st1,st2);
//  for(int i=0;st1[i]!='\0';i++){
//      printf("%c",st1[i]);
//  }
//}