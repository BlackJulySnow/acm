#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int ans = 0,x;
    fore(i,1,7){
        cin >> x;
        ans += x;
    }
    if(ans > 0){
        cout << "IMissYou!" << endl << ans;
    }else{
        cout << "OvO";
    }
    return 0;
}