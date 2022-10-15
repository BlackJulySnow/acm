#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,a,b,m;
int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    cin >> n;
    fore(i,1,n){
        cin >> a >> b >> m;
        if(b % gcd(a,m)){
            cout << "impossible" << endl;
        }

    }
    return 0;
}