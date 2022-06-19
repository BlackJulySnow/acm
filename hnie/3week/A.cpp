#include "bits/stdc++.h"
#define N 200
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,a[N],k;
int main() {
    cin >> n;
    fore(i,1,n){
        cin >> k;
        a[k]++;
    }
    int ans = 0;
    fore(i,1,100){
        ans += a[i] / 2;
    }
    cout << ans / 2;
    return 0;
}