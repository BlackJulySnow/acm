#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int a = 1,b = 1,c = 1;
    for(int i = 4;i <= 20190324;i++){
        int k = a + b + c;
        a = b;
        b = c;
        c = k;
        a %= 10000;
        b %= 10000;
        c %= 10000;
    }
    cout << c << endl;
    return 0;
}