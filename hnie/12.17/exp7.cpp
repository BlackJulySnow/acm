#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

#define MaxSize 100
typedef char ElemType;
int size;
struct Node{
    ElemType  data;
    Node * lc;
    Node * rc;
}bt;

void CreateBT(Node * &b, char * str){
    Node * St[MaxSize], * p;
    int top = -1,k,j = 0;char ch;
    b = NULL;
    ch = str[j];
    while (ch != '\0'){
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (Node * ) malloc(sizeof(Node));
                size++;
                p->data = ch;p->lc = p->rc = NULL;
                if(b == NULL)
                    b = p;
                else{
                    switch (k) {
                        case 1:
                            St[top]->lc = p;
                            break;
                        case 2:
                            St[top]->rc = p;
                            break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

void DestoryBT(Node * &b){
    if(b != NULL){
        DestoryBT(b->lc);
        DestoryBT(b->rc);
        free(b);
    }
}

Node * FindNode(Node * b,ElemType x){
    Node * p;
    if(b == NULL)
        return NULL;
    else if(b->data == x)
        return b;
    else{
        p = FindNode(b->lc,x);
        if(p != NULL)
            return p;
        else
            return FindNode(b->rc,x);
    }
}
int leafSize;
int SingleBranchNode;
int BTHeight(Node * b){
    int lch,rch;
    if(b == NULL) {
        return 0;
    }else{
        lch = BTHeight(b->lc);
        rch = BTHeight(b->rc);
        if(lch == 0 && rch == 0)
            leafSize++;
        if((lch == 0 && rch != 0) || (lch != 0 && rch == 0))
            SingleBranchNode++;
        return max(lch,rch) + 1;
    }
}

void DispBT(Node * b){
    if(b != NULL){
        printf("%c",b->data);
        if(b->lc != NULL || b->rc != NULL){
            printf("(");
            DispBT(b->lc);
            if(b->rc != NULL)
                printf(",");
            DispBT(b->rc);
            printf(")");
        }
    }
}

void PreOreder(Node * b){
    if(b != NULL){
        printf("%c",b->data);
        PreOreder(b->lc);
        PreOreder(b->rc);
    }
}

void InOrder(Node * b){
    if(b != NULL){
        InOrder(b->lc);
        printf("%c",b->data);
        InOrder(b->rc);
    }
}

void PostOrder(Node * b){
    if(b != NULL){
        PostOrder(b->lc);
        PostOrder(b->rc);
        printf("%c",b->data);
    }
}

int main() {
    char s[] = "A(B(C(,D),E(F)),G(H(I(J),K(,L)),M(N,P)))";
    Node * p,* g;
    CreateBT(p, s);
    printf("bt�ĸ߶�:%d\n", BTHeight(p));
    printf("bt���н������%d\n",size);
    printf("bt����Ҷ�ӽ������:%d\n",leafSize);
    printf("bt���е���֧�������:%d\n",SingleBranchNode);
    printf("�����������:");
    PreOreder(p);
    printf("\n�����������:");
    InOrder(p);
    printf("\n�����������:");
    PostOrder(p);
    g = FindNode(p,'G');
    printf("\n�ԡ�G��Ϊ���ڵ������:");
    DispBT(g);
    DestoryBT(p);
    DestoryBT(g);
    return 0;
}