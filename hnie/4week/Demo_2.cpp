#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
typedef unsigned char* byte_p;
void show(byte_p start,size_t len){
    for(int i = 0;i < len;i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

int tadd_ok(int x,int y){
    int sum = x + y;
    bool f1 = false,f2 = false;
    if(x < 0 && y < 0 && sum <= 0)
        f1 = true;
    if(x > 0 && y > 0 && sum >= 0)
        f2 = true;
    return f1 | f2;
}

int tsub_ok(int x,int y){
    int tmp = -y;
    show((byte_p) &y, sizeof (y));
    show((byte_p) &tmp, sizeof(y));
    return tadd_ok(x, -y);
}

int main(){
    int x = INT32_MIN;
    int tmp = -1;
//    while (temp){
//        if(temp & 1)
//            cout << 1;
//        else
//            cout << 0;
//        temp >>= 1;
//    }
//    cout << endl;
    printf("%d\n",-x);
    printf("%d\n",tsub_ok(1, x));
    return 0;
}