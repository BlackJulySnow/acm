#include "bits/stdc++.h"
#define N 100005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
double a[N],b[N],sum[N];
int main() {
    int n,len;
    cin >> n >> len;
    fore(i,1,n) {
        cin >> a[i];
    }
    double eps = 1e-5;
    double l = -1e6,r = 1e6;
    while (r - l > eps){
        double mid = (l + r) / 2;
        fore(i,1,n) {
            b[i] = a[i] - mid;
            sum[i] = sum[i - 1] + b[i];
        }
        double ans = -1e10;
        double min_val = 1e10;
        fore(i,len,n){
            min_val = min(min_val, sum[i - len]);
            ans = max(ans, sum[i] - min_val);
        }
        if(ans >= 0)
            l = mid;
        else
            r = mid;
//        cout << r - l << endl;
    }
//    printf("123");
    cout << int(r * 1000) << endl;

    return 0;
}