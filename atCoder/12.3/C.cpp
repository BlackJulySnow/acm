#include "bits/stdc++.h"
#define ll long long
#define fore(i, l, r) for(ll i = l;i <= r;i++)
using namespace std;
int main() {
    ll n,a,b,p,q,r,s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    ll l1 = max(1 - a,1 - b);
    ll r1 = min(n - a,n - b);
    ll l2 = max(1 - a,b - n);
    ll r2 = min(n - a,b - 1);

    fore(i,p,q){
        fore(j,r,s){
            if(a - i == b - j && l1 <= i - a && i - a <= r1){
                cout << "#";
            }else if(a - i == j - b && l2 <= i - a && i - a <= r2){
                cout << "#";
            }else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}