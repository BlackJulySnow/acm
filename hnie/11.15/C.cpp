#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main(){
    int MIN=1e9;
    int ans;
    fore(i,1,100){
        int tmp;
        if(100%i==0)
            tmp= 100 / i + i;
        else
            tmp= 100 / i + i + 1;
        if(tmp < MIN){
            MIN=tmp;
            ans=i;
        }
    }
    cout << ans << endl;
}