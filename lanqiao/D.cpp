#include "bits/stdc++.h"
#define N 1000005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define ll long long
int Next[N];
char s[N];
int main() {
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    int num = 1, index = 2;
    ll ans = 0;

    Next[1] = 0;
    for(int i = 2,j = 0;i <= n;i++){
        while (j > 0 && s[i] != s[j + 1])
            j = Next[j];
        if (s[i] == s[j + 1]){
            j++;
//            ans++;
        }
        Next[i] = j;
    }
    for(int i = 2;i <= n;i ++){
        if(Next[i] > 0){
            ans += i - Next[i] + 1;
        }
    }
    cout << ans << endl;
    return 0;
}