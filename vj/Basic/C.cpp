#include<cstdio>

long long a[500005],tmp[500005],cnt;

void merge(int l,int r){
    if(r - l <= 1)return;
    int mid = (l+r)>>1;
    merge(l,mid);
    merge(mid,r);
    int t = l;
    int p = l;
    int q = mid;
    while(p < mid || q < r){
        if(q >= r || (p < mid && a[p] <= a[q])){
            tmp[t++] = a[p++];
        }else{
            tmp[t++] = a[q++];
            cnt += mid - p;
        }
    }
    for(int i = l;i < r;i++)a[i] = tmp[i];
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)scanf("%lld",a+i);
    merge(0,n);
    printf("%lld",cnt);
    return 0;
}