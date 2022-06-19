#include "bits/stdc++.h"
#define N 200005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,t,a[N],b[N];
int main() {
    cin >> t;
    while(t--){
        cin >> n;
        fore(i,1,n){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a + 1,a + n + 1);
        int l = 1,r = n;
        while(l <= n && a[l] == b[l])
            l++;
        while(r >= l && a[r] == b[r])
            r--;
        int flag = 1;
        fore(i,l,r){
            printf("%d %d\n",a[i],a[i - 1]);
            if(a[i] + a[i - 1] % 2 == 0)
                flag = false;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}