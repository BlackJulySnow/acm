#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
char str[1000];
int main() {
    scanf("%s",str);
    sort(str, str + strlen(str),greater<int>());
    printf("Max:%s\n",str);
    sort(str, str + strlen(str));
    if(str[0] == '0'){
        for(int i = 1;i < strlen(str);i++)
            if(str[i] != '0') {
                swap(str[i], str[0]);
                break;
            }
    }
    printf("Min:%s\n",str);
    return 0;
}