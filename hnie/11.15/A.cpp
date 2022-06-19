#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int n = 10000,ans = 0;
    while (1){
        for(int i = 1;i <= 60 && n > 0;i++){
            n -= 10;
            ans++;
        }
        if(n <= 0)
            break;
        n += 300;
        ans += 60;
    }
    cout << ans << endl;
    return 0;
}