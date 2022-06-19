#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

#define N 1005
vector<int> a[N];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    fore(i,1,n){
        int oper;
        scanf("%d",&oper);
        if(oper == 1){
            int p,x,y;
            scanf("%d",&p);
            while (p--){
                scanf("%d%d",&x,&y);
                a[x].push_back(y);
            }
        }else{
            int x,y1,y2;
            scanf("%d%d%d",&x,&y1,&y2);
            int ans = 0;
            fore(j,0,a[x].size() - 1){
                if(y1 <= a[x][j] && a[x][j] <= y2)
                    ans++;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}