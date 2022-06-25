#include "bits/stdc++.h"
#define N 2005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,k,x;
pair<int,int> p[N];
vector<int> a2;
int main() {
    cin >> n >> k;

    int m = 0;
    fore(i,1,n){
        cin >> x;
        p[i] = {x,i};
        m = max(x,m);
    }
    if(k == 1){
        cout << m << endl << n;
        return 0;
    }
    sort(p + 1,p + n + 1);
    int ans = 0;
    for(int i = n - k + 1;i <= n;i++){
        a2.push_back(p[i].second);
//        cout << p[i].second << endl;
        ans += p[i].first;
    }
    sort(a2.begin(), a2.end());
    cout << ans << endl;
    cout << a2[0] << " ";
    for(int i = 1; i < a2.size() - 1; i++)
        cout << a2[i] - a2[i - 1] << " ";
    cout << n - a2[a2.size() - 2];
    return 0;
}