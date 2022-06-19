#include "bits/stdc++.h"
#define N 200005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,k,a2[N],d[N],v[N],ans1,ans2;

int main() {
    cin >> n >> k;
    v[k] = 1;
    fore(i,1,n){
        cin >> a2[i];
    }
    fore(i,1,k - 1){
        fore(j,1,i - 1){
            if(a2[i] > a2[j])
                d[i] = max(d[i],d[j] + 1);
        }
    }
    fore(i,k + 1,n){
        fore(j,k + 1,i - 1){
            if(a2[i] > a2[j])
                d[i] = max(d[i],d[j] + 1);
        }
    }
    fore(i,1,n){
        if(i < k)
            ans1 = max(ans1,d[i]);
        else
            ans2 = max(ans2,d[i]);
    }
    cout << ans1 + ans2 << endl;
    return 0;
}