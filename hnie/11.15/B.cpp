#include "bits/stdc++.h"
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    ll day = 60 * 24;
    ll ans = 0;
    for(int i = 1921 + 1;i <= 2020;i++){
        int year = i % 4 == 0 ? 366 : 365;
        ans += day * year;
    }
    ans -= day * 22;
    cout << ans << endl;
    return 0;
}