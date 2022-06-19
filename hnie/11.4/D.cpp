#include "bits/stdc++.h"
#define N 1005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n;
int a[N],b[N];
double esp = 1e-5;
vector<pair<double,double>> v;
int main() {
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    long long ans = 2;
    fore(i,2,n){
        cin >> a[i] >> b[i];
        bool flag = true;
        v.clear();
        fore(j,1,i - 1){
            if(a[i] == a[j] && b[i] == b[j]) {
                flag = false;
                break;
            }
            if(a[i] == a[j])
                continue;
            double tx =  -(b[i] - b[j]) / (a[i] - a[j]);
            double ty = a[i] * tx + b[i];
            v.push_back(make_pair(tx,ty));
        }
        if(flag){
            sort(v.begin(),v.end());
            int cnt = 1;
            for(int j = 1;j < v.size();j++){
                if()
            }
        }
    }
    return 0;
}