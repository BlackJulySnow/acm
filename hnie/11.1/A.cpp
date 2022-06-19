#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int ans = 0;
    for(int i = 1;i <= 2020;i++){
        int k = i;
        while(k){
            if(k % 10 == 2){
                ans++;
            }
            k /= 10;
        }
    }
    cout << ans;
    return 0;
}