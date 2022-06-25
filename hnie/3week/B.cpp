#include "bits/stdc++.h"
#define N 10005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n;
int main() {
    cin >> n;
    int a1 = 0,a2 = 0;
    int b1 = 0,b2 = 0;
    int t1,t2;
    fore(i,1,n){
        cin >> t1 >> t2;
        if(t1)
            a2++;
        else
            a1++;
        if(t2)
            b2++;
        else
            b1++;
    }
    cout << min(a1,a2) + min(b1,b2);
    return 0;
}