#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define N 300005
inline int read(){
    int x = 0,f = 1;
    char c = getchar();
    while((c < '0' || '9' < c)) {
        if(c == '-'){
            f = -1;
            c = getchar();
            break;
        }
        c = getchar();
    }
    while ('0' <= c && c <= '9'){
        x = 10 * x + c - '0';
        c = getchar();
    }
    return f * x;
}
int a[N];
int main() {
    int t = read();
    while(t--){
        int n = read();
        fore(i,1,n)
            a[i] = read();

    }
    return 0;
}