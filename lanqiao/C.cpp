#include "bits/stdc++.h"
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
char s[20];
int n;
ll ans;
ll calc(int l,int r){
    ll res = 0;
    for(int i = l;i <= r;i++){
        res = res * 10 + s[i] - '0';
    }
    return res;
}
void dfs(int k,ll tot){
    if(k > n) {
        ans += tot;
    }else{
        for(int i = k;i <= n;i++){
            dfs(i + 1,tot + calc(k,i));
        }
    }
}

int main() {
    scanf("%s",s + 1);
    n = strlen(s + 1);
    dfs(1,0);
    cout << ans << endl;
    return 0;
}