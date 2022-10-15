//
// Created by B1GGersnow on 2022/9/30.
//

#include "stdio.h"

typedef struct _subject{
    char sno[20];
    char name[20];
    float chinese;
    float math;
    float english;
}subject;

subject a[5];

void print(int i){
    printf("%s\t%s\t%f\t%f\t%f\n",a[i].sno,a[i].name,a[i].chinese,a[i].math,a[i].english);
}

void scan(i){
    scanf("%s%s%f%f%f",a[i].sno,a[i].name,&a[i].chinese,&a[i].math,&a[i].english);
}

int main(){

    freopen("data","w",stdout);
    for(int i = 0;i < 5;i++){
        scan(i);
        print(i);
    }
    freopen("/dev/tty", "w", stdout);
    freopen("data","r",stdin);
    for(int i = 0;i < 5;i++){
        scan(i);
    }
    print(0);
    print(2);
    print(3);
    return 0;
}