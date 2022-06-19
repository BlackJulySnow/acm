#include "bits/stdc++.h"
#define N 1005
#define M 1005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int head[N],tot,ru[N],chu[N];
struct Edge{
    int v,next,w;
}e[M];
void addE(int u,int v,int w){
    e[++tot].next = head[u];
    head[u] = tot;
    e[tot].v = v;
    e[tot].w = w;
}
void calcRu(){
    fore(u,1,n){
        for(int i = head[u];i;i = e[i].next){
            int v = e[i].v;
            ru[v]++;
        }
    }
}
void calcChu(){
    fore(u,1,n){
        int tot = 0;
        for(int i = head[u];i;i = e[i].next)
            tot++;
        chu[u] = tot;
    }
}
int calc(){
    int ans = 0;
    fore(u,1,n){
        int tot = 0;
        for(int i = head[u];i;i = e[i].next)
            tot++;
        if(tot == 0)
            ans++;
    }
    return ans;
}
int main() {
    cin >> n >> m;
    fore(i,1,m){
        int x,y,w;
        cin >> x >> y >> w;
        addE(x,y,w);
    }
    calcChu();
    calcRu();
    cout << calc();
    return 0;
}