#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
double a[50][5];
int main() {
    for(int i = 1;i <= 80;i++){
        cin >> a[i][1] >> a[i][2];
    }
    printf("[");
    for(int i = 1;i <= 5;i++){
        printf("[");
        for(int j = 0;j < 4;j++){
            printf("[");
            for(int k = 0;k < 4;k++){
                printf("%lf,",a[k * 5 + j * 20 + i][2]);
            }
            printf("],\n");
        }
        printf("],\n");
    }
    printf("]");
    return 0;
}