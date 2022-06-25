#include "bits/stdc++.h"
#define N 200005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
struct Node{
    int l,r;
    bool operator < (Node p){
        return r < p.r;
    }
}a[N];
int n,d,vis[N];
int main() {
    cin >> n >> d;
    fore(i,1,n){
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1,a + n + 1);
//    fore(i,1,n){
//        cout << a[i].l << " " << a[i].r << endl;
//    }
    int ans = 0,x = -1e9;
    for(int i = 1;i <= n;i++){
        if(x + d - 1 < a[i].l){
            ans++;
            x = a[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}