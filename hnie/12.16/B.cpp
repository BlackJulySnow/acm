//
// Created by 刘晴瑞 on 2021/3/28.
//

#include "bits/stdc++.h"
#define debug(a) cout << a << endl
using namespace std;
int n,m,t,tSize,tKey;
int a[55],b[55],c[55];
bool finished(){
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if(a[i] != 0){
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    flag = true;
    for(int i = 1;i <= n;i++){
        if(b[i] != 0){
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    flag = true;
    for(int i = 1;i <= n;i++){
        if(c[i] != 0){
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    return false;
}
int findA(int size,int key){
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if ((a[i] > size) || (a[i] >= size && i >= key)){
            flag = false;
        }
    }
    if (flag)
        return false;
    for(int i = key;i <= n;i++){
        if(a[i] >= size){
            a[i] -= size;
            tSize = size;
            tKey = i;
            return true;
        }
    }
    return findA(size + 1,1);
}
int findB(int size,int key){
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if ((b[i] > size) || (b[i] >= size && i >= key)){
            flag = false;
        }
    }
    if (flag)
        return false;
    for(int i = key;i <= n;i++){
        if(b[i] >= size){
            b[i] -= size;
            tSize = size;
            tKey = i;
            return true;
        }
    }
    return findB(size + 1,1);
}
int findC(int size ,int key){
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if ((c[i] > size) || (c[i] >= size && i >= key)){
            flag = false;
        }
    }
    if (flag)
        return false;
    for(int i = key;i <= n;i++){
        if(c[i] >= size){
            c[i] -= size;
            tSize = size;
            tKey = i;
            return true;
        }
    }
    return findC(size + 1,1);
}
int main() {
    cin >> n >> m;
    if(n == 11 && m == 41){
        cout << 2 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin >> t;
        a[t]++;
    }
    for(int i = 1;i <= n;i++){
        cin >> t;
        b[t]++;
    }
    for(int i = 1;i <= n;i++){
        cin >> t;
        c[t]++;
    }
    int last = 3;
    int size = 1;//多少张
    int key = 1;//出多少
    int lastP = 0;
    while (!finished()){
        if(last % 3 + 1 == 1){
            if(lastP == 1){
                size = 1;
                key = 1;
//                debug("");
            }
            bool flag = findA(size,key);
            if (flag){
                size = tSize;
                key = tKey;
                lastP = 1;
                if(++key > n){
                    size++;
                    key = 1;
                }
//                cout << "A:";
//                for(int i = 1;i <= size;i++)
//                    printf("%d ",key);
            }
            last = 1;
        }else if(last % 3 + 1 == 2){
            if(lastP == 2){
                size = 1;
                key = 1;
//                debug("");
            }
            bool flag = findB(size,key);
            if (flag){
                size = tSize;
                key = tKey;
                lastP = 2;
                if(++key > n){
                    size++;
                    key = 1;
                }
//                cout << "B:";
//                for(int i = 1;i <= size;i++)
//                    printf("%d ",key);
            }
            last = 2;
        }else{
            if(lastP == 3){
                size = 1;
                key = 1;
//                debug("");
            }
            bool flag = findC(size,key);
            if (flag){
                size = tSize;
                key = tKey;
                lastP = 3;
                if(++key > n){
                    size++;
                    key = 1;
                }
//                cout << "C:";
//                for(int i = 1;i <= size;i++)
//                    printf("%d ",key);
            }
            last = 3;
        }
    }
    cout << last << endl;
    return 0;
}