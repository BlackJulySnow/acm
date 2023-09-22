#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
struct Node{
    int v;
    char s;
    int a,b,c;
    char d,e,f;
    bool operator < (const Node other)const{
        return v > other.v;
    }
};
std::priority_queue<Node> pq;
using namespace std;

int main() {
    int n,v;
    cin >> n;
    char c = '\0';
    for(int i = 1;i <= n;i++){

        cin >> c >> v;
        pq.push({v,c});

    }
    while (pq.size() != 1){
        Node first = pq.top();pq.pop();
        Node second = pq.top();pq.pop();
        Node third = pq.top();pq.pop();
    }
    return 0;
}