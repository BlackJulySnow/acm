#include "bits/stdc++.h"
#define N 100005
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,a[N],d[N];
int main() {
    cin >> n;
    fore(i,1,n){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int minN = 1e9 + 5;
    fore(i,2,n){
        d[i] = a[i] - a[i - 1];
        minN = min(d[i],minN);
    }
    if(minN == 0){
        cout << n << endl;
        return 0;
    }
    ll ans = n;
    fore(i,2,n){
        ans += d[i] / minN - 1;
    }
    cout << ans << endl;
    return 0;
}