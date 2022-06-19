#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int a[1005];
int main() {
    int n;
    int MAX = 0;
    int MIN = 1e9;
    cin >> n;
    fore(i,1,n){
        cin >> a[i];
        MAX = max(MAX,a[i]);
        MIN = min(MIN,a[i]);
    }
    fore(i,1,n){
        cout << int(((a[i] - MIN) * 100) / (MAX - MIN));
        if(i != n)
            cout << " ";
    }
    return 0;
}