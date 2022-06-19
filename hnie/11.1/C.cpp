#include "bits/stdc++.h"

using namespace std;

int main() {
    long long ans = 1;
    for(int i = 1;i <= 19;i++){
        ans += i * 4;
    }
    cout << ans << endl;
    return 0;
}