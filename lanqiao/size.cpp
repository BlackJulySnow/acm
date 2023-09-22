#include "bits/stdc++.h"

using namespace std;
int a[100] = {0,1,2,3,4,5,10,7,8,9,6};
stack<int> s;

int main() {
    int n = 10;
    for(int i = 1;i <= n;i++){
        int maxv = a[i];
        while (!s.empty() && s.top() > a[i]){
            maxv = max(maxv, s.top());
            s.pop();
        }
        s.push(maxv);
    }
    cout << s.size() << endl;
}