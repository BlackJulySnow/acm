#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n <= 2){
        cout << -1;
        return 0;
    }
    if(n == 3){
        cout << 210;
        return 0;
    }
    if(n == 4){
        cout << 1050;
        return 0;
    }
    int ans = 1050;
    for(int i = 5;i <= n;i++){
        ans *= 10;
        ans %= 10000;
        ans %= 210;
    }
    printf("1");
    int tot = ans < 100 ? n - 3 : n - 4;
    fore(i,1,tot)
        printf("0");
    cout << ans;
    return 0;
}