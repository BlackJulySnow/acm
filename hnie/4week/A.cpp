#include "bits/stdc++.h"
#define FOR(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,c,v[20],w[20],res,state[20],temp[20];
inline int read(){
    char c = getchar();
    int ans = 0;
    while(c < '0' || '9' < c){
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        ans = 10 * ans + c - '0';
        c = getchar();
    }
    return ans;
}
void get(int k, int last, int s){
    if(k > n){
        if (s > res){
            res = s;
            memcpy(state, temp, sizeof(state));
        }
        return;
    }
    temp[k] = 0;
    get(k + 1, last, s);
    temp[k] = 1;
    if (last - w[k] >= 0)
        get(k + 1, last - w[k], s + v[k]);
}

int main() {
    n = read();
    FOR(i,1,n)
        w[i] = read();
    FOR(i,1,n)
        v[i] = read();
    c = read();
    get(0, c, 0);
    FOR(i,1,n)
        cout << state[i];
    cout << endl << res;
    return 0;
}