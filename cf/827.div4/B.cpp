#include <bits/stdc++.h>

using namespace std;
int a[105];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        bool flag = true;
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        sort(a,a + n + 1);
        for(int i = 2;i <= n;i++){
            if(a[i] <= a[i - 1])
                flag = false;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
