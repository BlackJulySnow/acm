#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int G[10][10];
int v[10],vis[10];
void dfs(int x){
    for(int i = 1;i <= 7;i++){
        if(!vis[i] && G[x][i] && v[i]){
            vis[i] = true;
            dfs(i);
        }
    }
}
int main() {
    int ans = 0;
    G[1][2] = G[2][1] = true;
    G[1][6] = G[6][1] = true;
    G[2][3] = G[3][2] = true;
    G[2][7] = G[7][2] = true;
    G[3][4] = G[4][3] = true;
    G[3][7] = G[7][3] = true;
    G[4][5] = G[5][4] = true;
    G[5][6] = G[6][5] = true;
    G[5][7] = G[7][5] = true;
    G[6][7] = G[7][6] = true;
    for(int i = 0;i < (1 << 7);i++){
        for(int j = 0;j < 7;j++){
            v[j + 1] = (i >> j) & 1;
//            cout << v[j + 1];
        }
//        cout << endl;
        for(int j = 1;j <= 7;j++){
            if(v[j]){
                memset(vis,0,sizeof(vis));
                vis[j] = true;
                dfs(j);
                bool flag = true;
                for(int k = 1;k <= 7;k++){
                    if(vis[k] != v[k])
                        flag = false;
                }
                if(flag)
                    ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}