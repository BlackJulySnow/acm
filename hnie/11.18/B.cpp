#include "bits/stdc++.h"
#define N 100005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

long long d[N],n,dep,x;

int main() {
    cin >> n;
    for(long long i = 0;i < n;){
//        cout << i << endl;
        long long j,tot = 0;
        for(j = 1;(j <= (1 << dep)) && i + j <= n; j++){
            cin >> x;
            d[dep + 1] += x;
            tot++;
        }
        i += tot;
//        cout << d[dep + 1] << endl;
        dep++;
    }
    long long ans = 0,ansD = 0;
    for(int i = 1;i <= dep;i++){
        if(d[i] > ans){
            ansD = i;
            ans = d[i];
        }
    }
    cout << ansD;
    return 0;
}