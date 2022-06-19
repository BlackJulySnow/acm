#include "bits/stdc++.h"
#define N 100
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int t,n,a[N],sum;
int main() {
    cin >> t;
    while(t--){
        cin >> n;
        sum = 0;
        fore(i,1,n){
            cin >> a[i];
            sum += a[i];
        }
        if(sum >= n)
            cout << abs(n - sum) << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}