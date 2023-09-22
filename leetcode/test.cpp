//
// Created by B1GGersnow on 2023/9/22.
//

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> stk;
        for(char i : s){
            while(!stk.empty() && i <= stk.top())
                stk.pop();
            stk.push(i);
        }
        string res = "";
        while(!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};

int main(){
    string s = "cbacdcbc";
    Solution solution;
    cout << solution.smallestSubsequence(s);
}