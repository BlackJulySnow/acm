#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int cnt;

void quick_sort(int l, int r, int p[], int n) {
    if (l >= r)return;

    int x = p[l], i = l, j = r;
    while (i < j) {
        while (j > i && p[j] >= x) j--;
        p[i] = p[j];
        while (i < j && p[i] <= x) i++;
        p[j] = p[i];
    }
    p[i] = x;
    printf("第%d次划分，基准为：%d 结果：", ++cnt, x);
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");

    quick_sort(l, i - 1, p, n);
    quick_sort(i + 1, r, p, n);
}

void sift(int p[], int l, int h) {
    int i = l, j = i * 2;
    int t = p[i];
    while (j <= h) {
        if (j < h && p[j] < p[j + 1]) j++;
        if (t < p[j]) {
            p[i] = p[j];
            i = j;
            j = i * 2;
        } else break;
    }
    p[i] = t;
}

void Heap_sort(int p[], int n) {
    cnt = 0;
    for (int i = n / 2; i >= 1; i--)
        sift(p, i, n);
    for (int i = n; i >= 2; i--) {
        swap(p[1], p[i]);
        sift(p, 1, i - 1);
        printf("\n第%d趟：", ++cnt);
        for (int j = 1; j <= n; j++)
            printf("%d ", p[j]);
    }
}

int main() {
    int a[] = {6, 4, 2, 9, 5, 8, 7, 10, 1, 3, 12};
    int n = 11;
    quick_sort(0, n - 1, a, n);
    int b[] = {0, 6, 4, 2, 9, 5, 8, 7, 10, 1, 3, 12};
    Heap_sort(b, n);
    return 0;
}
