#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,m;
void dfs(int k,int last){
    for(int i = 0;i < (1 << m);i++){

    }
}

int main() {
    cin >> n >> m;
    for(int i = 0;i < (1 << m);i++){
        for(int j = 0;j < m - 1;j++){
            if(!(((i & (1 << j)) ^ (i & (1 << (j + 1)))) && ((i & (1 << j)) ^ (i & (1 << (j - 1)))))){

            }
        }
    }
    return 0;
}