#include "bits/stdc++.h"
using  namespace  std;

int main() {
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(b < 16){
            a -= 10;
        }else if(b > 20){
            a -= b - 20;
        }
        printf("%d\n",(a < 0 ? 0 : a));
    }
    return 0;
}