#include <stdio.h>
void go_south_east(int *lat,int *lon){
    *lat=*lat-1;
    *lon=*lon+1;
}

void fortune_cookie(char quote[]){
    printf("%p\n",&quote);
    printf("%i\n", sizeof(quote));
    printf("%c",quote[1]);
}

/*
 * 指针
 */

void get_choice(){
    int cout[]={1,3,2,6};
    int *choice=cout;
    cout[0]=5;
    cout[1]=4;
    cout[1]=*choice;
    printf("%d",cout[1]);
}

void skip(char *msg){
//    printf("%s\n",*msg);
//    printf("%s\n",*(msg+1));
    puts(msg+6 );
}

//int main(){
//    int lat=32;
//    int lon=32;
//    go_south_east(&lat,&lon);
//    printf("%d%d\n",lat,lon);
//
//    char quote[]={'a','v','D'};
//    fortune_cookie(quote);
//
//
//    char *msg="i don't know";
//    skip(msg);
//
//    return 0;
//}