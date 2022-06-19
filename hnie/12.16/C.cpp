#include "bits/stdc++.h"
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
#define MOD 1000000007
using namespace std;
int n,m;
ll ans;
void dfs(ll s,int k){
    if(s % m == 0)
        ans++;
    fore(i,1,6){
        if(k != n)
            dfs(s * 10 + i,k + 1);
    }
}
int main() {
    cin >> n >> m;
    dfs(0,0);
    ans--;
    cout << ans % MOD << endl;
    return 0;
}