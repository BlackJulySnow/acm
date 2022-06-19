#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
double a[20],b[20],k;
int main() {
    for(int i = 1;i <= 13;i++)
        cin >> a[i];

    for(int i = 1;i <= 13;i++)
        cin >> b[i];
    cin >> k;
    double ans = 0;
    for(int i = 1;i <= 13;i++)
        ans += a[i] * b[i] + k;
    cout << ans << endl;
    return 0;
}