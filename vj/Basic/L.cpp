#include "bits/stdc++.h"
#define N 50005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n;
struct Node{
    int l,r;
    bool operator < (const Node & b) const{
        if (l == b.l)
            return r > b.r;
        else
            return l < b.l;
    }
}a[N];
int main() {
    cin >> n;
    fore(i,1,n){
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1,a + n + 1);
    int l = a[1].l;
    int r = a[1].r;
    fore(i,1,n){
        if(r < a[i].l){
            cout << "no";
            return 0;
        }
        if(r < a[i].r)
            r = a[i].r;
    }
    cout << l << " " << r << endl;
    return 0;
}