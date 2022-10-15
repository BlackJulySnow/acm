#include <bits/stdc++.h>

using namespace std;
string s[10];
int main(){
//     freopen("D:/CLionProjects/acm/cf/827.div4/data.txt","r",stdin);
    int t;
    cin >> t;
    while (t--){
        char ans = '\0';
        for(int i = 0;i < 8;i++){
            cin >> s[i];
//            cout << s[i] << endl;
            if(s[i][0] == '.')
                continue;
            bool flag = true;
            for(int j = 1;j < 8;j++){
                if(s[i][0] != s[i][j])
                    flag = false;
            }
            if(flag)
                ans = s[i][0];
        }
        for(int i = 0;i < 8;i++){
            if(s[0][i] == '.')
                continue;
            bool flag = true;
            for(int j = 1;j < 8;j++){
                if(s[0][i] != s[j][i])
                    flag = false;
            }
            if(flag)
                ans = s[0][i];
        }
        if(ans == '\0'){

        }
        cout << ans << endl;
    }
    
    
    return 0;
}
