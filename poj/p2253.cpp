#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#define N 205
using namespace std;
int n;
vector<pair<int,int> > e;
double G[N][N];
double dist(int x1,int y1,int x2,int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

queue<int> q;
int v[N];
double d[N];
void spfa(){
    while (!q.empty())
        q.pop();
    memset(v,0,sizeof(v));
    for(int i = 1;i <= n;i++)
        d[i] = 50000000;
    d[1] = 0,v[1] = true;
    q.push(1);
    while (q.size()){
        int x = q.front();q.pop();
        v[x] = false;
        for(int y = 1;y <= n;y++){
            if(y != x && d[y] > max(G[x][y],d[x])){
                d[y] = max(G[x][y],d[x]);
                if(!v[y])
                    q.push(y), v[y] = true;
            }
        }
    }
}

int main(){
    int cnt = 1;
    while(scanf("%d",&n) && n){
        e.clear();
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                G[i][j] = 100000000;
        for(int i = 1;i <= n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            e.push_back(make_pair(x,y));
            for(int j = 1;j <= i;j++){
                G[i][j] = G[j][i] = dist(x,y,e[j - 1].first,e[j - 1].second);
            }
        }
        spfa();
        printf("Scenario #%d\n",cnt++);
        printf("Frog Distance = %.3lf\n\n",d[2]);
    }
    return 0;
}