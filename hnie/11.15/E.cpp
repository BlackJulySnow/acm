#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define MOD 2020
int d[3][1011][2021];
int main() {
//    fore(i,1,2020)
//        d[1][1][i] = 1;
//    fore(i,2,1010)
//        fore(j,1,2020)
//            fore(dep,1,j - 1)
//                d[1][i][j] = (d[1][i][j] + d[1][i - 1][dep]) % MOD;
//    fore(i,1,1010)
//        fore(j,1,2020)
//            fore(dep,1,j - 1)
//                fore(o,1,j - 1){
//                    if(dep != o){
//                        d[2][i][j] = (d[1][i][dep] + d[2][i - 1][o]) % MOD;
//                    }
//    }
//    int ans = 0;
//    fore(i,1,2020){
//        ans += d[2][1010][i];
//    }
    int ans = 1;
    for(int i = 1;i <= 2020;i++){
        ans = ans * 2 % MOD;
    }
    cout << ans % MOD;
    return 0;
}