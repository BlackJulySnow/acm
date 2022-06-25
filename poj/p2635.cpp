#include "bits/stdc++.h"
#define N 1000005
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int prm[N],vec[N],tot;
void get(int n){
    for(int i = 2;i <= n;i++){
        if(vec[i] == 0){
            vec[i] = i;
            prm[++tot] = i;
        }
        for(int j = 1;j <= tot;j++){
            if(prm[j] > vec[i] || prm[j] > n / i)
                break;
            vec[i * prm[j]] = prm[j];
        }
    }
}
int main() {
    get(1000000);
    ll l;
    string str;
    while(cin >> str >> l){
        
    }
    return 0;
}