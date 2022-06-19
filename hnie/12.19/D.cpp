#include "bits/stdc++.h"
#define N 1000005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int v[N],prm[N],siz[N],tot;
int g(int x){
    int ans = 0;
    while (x){
        ans++;
        x >>= 1;
    }
    return ans;
}
void primes(int n){
    for(int i = 2;i <= n;i++){
        if(v[i])
            continue;
        prm[++tot] = i;
        siz[tot] = g(i);
        for(int j = i;j <= n / i;j++)
            v[i * j] = 1;
    }
}
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
set<int> s;
int main() {
//    cout << read();
    int t;
    primes(1000000);
    t = read();
    int n = t;
//    freopen("data.out","w",stdout);
//    cout << "[0,";

    while(t--){
        s.clear();
        int x = read();
        int q = g(x);
        for(int i = 1;i <=tot && siz[i] <= q;i++){
            int k = x ^ prm[i];

//            cout << k << endl;
            if(k >= x)
                continue;
            if(s.find(k) == s.end()){
                s.insert(k);
//                cout << k << " ";
            }
        }
//        cout << endl;

//        printf("%d %d\n",x,s.size());
        printf("%d\n",s.size());
    }
    return 0;
}