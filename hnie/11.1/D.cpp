#include "bits/stdc++.h"

int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int ans = 0;
    int week = 6;
    fore(year,2000,2020){
        fore(j,1,12){
            int mou = m[j] + ((year % 4 == 0) && (j == 2) ? 1 : 0);
            fore(day,1,mou){
                ans++;
                if(week == 1 || day == 1)
                    ans++;
                week++;
                if(week > 7)
                    week -= 7;
                if(year == 2020 && j == 10 && day == 1)//如果到了2020年10月1日
                    cout << ans;
            }
        }
    }
    return 0;
}