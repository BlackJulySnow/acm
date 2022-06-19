#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define N 100005
int n,k;
ll a2[N],a1[N];

bool check(ll mid) {
    ll tot=0,cnt=0;
    for(int i=1;i<=n;i++) {
        if(a2[i] * a2[i] > mid)
            return 0;
        if(i == 1) {
            cnt++;
            tot= 1ll * a2[i] * a2[i];
            continue;
        }
        if(tot + a2[i] * a2[i] <= mid)
            tot += a2[i] * a2[i];
        else{
            tot= a2[i] * a2[i];
            cnt++;
        }
    }
    return cnt <= k;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a2[i];
    ll ans=-1;
    ll l=1,r=1e18;
    while(l<=r) {
        ll mid= (l + r) >> 1;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }else
            l = mid + 1;
    }
    cout << ans << endl;
}