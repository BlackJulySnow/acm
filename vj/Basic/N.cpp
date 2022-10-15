#include "algorithm"
#include "iostream"
#define N 505
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int c,n,a[N][N],sum[N][N],x[N],y[N],idx1[N],idx2[N],k1,k2;
int getSum(int x1,int y1,int x2,int y2){
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int findX(int * a,int l,int r,int x){
    while (l < r){
        int mid = (l + r + 1) / 2;
        if(a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
bool check(int len){
//    cout << len << endl;
    fore(i,1,k1 - 1){
        fore(j,1,k2 - 1){
            int k3 = findX(idx1,i,k1,idx1[i] + len - 1);
            int k4 = findX(idx2,j,k2,idx2[j] + len - 1);
            k3 = min(k3,k1 - 1);
            k4 = min(k4,k2 - 1);
            if(getSum(i,j,k3,k4) >= c) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> c >> n;
    fore(i,1,n){
        cin >> x[i] >> y[i];
        idx1[i] = x[i];
        idx2[i] = y[i];
    }
    sort(idx1 + 1,idx1 + n + 1);
    sort(idx2 + 1,idx2 + n + 1);
    k1 = unique(idx1 + 1,idx1 + n + 1) - idx1;
    k2 = unique(idx2 + 1,idx2 + n + 1) - idx2;
//    cout << k1 << " " << k2 << endl;
    fore(i,1,n){
        int xi = lower_bound(idx1 + 1,idx1 + k1,x[i]) - idx1;
        int yi = lower_bound(idx2 + 1,idx2 + k2,y[i]) - idx2;
        a[xi][yi]++;
    }
    int l = 1;
    int r = max(idx1[k1 - 1] - idx1[1] + 2,idx2[k2 - 1] - idx2[1] + 2);
    fore(i,1,k1 - 1){
        fore(j,1,k2 - 1){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    while (l < r){
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}