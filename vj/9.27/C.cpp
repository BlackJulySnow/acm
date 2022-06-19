#include "bits/stdc++.h"
using namespace std;
#define ll long long
int d[50][50];
int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a % b);
}
int main() {
//    d[0][0] = 1;
//    for(int i = 1;i <= 40;i++){
//        for(int j = 1;j <= 40;j++){
//            d[i + 1][j + 2] |= d[i][j];
//            d[i + 2][j + 1] |= d[i][j];
//        }
//    }
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n,a,b,x;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a >> b;
        ll s = a * b;
        x=pow(s,1.0/3)+0.5;
        if(x*x*x!=s || a%x!=0 || b%x!=0)
            printf("No\n");
        else
            printf("Yes\n");
    }
//        bool flag = true;
//        cin >> a >> b;
//        for(int j = 2;a != 1 && b != 1;j++){
//            int k1 = 0,k2 = 0;
//            while (a % j == 0){
//                k1++;
//                a /= j;
//            }
//            while (b % j == 0){
//                k2++;
//                b /= j;
//            }
//            if(!d[k1][k2] || j >= 31623) {
//                flag = false;
//                break;
//            }
//        }
//        if(flag)
//            cout << "Yes" << endl;
//        else
//            cout << "No" << endl;
//    }
    return 0;
}