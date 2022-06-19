
#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    string line;
    getline(cin, line);
    string res = "";
    for(char c : line){
        if(c != ' ')
            res = res + c;
    }
    cout << res;
    return 0;
}