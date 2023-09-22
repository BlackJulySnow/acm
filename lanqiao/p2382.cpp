#include "bits/stdc++.h"

using namespace std;
bool prime(int k){
    for (int i = 2;i <= sqrt(k);i++) {
        if (k % i == 0)
            return false;
    }
    return true;
}
int ans;
bool calc(int n){
    bool flag;
    flag = true;
    for(int i = 10;n % (i / 10) != n;i *= 10){
        if(!prime(n % i))
            flag = false;
    }
    if(flag){
        ans = max(ans,n);
    }
    return flag;
}
int dfs(int n){
    if(calc(n * 10 + 3))
        dfs(n * 10 + 3);
    if(calc(n * 10 + 5))
        dfs(n * 10 + 5);
    if(calc(n * 10 + 7))
        dfs(n * 10 + 7);
}

int main(){
//    dfs(0);
//    cout << ans;
    cout << 373;
    return 0;
}