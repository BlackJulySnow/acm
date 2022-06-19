#include "bits/stdc++.h"

using namespace std;
inline int read(){
    int x = 0;
    char c = getchar();
    while (c < '0' || '9' < c)
        c = getchar();
    while ('0' <= c && c <= '9'){
        x = 10 * x + c - '0';
        c = getchar();
    }
    return x;
}

#define N 4000005

int tire[N][2],node,cnt[N];

void add(int x){
    int s=0;
    for(int i=25;i>=0;i--){
        int v= (x >> i) & 1;
        if(!tire[s][v])
            tire[s][v]=++node;
        s=tire[s][v];
        cnt[s]++;
    }
}

int prm[N],tot,vis[N];

void prime(int n){
    for(int i=2;i<=n;i++){
        if(vis[i] == 0) {
            prm[tot++]=i;
            add(i);
        }
        for(int j=0; prm[j] <= n / i; j++){
            vis[prm[j] * i]=true;
            if(i % prm[j] == 0) break;
        }
    }
}

int main() {
    prime(N - 1);
    int t = read();
    while (t--) {
        int x = read();
        int s = 0;
        int ans = 0;
        for (int i = 25; i >= 0; i--) {
            int v = (x >> i) & 1;
            if ((x >> i) & 1){
                ans += cnt[tire[s][v]];
                s = tire[s][!v];
            }
            else
                s = tire[s][v];
            if (!s) break;
        }
        cout << ans << endl;
    }
}