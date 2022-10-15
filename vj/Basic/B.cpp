#include "bits/stdc++.h"
#define N 40000
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int a[N],n,k;
int main() {
    cin >> n >> k;
    fore(i,1,n){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int last = unique(a + 1,a + n + 1) - a;
    if(k >= last)
        cout << "NO RESULT";
    else
        cout << a[k];
    return 0;
}