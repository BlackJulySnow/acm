#include "bits/stdc++.h"
#define N 2005
#define M 5005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int head[N],tot,d[N][N],vis[N],n,m,c;
struct Edge{
    int v,next,w;
}e[M];
void addE(int u,int v,int w){
    e[++tot].next = head[u];
    head[u] = tot;
    e[tot].v = v;
    e[tot].w = w;
}
priority_queue<pair<int,int>> pq;
void dij(int start){
    memset(vis,0,sizeof(vis));
    pq.push(make_pair(0,start));
    d[start][start] = 0;
    while (!pq.empty()){
        int x = pq.top().second;
        pq.pop();
        if(vis[x])
            continue;
        vis[x] = 1;
        for(int i = head[x];i;i = e[i].next){
            int y = e[i].v,w = e[i].w;
            if(!vis[y] && d[start][x] + w < d[start][y]){
                d[start][y] = d[start][x] + w;
                pq.push(make_pair(-d[start][y],y));
            }
        }
    }
}
int main() {
    memset(d,0x3f,sizeof(d));
    cin >> n >> m >> c;
    bool flag = true;
    fore(i,1,m){
        int u,v,w;
        cin >> u >> v >> w;
        addE(u,v,w);
        if(w <= c)
            flag = false;
    }
    if(flag){
        cout << 0 << endl;
        return 0;
    }
    fore(i,1,n)
        dij(i);
    int res = 1e9;
    fore(i,1,n){
        fore(j,i + 1,n){
            if(d[i][j] != d[0][0] && d[j][i] != d[0][0])
                res = min(res,d[i][j] + d[j][i]);
        }
    }
    if(res <= c)
        cout << 2 << endl;
    else
        cout << 1 << endl;
    return 0;
}