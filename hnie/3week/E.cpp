#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,x;
int main() {
    cin >> n;
    fore(i,1,n){
        cin >> x;
        cout << (x & 1 ? x : x - 1) << " ";
    }
    return 0;
}