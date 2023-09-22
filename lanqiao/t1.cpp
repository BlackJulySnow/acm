#include "bits/stdc++.h"
#define ll long long
using namespace std;
#define N 100005
char ans[N],s[N];
int n,m;
void calc(int r){
    for(int i = 1;i <= r;i++){
        if(i + r <= m)
            ans[i + r] = (ans[i] - 'a' - 1 + 26) % 26 + 'a';
    }
}
int main() {
    cin >> n >> m;
    scanf("%s",s + 1);
    for(int i = n;i > n/ 2;i--){
        ans[n - i + 1] = (s[i] - 'a' + 16 ) % 26 + 'a';
    }
    int k = n / 2;
    while (k <= m){
        calc(k);
        k *= 2;
    }
    for(int i = m;i >= 1;i--){
        printf("%c",ans[i]);
    }
    return 0;
}