#include "bits/stdc++.h"

using namespace std;
int n,x,maxN;
int main() {
    cin >> n;
    vector<int> a(n),vct,t(n);
    vct.push_back(0);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
        x = a[i];
        int k = upper_bound(vct.begin(),vct.end(),x,greater<int>()) - vct.begin();
//        cout << k << endl;
        if(vct.size() == k + 1)
            vct.push_back(0);
        while (vct[k] >= x) {
            k++;
            if(vct.size() + 1 == k)
                vct.push_back(0);
        }
        t[i] = k;
        vct[k] = x;
        maxN = max(maxN,k);
    }
//    cout
    vector<vector<int>> ans(maxN + 1);
    for(int i = 0;i < n;i++){
//        cout << a[i] << endl;
        ans[t[i]].push_back(a[i]);
    }
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}