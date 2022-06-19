//
// Created by 刘晴瑞 on 2020/12/20.
//

#include "bits/stdc++.h"

using namespace std;

int maiin() {
//    freopen("data.out","w",stdout);
    string file[1005] = {""};
    string s1,s2,s3;
    int n;
    cin >> n;
    int tot = 0;
    for(int j = 1;j <= n;j++){
        cin >> s1;
        if (s1 == "ls"){
            for(int i = 1;i <= tot;i++)
                if (file[i] != "")
                    cout << file[i] << endl;
            continue;
        }
        cin >> s2;
        if (s1 == "rename") {
            cin >> s3;
            bool state = true;
            for(int i = 1;i <= tot;i++){
                if (file[i] == s3){
                    state = false;
                }
            }
            if(state){
                for(int i = 1;i <= tot;i++){
                    if (file[i] == s2){
                        file[i] = s3;
                    }
                }
            }
        }else if (s1 == "touch"){
            bool state = true;
            for(int i = 1;i <= tot;i++){
                if (file[i] == s2)
                    state = false;
            }
            if (state)
                file[++tot] = s2;
        }else if (s1 == "rm"){
            for(int i = 1;i <= tot;i++)
                if (file[i] == s2)
                    file[i] = "";
        }
    }
    return 0;
}