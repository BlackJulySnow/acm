#include "bits/stdc++.h"
#define N 1000
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
//int a[N][N],sum[N][N];
inline int read(){
    int x = 0;
    char c = getchar();
    while (c < '0' || '9' < c)
        c = getchar();
    while ('0' <= c && c <= '9'){
        x = 10 * x + c - '0';
        c = getchar();
    }
    return x;
}
void out(int x){
    if(x <= 9)
        putchar('0' + x);
    else{
        out(x / 10);
        putchar(x % 10 + '0');
    }
}
int main() {
//    out(123);
    int n = read();
    int m = read();
    int a[n+1][m+1];
    int sum[n+1][m+1];
//    vector<int> a
    fore(i,1,n){
        fore(j,1,m){
            a[i][j] = read();
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
//    printf("%d\n",sum[3][3]);
    int q = read();
    fore(i,1,q){
        int a = read();
        int b = read();
        int c = read();
        int d = read();
        out(sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1]);
        putchar('\n');
//        printf("%d\n",);
    }
    return 0;
}