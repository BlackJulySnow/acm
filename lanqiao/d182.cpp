//
// Created by B1GGersnow on 2023/4/5.
//
#include "bits/stdc++.h"
using namespace std;

const int N = 1010;
const int P = 1e7 + 10;
long double A[N], B[N];

set<pair<long double,long double> > t;
int n;
long double ans = 1;

void pan()
{
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[i] == A[j]) continue;
            long double a = (B[j] - B[i]) / (A[i] - A[j]);
            long double b = a * A[j] + B[j];
            if(t.find(make_pair(a,b)) == t.end()){
                s++;
                t.insert(make_pair(a,b));
            }
        }
        t.clear();
        ans += 1 + s;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i];
    if (n == 0)
        cout << ans << endl;
    else
    {
        pan();
        cout << ans << endl;
    }
    return 0;
}