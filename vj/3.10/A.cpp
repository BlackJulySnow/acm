#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int vis[1000];
int main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        memset(vis,0,sizeof(vis));
        cin >> n >> k;
        if(k * 2 + 1 > n){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1;i <= k;i++){
            vis[i] = vis[n - i + 1] = 1;
            cout << i << " " << n - i + 1 << " ";
        }
        for(int i = 1;i <= n;i++)
            if(!vis[i])
                cout << i << " ";
        cout << endl;
    }
    return 0;
}