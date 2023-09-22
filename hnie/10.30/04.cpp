#include "bits/stdc++.h"
#define N 250005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
char s[N << 1];
int Next[N << 1];

int main() {
    scanf("%s",s + 1);
    Next[1] = 0;
    int n = strlen(s + 1);
    for(int i = 2,j = 0;i <= n;i++){
        while (j > 0 && s[i] != s[j + 1])
            j = Next[j];
        if(s[i] == s[j + 1])
            j++;
        Next[i] = j;
        cout << Next[i] << endl;
    }

    return 0;
}