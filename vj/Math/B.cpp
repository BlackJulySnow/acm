//
// Created by B1GGersnow on 2022/10/12.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000][1000],p[100],k;
int v[1000][1000];

int main(){
    a[0][0] = 1;
    p[0] = 1;
    for(int i =1;i <= 13;i++){
        p[i] = p[i - 1] * i;
    }
    for(int i = 1;i <= 500;i++){
        for(int j = 0;j <= i;j++){
            if(j >= 1) {
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                if(a[i][j] >= 1e9 || v[i - 1][j] || v[i - 1][j - 1])
                    v[i][j] = 1;
            }else
                a[i][j] = 1;
        }
    }
    vector<pair<int,int>> vec;
    int round = 0;
    while(cin >> k){
        round++;
        if(k == 1){
            printf("Case %d: Impossible\n",round);
            continue;
        }

        for(int i = 1;i <= 13;i++){
            if(k % p[i] == 0){
                for(int j = 1;i + j <= 500;j++){
                    if(!v[i + j][j] && k / p[i] == a[i + j][j]){
                        vec.emplace_back(i + j,j);
                    }
                }
            }
        }
        if(vec.empty()){
            printf("Case %d: %lld %lld\n",round,k,k-1);
            continue;
        }
        sort(vec.begin(),vec.end());
        vec.clear();
        printf("Case %d: %d %d\n",round,vec.front().first,vec.front().second);
    }
    return 0;
}