#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int get(int x,int v){
    if(x <= 9)
        return v * 10 + x;
    else
        return get(x / 10,v * 10 + x % 10);
}

bool is_ab(int x){
    return get(x,0) == x && (x % 10 == x / 100 % 10) && (x / 10 % 10 == x / 1000 % 10);
}

int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    int n;
    cin >> n;
    int ans1 = 0,ans2 = 0;
    int yy = n / 10000;
    int mm = n / 100 % 100;
    int dd = n % 100;
    for(int i = yy;i < 10000;i++){
        for(int j = (i == yy ? mm : 1);j <= 12;j++){
            for(int k = ((j == mm && yy == i) ? dd + 1 : 1);k <= m[j];k++){
                int x = i * 10000 + j * 100 + k;
//                cout << x << endl;
                if(ans1 == 0 && x == get(x,0))
                    ans1 = x;
                if(ans2 == 0 && is_ab(x))
                    ans2 = x;
                if(ans1 && ans2){
                    cout << ans1 << endl << ans2;
                    return 0;
                }
            }
        }
    }
}