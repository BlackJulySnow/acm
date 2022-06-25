#include "bits/stdc++.h"
#define N 200005
using namespace std;
struct Node{
    int to,next;
}e[N << 1];
int head[N],tot;
void addE(int u,int v){
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
int d1[N],d2[N],n,x,a,b;
void dfs(int fa,int u,int * d){
    d[u] = d[fa] + 1;
    for(int i = head[u];i;i = e[i].next){
        int v = e[i].to;
        if(v == fa)
            continue;
        dfs(u,v,d);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i = 1;i < n;i++){
        cin >> a >> b;
        addE(a,b);
        addE(b,a);
    }
    dfs(0,1,d1);
    dfs(0,x,d2);
    int now = 0;
    for(int i=1;i<=n;i++){
        if(d2[i]<d1[i]){
            now=max(now,2*d1[i]);
        }
    }
    cout << now - 2 << endl;
    return 0;
}