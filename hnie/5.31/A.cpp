//
// Created by B1GGersnow on 2022/5/31.
//

#include "bits/stdc++.h"
#define N 30
using namespace std;
int a[N][N],v[N],n,ans = 1e9;

void dfs(int k,int tot){
    if(tot >= ans)
        return;
    if(k > n){
        ans = min(ans,tot);
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!v[i]){
            v[i] = 1;
            dfs(k + 1,tot + a[k][i]);
            v[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)
            cin >> a[i][j];
    }
    dfs(1,0);
    cout << ans << endl;
    return 0;
}