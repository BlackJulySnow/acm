#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

void get(int x){
    if(x <= 25)
        printf("%c",'A' + x - 1);
    else{
        get(x / 26);
        printf("%c",'A' + x % 26 - 1);
    }
}

int main() {
    int n;
    get(2019);
//    while (true){
//        cin >> n;
//        get(n);
//        cout << endl;
//    }
    return 0;
}