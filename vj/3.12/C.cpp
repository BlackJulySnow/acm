#include "bits/stdc++.h"
#define N 1005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int t,n,a[N],b[N];
#define PI pair<int,int>

void get() {
    int flag = 1;
    vector<PI> vec;
    fore(i,1,n) {
        if(a[i] == b[i]) {
            continue;
        }
        int tmp=-1;
        fore(j,i + 1,n) {
            if(a[j]==b[i]) {
                tmp=j;
            }
        }
        for(int j=tmp; j >= i + 1; j--) {
            vec.push_back({j - 1, j});
            swap(a[j-1],a[j]);
        }
        if(tmp == -1) {
            flag=0;
            break;
        }
    }

    if(flag){
        cout << "YES" << endl;
        for(PI x:vec)
            cout << x.first << " " << x.second << endl;
        cout << "0 0" << endl;
    }else {
        cout << "NO" << endl;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        fore(i,1,n)
            cin >> a[i];
        fore(i,1,n)
            cin >> b[i];
        get();
    }
    return 0;
}