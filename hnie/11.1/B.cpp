#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a % b);
}

int main() {
    int ans = 0;
    for(int i = 1;i <= 2020;i++){
        for(int j = 1;j <= 2020;j++){
            if(gcd(i,j) == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}