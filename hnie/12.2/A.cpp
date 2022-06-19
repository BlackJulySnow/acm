#include "bits/stdc++.h"
#define MOD 1000000007
#define N 100005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int d[N][2][2],n,m;
int main() {
    cin >> n >> m;
    d[1][0][0] = d[1][1][0] = 1;
    fore(j,1,n){
        fore(i,1,m){
            if(i == 1 && j == 1)
                continue;
            int a = d[i][0][0];
            int b = d[i][0][1];
            int c = d[i][1][0];
            int k = d[i][1][1];
            d[i][0][0] = d[i - 1][1][1] + d[i - 1][1][0] + c + k;
            d[i][0][1] = d[i - 1][0][0] + c + k + a + d[i - 1][1][0] + d[i - 1][1][1];
            d[i][1][0] = d[i - 1][0][0] + d[i - 1][0][1] + a + b;
            d[i][1][1] = d[i - 1][1][0] + a + b + c + d[i - 1][0][0] + d[i - 1][0][1];
        }
    }
    cout << d[m][0][0]<< endl;
    return 0;
}