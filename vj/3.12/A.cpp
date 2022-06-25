#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
string s;
int main() {
    cin >> s;
    string flag="chuanzhi";
    int position=0;
    int i=1;
    while((position=s.find(flag,position))!=string::npos)
    {
//        cout<<"position  "<<i<<" : "<<position<<endl;
        position++;
        i++;
    }
    cout << i - 1 << endl;
//    string t = "chuanzhi";
//    int tot = 0;
//    for(int i = 0;i < s.length();i++){
//        bool state = true;
//        for(int j = 0;j < t.length();j++){
//            if(i + j >= s.length() && s[i + j] != t[j]){
//                cout << j << endl;
//                state = false;
//                break;
//            }
//        }
//        if(state){
//            tot++;
//
//        }
//
//    }
//    cout << tot;
    return 0;
}