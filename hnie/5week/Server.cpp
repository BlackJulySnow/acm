#include<bits/stdc++.h>
#define type "Content-Type"
#define length "Content-Length"
#define boundary = "--123456789000000000000987654321"

using namespace std;
void out(int k){
    if(k <= 9)
        putchar('0' + k);
    else{
        out(k / 10);
        putchar(k % 10 + '0');
    }
}
inline int read(){
    char c = getchar();
    int res = 0;
    while(c < '0' || '9' < c)
        c = getchar();
    while ('0' <= c && c <='9'){
        res = 10 * res + c - '0';
        c = getchar();
    }
    return res;
}
int main(){
    cout << strcmp(type,length);
//    freopen("data.out","w",stdout);
    int n = read();
    int a[10];
    for(int i = 0;i < n;i++)
        a[i] = i + 1;
    do{
        for(int i = 0;i < n;i++){
            out(a[i]);
            putchar(' ');
        }
        puts("");
    }while(next_permutation(a,a + n));
    return 0;
}