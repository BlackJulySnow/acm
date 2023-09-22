#include "bits/stdc++.h"
#define N 100005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int v[N][11],d[N][11];
int main() {
    int n;
    while (scanf("%d",&n) != EOF && n){
        memset(d,0x8f,sizeof(d));
        memset(v,0,sizeof(v));
        int maxn = 0;
        fore(i,1,n){
            int x,T;
            scanf("%d%d",&x,&T);
            v[T][x] ++;
            maxn = max(maxn,T);
        }
        d[0][5] = 0;
        for(int i = 1;i <= maxn;i++){
            d[i][0] = max(d[i - 1][0],d[i - 1][1]) + v[i][0];
            d[i][10] = max(d[i - 1][10],d[i - 1][9]) + v[i][10];
            fore(j,1,9){
                d[i][j] = max(max(d[i - 1][j], d[i - 1][j - 1]),d[i - 1][j + 1]) + v[i][j];
            }
        }
        int ans = 0;
        fore(i,0,10){
            ans = max(ans,d[maxn][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}