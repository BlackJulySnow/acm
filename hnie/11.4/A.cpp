#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int n,x;
    cin >> n;
    int tot = 0;
    int tot1 = 0;
    int tot2 = 0;
    fore(i,1,n){
        cin >> x;
        tot++;
        if(x >= 60)
            tot1++;
        if(x >= 85)
            tot2++;
    }
    int k1 = (int)((double)(tot1) / (tot) * 100);
    if((double)(tot1) / (tot) * 100 - k1 >= 0.5)
        k1++;
    int k2 = (int)((double)(tot2) / (tot) * 100);
    if((double)(tot2) / (tot) * 100 - k2 >= 0.5)
        k2++;
    cout << k1 << "%" << endl;
    cout << k2 << "%";
    return 0;
}