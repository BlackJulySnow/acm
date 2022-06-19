#include<bits/stdc++.h>

using namespace std;
int n;
int get(int x){
    return max(x - 1,n - x);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cout << get(i) * 2 << endl;
    }

    return 0;
}