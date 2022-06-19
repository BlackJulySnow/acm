#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int t,h,e;
    cin >> t >> h >> e;
    double ans = (double)t * 0.2 + h * 0.3 + e * 0.5;
    cout << int(ans);
    return 0;
}