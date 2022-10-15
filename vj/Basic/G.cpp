#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
string s;
int main() {
    cin >> s;
    int tot = 1;
    for(int i = 0;i < s.length() - 1;i++){
        if(s[i] != '9'){
            tot = 0;
            break;
        }
    }
    if (tot)
        cout << s;
    else{
        for(int i = 1;i < s.length();i++)
            cout << '9';
    }
    return 0;
}