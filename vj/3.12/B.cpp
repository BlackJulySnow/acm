#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;


int main() {
    int t,n,a[200];
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n;
        fore(i,1,n)
            cin >> a[i];
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i;j++){
                fore(k,1,j){
                    if(a[k] + a[j] == a[i]){
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}