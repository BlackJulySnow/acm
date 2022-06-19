#include<bits/stdc++.h>
#define fore(i, l, r) for(int i = l;i <= r;i++)
#define N 500005
using namespace std;
#define ull unsigned long long
#define PI pair<int,ull>
int n,m;
vector<PI> vec[N];
ull dist[N];

void dfs(int u, int last, ull v) {
    dist[u] = v;
    for(PI x : vec[u]) {
        if(x.first == last)
            continue;
        dfs(x.first, u, v ^ x.second);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    int a,b;
    ull c;
    fore(i,1,n - 1) {
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    dfs(1,0,0);
    fore(i,1,m){
        cin >> a >> b >> c;
        cout << ((dist[a] ^ dist[b]) == c ? "Yes" : "No") << endl;
    }
}