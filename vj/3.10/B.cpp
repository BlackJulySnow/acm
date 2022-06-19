#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define N 200005
int main() {
    int t,a[N],sum[N],n;
    cin >> t;
    while(t--){
        cin >> n;
        memset(sum,0,sizeof(sum));
        fore(i,1,n) {
            cin >> a[i];
            sum[i] = sum[i - 1] & a[i];
        }
        fore(i,1,n){

        }
    }
    return 0;
}