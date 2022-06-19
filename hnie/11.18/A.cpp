#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

bool check(int x){
    while(x){
        if(x % 10 == 2 || x % 10 == 0 || x % 10 == 1 || x % 10 == 9)
            return true;
        x /= 10;
    }
    return false;
}

long long n,ans;
int main() {
    cin >> n;
    for(int i = 1;i <= n;i++){
        if(check(i))
            ans += i;
    }
    cout << ans << endl;
    return 0;
}