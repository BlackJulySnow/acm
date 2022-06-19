#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int t,s[4];
int main() {
    cin >> t;
    while(t--){
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        int a = max(s[0],s[1]);
        int b = max(s[2],s[3]);
        sort(s,s + 4);
        if(s[3] != max(a,b) || s[2] != min(a,b))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}