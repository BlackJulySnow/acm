#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3f3f3f3f
#define MAXV 110
#define min(a, b) a<b?a:b

typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
} MatGraph;

typedef struct {
    int e[MAXV], ne[MAXV], w[MAXV], h[MAXV], idx;
    int n;
} Adj;
int path[MAXV];

void CreatMat(MatGraph *&g, int mp[][MAXV], int n, int e) {
    g = (MatGraph *) malloc(sizeof(MatGraph));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g->edges[i][j] = mp[i][j];
    g->e = e;
    g->n = n;
}

void add(int a, int b, int c, Adj *p) {
    p->e[p->idx] = b;
    p->w[p->idx] = c;
    p->ne[p->idx] = p->h[a];
    p->h[a] = p->idx++;
}

void CreatAdj(MatGraph *g, Adj *&p) {
    p = (Adj *) malloc(sizeof(Adj));
    for (int i = 0; i < g->n; i++)
        for (int j = 0; j < g->n; j++)
            if (g->edges[i][j] != 0 && g->edges[i][j] != INF)
                add(i, j, g->edges[i][j], p);
    p->n = g->n;
}

int dijkstra(MatGraph *g) {
    int d[MAXV];
    bool st[MAXV];
    memset(d, 0x3f, sizeof d);
    memset(st, 0, sizeof st);
    d[1] = 0;

    for (int i = 0; i < g->n; i++) {
        int t = -1;
        for (int j = 0; j < g->n; j++)
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
        st[t] = true;

        for (int j = 0; j < g->n; j++) {
            if (d[j] > d[t] + g->edges[t][j]) path[j] = t;
            d[j] = min(d[j], d[t] + g->edges[t][j]);
        }
    }

    for (int i = 0; i < g->n; i++)
        printf("到点%d的最短路径长度为：%d\n", i, d[i]);
    printf("\n");
}

void disp(int x) {
    if (x == 1) {
        printf("1");
        return;
    }
    disp(path[x]);
    printf("->%d", x);
}

void Path(MatGraph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("到点%d的最短路径为：", i);
        disp(i);
        printf("\n");
    }
}

int main() {
    int mp[MAXV][MAXV] = {
            {INF, 1,   INF, INF, 3,   INF},
            {INF, INF, 5,   INF, INF, INF},
            {8,   INF, INF, 9,   INF, INF},
            {3,   INF, INF, INF, INF, 2},
            {INF, INF, 6,   7,   INF, INF},
            {INF, INF, INF, INF, 1,   INF}
    };
    MatGraph *g;
    Adj *p;
    int n = 6, e = 10;
    CreatMat(g, mp, n, e);
    CreatAdj(g, p);
    dijkstra(g);
    Path(g);
    return 0;
}
