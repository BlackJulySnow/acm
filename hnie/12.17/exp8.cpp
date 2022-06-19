#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct node {
    KeyType key;
    struct node *l, *r;
} BSTNode;

void Insert(BSTNode *&bt, KeyType k) {
    if (bt == NULL) {
        bt = (BSTNode *) malloc(sizeof(BSTNode));
        bt->key = k;
        bt->l = bt->r = NULL;
    } else if (k == bt->key)
        return;
    else if (k < bt->key)
        return Insert(bt->l, k);
    else
        return Insert(bt->r, k);
}

BSTNode *CreateBST(KeyType a[], int n) {
    BSTNode *bt = NULL;
    for (int i = 0; i < n; i++)
        Insert(bt, a[i]);
    return bt;
}

void Disp(BSTNode *h) {
    if (h != NULL) {
        printf("%d", h->key);
        if (h->l != NULL || h->r != NULL) {
            printf("(");
            Disp(h->l);
            if (h->r != NULL) printf(",");
            Disp(h->r);
            printf(")");
        }
    }
}

void query(BSTNode *bt, int x) {
    if (bt->key == x) {
        printf("%d", x);
        return;
    }
    printf("%d->", bt->key);
    if (x < bt->key) query(bt->l, x);
    else if (x > bt->key) query(bt->r, x);
}

void Delete(BSTNode *&bt, int x) {
    if (bt != NULL) {
        if (bt->key == x) {
            BSTNode *L = bt->l, *R = bt->r;
            while (R->l != NULL) R = R->l;
            R->l = L;
            bt = bt->r;
            return;
        }
        if (bt->key > x) Delete(bt->l, x);
        else if (bt->key < x) Delete(bt->r, x);
    }
}

int main() {
    int a[] = {6, 4, 2, 9, 5, 8, 7, 10, 1, 3, 12};
    BSTNode *bt = CreateBST(a, 11);
    printf("输出bt二叉树：");
    Disp(bt);
    printf("\n查找路径：");
    query(bt, 10);
    printf("\n插入关键字11后：");
    Insert(bt, 11);
    Disp(bt);
    printf("\n删除关键字为4和9的结点：");
    Delete(bt, 4);
    Delete(bt, 9);
    Disp(bt);
    return 0;
}
