#include "bits/stdc++.h"
using namespace std;
double a1[40], a2[40];
int n,T;
int main (){
    cin >> T;
    for(int s = 1;s <= T;s++) {
        cin >> n;
        double tot = 0;
        for (int i = 0; i < n; i ++ ) {
            cin >> a2[i];
            tot += a2[i];
        }
        for (int i = 0; i < n; i ++ )
            cin >> a1[i];
        double re = 0;
        for (int i = 0; i < n; i ++ ) {
            double x = 0;
            if (a1[i] >= 60)
                x = (a1[i] - 50) / 10;
            re += x * a2[i];
        }
        printf ("%.2lf\n", re / tot);
    }
    return 0;
}