#include "bits/stdc++.h"
#define MAXN 10005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int phi[MAXN],vis[MAXN],pri[MAXN],cnt;

void init() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!vis[i]) {
            phi[i] = i - 1;
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] >= MAXN) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j]) {
                phi[i * pri[j]] = phi[i] * (pri[j] - 1);
            } else {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
        }
    }
}
int get(int s,int k){
    if(s <= 9){
        if(s == k)
            return true;
        else
            return false;
    }else{
        if(s % 10 == k)
            return true;
        else{
            return get(s / 10,k);
        }
    }
}
int main() {
    init();
    int k,n;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0;pri[i] <= n && i < cnt;i++){
//        cout << pri[i] << endl;
        if(!get(pri[i],k))
            ans++;
    }
    cout << ans << endl;
    return 0;
}