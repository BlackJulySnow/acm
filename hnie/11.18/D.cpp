#include "bits/stdc++.h"
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define N 100005
int n,m,a[N],tot;
int main() {
    long long ans = 0;
    cin >> n >> m;
    fore(i,1,n + m + 1){
        cin >> a[i];
        if(a[i] < 0)
            tot++;
        ans += a[i];
    }
    sort(a + 1,a + n + m + 2);
    if(m == 0) {
        cout << ans;
        return 0;
    }
    if(tot != 0){

        for(int i = 1;i <= tot;i++)
            ans -= a[i] << 1;
    }
    cout << ans << endl;
    return 0;
}