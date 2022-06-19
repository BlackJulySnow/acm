#include "bits/stdc++.h"
#define N 105
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int G[N][N],n,ru[N],chu[N];
void calcRu(){
    fore(i,1,n){
        int tot = 0;
        fore(j,1,n){
            if(G[j][i])
                tot++;
        }
        ru[i] = tot;
    }
}
void calcChu(){
    fore(i,1,n){
        int tot = 0;
        fore(j,1,n){
            if(G[i][j])
                tot++;
        }
        chu[i] = tot;
    }
}
int calc(){
    int ans = 0;
    fore(i,1,n){
        bool flag = true;
        fore(j,1,n){
            if(G[i][j] || G[j][i])
                flag = false;
        }
        if(flag)
            ans++;
    }
    return ans;
}
int main() {
    cin >> n;
    fore(i,1,n)
        fore(j,1,n)
            cin >> G[i][j];
    calcChu();
    calcRu();
    cout << calc() << endl;
    return 0;
}