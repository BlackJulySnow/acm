#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
double a[100][2];
double person[100][5];
int main() {
    fore(i,1,80){
        cin >> a[i][0] >> a[i][1];
    }
    fore(i,1,5){
        fore(j,0,3){
            double tot = 0;
            fore(k,0,3){
                tot += a[i + j * 20 + k * 5][0] * a[i + j * 20 + k * 5][1];
//                cout << a[i + j * 20 + k * 5][0] << " " << a[i + j * 20 + k * 5][1] << endl;
            }
            person[i][j] = tot;
//            cout << tot << endl;
        }
//        break;
    }
    printf("[");
    for (int i = 1; i <= 5; ++i) {
        printf("[%lf,%lf,%lf,%lf],\n",person[i][0],person[i][1],person[i][2],person[i][3]);
    }
    printf("]");
    return 0;
}