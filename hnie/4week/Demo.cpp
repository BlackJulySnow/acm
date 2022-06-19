#include "bits/stdc++.h"
//#include "Demo_2.cpp"
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
typedef unsigned char* byte_p;

void show(byte_p start,size_t len){
    for(int i = 0;i < len;i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show((byte_p) & x,sizeof (int));
}

void show_float(float x){
    show((byte_p) & x,sizeof (float ));
}

void show_p(void * x){
    show((byte_p) & x,sizeof (void *));
}

int main() {
//    int a = 2;
    int c = 3;
    int val = 0x3f3f3f3f;
    int b = 1;
    printf("%x\n",&c);
//    show((byte_p)&val, 8);
//    printf("%d\n",val);
//    long long a = 12345;
    int *p = &val;
    printf("%x\n",p);
    show_p(p);
    show_int(12345);
    show_float(12345.0);
    return 0;
}