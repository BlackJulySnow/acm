#include "iostream"
#include "cstring"
#include "queue"
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define M 3000
#define N 505
struct Node{
    int w,to,next;
}e[M << 1];
int head[N],tot,n,m,k;

void addEdge(int u,int v,int w){
    e[++tot].to = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot;
}

bool v[N];
int d[N],cnt[N];
queue<int> q;

bool spfa(){
    while (!q.empty())
        q.pop();
    memset(v,0,sizeof(v));
    memset(cnt,0,sizeof(cnt));
    memset(d,0x3f,sizeof(d));
    d[1] = 0,v[1] = true;
    cnt[1] = 1;
    q.push(1);
    while (q.size()){
        int x = q.front();q.pop();
        v[x] = false;
        for(int i = head[x];i;i = e[i].next){
            int y = e[i].to,w = e[i].w;
            if(d[y] > d[x] + w){
                d[y] = d[x] + w;
//                if(d[1] < 0)
//                    return true;
                if(!v[y]) {
                    q.push(y), v[y] = true;
                    cnt[y]++;
                    if(cnt[y] >= 30)
                        return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        tot = 0;
        memset(head,0,sizeof(head));
        fore(i, 1, m) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        fore(i, 1, k) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, -w);
        }
        if(spfa()){
            cout << "YES" << endl;
        }else
            cout << "NO" << endl;
    }

    return 0;
}