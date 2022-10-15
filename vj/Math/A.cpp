//
// Created by B1GGersnow on 2022/10/13.
//

#include "bits/stdc++.h"
typedef long long ll;
const int MAXN = 1e9;
using namespace std;
int main()
{
    int k;
    int cnt = 0;
    while (~scanf("%d", &k))
    {
        int flag = 0;
        int i, j;
        printf("Case %d: ", ++cnt);
        for (i = 2; i <= ceil(sqrt(k)); i++)
        {
            int sum = 1;
            for (j = i; j >= 1; j--)
            {
                sum *= j;
                if (sum == k)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag){
            printf("%d %d\n", i, j - 1);
        }
        else{
            if (k == 1)
                printf("Impossible\n");
            else
                printf("%d %d\n", k, k - 1);
        }
    }
    return 0;
}