#include "iostream"
#include "map"
#include "algorithm"
#define N 10005
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int n,a,b,c,x,y,h[N],tot[N];
map<int,map<int,int>> m;
int main() {
    cin >> n >> a >> b >> c;
    fore(i,1,c){
        cin >> x >> y;
        if (x == y)
            continue;
        if(x > y)
            swap(x,y);
        if(m[x].count(y) != 0){
            continue;
        }
        m[x][y] = 1;
        tot[x + 1]--;
        tot[y]++;
    }
    fore(i,1,n){
        tot[i] += tot[i - 1];
        cout << b + tot[i] << endl;
    }
    return 0;
}