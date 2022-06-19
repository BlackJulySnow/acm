#include "bits/stdc++.h"
#define N 1005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int Next[N],d[N],tot,ans[N];
int main() {
    char s[] = " abcaabcbcaabcbdcbaabcbcadcba";
    char t[] = " abcbca";
    int n = strlen(t + 1);
    int m = strlen(s + 1);
    for(int i = 2,j = 0;i <= n;i++){
        while(j > 0 && t[i] != t[j + 1])
            j = Next[j];
        if(t[i] == t[j + 1])
            j++;
        Next[i] = j;
    }

    for(int i = 1,j = 0;i <= m;i++){
        while(j > 0 && (j == n || s[i] != t[j + 1]))
            j = Next[j];
        if(s[i] == t[j + 1])
            j++;
        d[i] = j;
        if(d[i] == n)
            ans[++tot] = i - n + 1;
    }
    cout << "出现了" << tot << "次" << (t + 1) << endl;
    fore(i,1,tot){
        cout << ans[i] << endl;
    }
    return 0;
}