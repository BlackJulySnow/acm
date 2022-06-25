#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define ll long long
char s[100005];

int tot[30];
int d[30][100005];

ll calc(int x){
    ll ans = (long long) x * (x + 1) / 2;
    return ans;
}

int main() {
    cin >> s + 1;
    int n = strlen(s + 1);
    for(int i = 1;i <= strlen(s + 1);i++){
        d[s[i] - 'a' + 1][++tot[s[i] - 'a' + 1]] = i;
    }
    long long ans = 0;
    for(int i = 1;i <= 26;i++){
        d[i][0] = 0;
        d[i][tot[i] + 1] = n + 1;
        ll tmp = calc(n);
        for(int j = 1;j <= tot[i] + 1;j++){
            tmp -= calc(d[i][j] - d[i][j - 1] - 1);
        }
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}