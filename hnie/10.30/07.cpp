#include "bits/stdc++.h"
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((l + r) >> 1)
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
#define N 1000006
int sum[N << 2];
int a[N],n,q;
//pair<int,int> ;
struct node{
    int i,first,second,ans;
}b[N];
void modify(int o,int l,int r,int pos){
    if(l == r){
        sum[o] = 1;
    }else{
        if(pos <= mid)
            modify(ls,l,mid,pos);
        else
            modify(rs,mid + 1,r,pos);
        sum[o] = sum[ls] + sum[rs];
    }
}
int query(int o,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
        return sum[o];
    }
    int tot = 0;
    if(ql <= mid)
        tot += query(ls,l,mid,ql,qr);
    if(mid < qr)
        tot += query(rs,mid + 1,r,ql,qr);
    return tot;
}

int find(int p,int k){
    int l = p,r = n + 1;
    while(l < r){
        if(query(1,1,n,p,mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l == n + 1 ? -1 : l;
}
int query(int o,int l,int r,int k){
    if(l == r)
        return l;
    if(sum[ls] >= k)
        return query(ls,l,mid,k);
    else
        return query(rs,mid,r,k - sum[ls]);
}
bool cmp1(node n1,node n2){
    return n1.first < n2.first;
}
bool cmp2(node n1,node n2){
    return n1.i < n2.i;
}
int main() {
//    freopen("D:/CLionProjects/acm/hnie/10.30/1.in","r",stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= q;i++){
        cin >> b[i].first >> b[i].second;
        b[i].i = i;
    }
    sort(b + 1,b + q + 1,cmp1);
    int j = q;
    modify(1,1,n + 1,n + 1);
    for(int i = n;i >= 1;i--){
        while(j >= 1 && b[j].first == i){
            b[j].ans = query(a[i],b[j].second);
            j--;
        }
        modify(1,1,n,a[i]);
    }
    sort(b + 1,b + q + 1,cmp2);
    for(int i = 1;i <= q;i++){
        cout << b[i].ans << endl;
    }
    return 0;
}