#include "iostream"
#include "vector"
#define N 20
#include "algorithm"
#include <cstring>
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int a2[N][N],a1[N][N],ans[N],n,m;
vector<pair<int,string>> v;
bool cmp(pair<int,string> p1,pair<int,string> p2){
    if (p1.first == p2.first)
        return p1.second.compare(p2.second) <= 0;
    else
        return p1.first < p2.first;
}
int dfs(int k){
    int x = 0;
    for(int i = 1;i <= m;i++){
        if(a1[k - 1][i]){
            x |= 1;
            a1[k][i] ^= 1;
            a1[k + 1][i] ^= 1;
            if(i - 1 >= 1)
                a1[k][i - 1] ^= 1;
            if(i + 1 <= m)
                a1[k][i + 1] ^= 1;
        }
        x <<= 1;
    }
    ans[k] = x >> 1;
    if(k >= n){
        int tmp = 0;
        for(int i = 1;i <= m;i++)
            tmp |= a1[n][i];
        return !tmp;
    }
    return dfs(k + 1);
}
int main() {
    cin >> n >> m;
    fore(i,1,n)
        fore(j,1,m)
            cin >> a2[i][j];
    int s = 1 << m;
    for(int i = 0; i < s; i++){
        memcpy(a1, a2, sizeof (a2));
        for(int j = 1;j <= m;j++){
            if(i & (1 << (m - j))){
                a1[1][j] ^= 1;
                a1[2][j] ^= 1;
                if(j - 1 >= 1)
                    a1[1][j - 1] ^= 1;
                if(j + 1 <= m)
                    a1[1][j + 1] ^= 1;
            }
        }
        ans[1] = i;
        if(dfs(2)){
            string str = "";
            int tot = 0;
            for(int j = 1;j <= n;j++)
                for(int k = 1;k <= m;k++) {
                    str += ans[j] & (1 << (m - k)) ? "1" : "0";
                    tot += ans[j] & (1 << (m - k)) ? 1 : 0;
                }
            v.push_back(make_pair(tot,str));
        }
    }
    if(v.size()){
        sort(v.begin(),v.end(),cmp);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cout << v[0].second[m * i + j] << " ";
            }
            cout << endl;
        }
    }else
        cout << "IMPOSSIBLE";
    return 0;
}