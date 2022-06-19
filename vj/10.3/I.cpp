#include "bits/stdc++.h"
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define MOD 1000000007

ll ksm(ll a,ll b){
    ll ans = 1;
    while (b){
        if(b & 1)
            ans = (ans * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
ll calc(ll n){
    ll ans = (2 * (6 * ksm(2,n/2) + 8 * ksm(2,(n-1)/2) - (4*n+8))) % MOD;
//    cout << (2 * (6 * ksm(2,n/2) + 8 * ksm(2,(n-1)/2) - (4*n+8))) % MOD << endl;
    ans -= (4 * (ksm(2,n/2) + ksm(2, (n-1)/2) - (n+1))) % MOD;
//    cout << (4 * (ksm(2,n/2) + ksm(2,(n-1)/2) - (n+1))) % MOD << endl;
//    cout << ans << endl;
    ans %= MOD;
    while (ans < 0)
        ans += MOD;
    return ans % MOD;
}
int main() {
    ll n;
    cin >> n;
    if(n == 1){
        cout << 1;
    }else if(n == 2){
        cout << 2;
    }else if(n == 3){
        cout << 6;
    }else
        cout << calc(n - 3) * n % MOD;
    return 0;
}