#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int a[3];
bool contain(int x){
    bool flag = false;
    while(x){
        if(x % 10 == 2 || x % 10 == 4)
            flag = true;
        x /= 10;
    }
    return flag;
}
vector<pair<int,pair<int,int>>> v;

int main() {
//    cout << contain(524) << endl;
    long long ans = 0;
    int n = 2019;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < i && i + j <= 2019;j++){
            for(int k = 1;k < j && i + j + k <= 2019;k++){
                if(i + j + k == n && !contain(i) && !contain(j) && !contain(k)){
//                    a[0] = i;
                    ans++;
//                    a[1] = j;
//                    a[2] = k;
//                    sort(a,a + 3);
//                    printf("%d %d %d\n",a[0],a[1],a[2]);
//                    v.push_back(make_pair(a[0], make_pair(a[1],a[2])));
                }
            }
        }
    }
//    sort(v.begin(),v.end());
//    unique(v.begin(),v.end());
    cout << ans;
    return 0;
}