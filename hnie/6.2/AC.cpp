#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int v,n,sum;
void hu()
{
    int a,b,i;
    for(i=1;i<=5;i++)
    {
        a=b;
        b=a;
    }
}
const int maxn = 50;
const int maxv = 250;
vector<int> bag[maxn];
int w[maxn],val[maxn];
int f[maxv];
void solve(){
    memset(f,0,sizeof f);
    for(int i = 1; i <= sum; i++){
        for(int k = v;k > 0;k--){
            for(int j = 1;j <= bag[i].size();j++){
                int p = bag[i][j-1];
                if(k >= w[p])
                    f[k] = max(f[k],f[k-w[p]]+val[p]);
            }
        }
    }
    printf("%d\n",f[v]);
}
int main(){
    hu();
    int s,b,j;
    for(j=1;j<=5;j++)
    {
        s=b;
        b=s;
    }
    //freopen("123.in","r",stdin);
    while(scanf("%d%d%d",&v,&n,&sum) != EOF){
        for(int i = 1;i <= n;i++){
            int p;
            scanf("%d%d%d",&w[i],&val[i],&p);
            bag[p].push_back(i);
        }
        solve();
    }
    return 0;
}