#include "bits/stdc++.h"

#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
struct Node{
    int tag;
    union{
        char data;
        Node * sublist;
    }val;
    Node * link;
};

Node * CreateGL(char * &s){
    Node * g;
    char ch = * s++;
    if(ch != '\0'){
        g = (Node *) malloc(sizeof(Node));
        if(ch == '('){
            g->tag = 1;
            g->val.sublist = CreateGL(s);
        }else if(ch == ')')
            g = NULL;
        else if(ch == '#')
            g->val.sublist = NULL;
        else{
            g->tag = 0;
            g->val.data = ch;
        }
    }else
        g = NULL;
    ch = * s++;
    if(g != NULL){
        if(ch == ',')
            g->link = CreateGL(s);
        else
            g->link = NULL;
    }
    return g;
}
int GLLength(Node * g){
    int n = 0;
    g = g->val.sublist;
    while (g != NULL){
        n++;
        g = g->link;
    }
    return n;
}

int GLDepth(Node * g){
    int max = 0,dep;
    if(g->tag == 0)
        return 0;
    g = g->val.sublist;
    if(g == NULL)
        return 1;
    while (g != NULL){
        if(g->tag == 1){
            dep = GLDepth(g);
            if(dep > max)
                max = dep;
        }
        g = g->link;
    }
    return max + 1;
}
void DispGL(Node * g){
    if(g != NULL){
        if(g->tag == 0)
            printf("%c",g->val.data);
        else{
            printf("(");
            if(g->val.sublist == NULL)
                printf("#");
            else
                DispGL(g->val.sublist);
            printf(")");
        }
        if(g->link != NULL){
            printf(",");
            DispGL(g->link);
        }
    }
}
char maxAtom(Node * g){
    char max1,max2;
    if(g != NULL){
        if(g->tag == 0){
            max1 = maxAtom(g->link);
            return max(g->val.data,max1);
        }else{
            max1 = maxAtom(g->val.sublist);
            max2 = maxAtom(g->link);
            return max(max1,max2);
        }
    }
    return 0;
}
void Destroy(Node * &g){
    Node * g1,*g2;
    g1 = g->val.sublist;
    while (g1 != NULL){
        if(g1->tag == 0){
            g2 = g1->link;
            free(g1);
            g1 = g2;
        }else{
            g2 = g1->link;
            Destroy(g1);
            g1 = g2;
        }
    }
}
int main() {
    Node * g;
    char * str = "(A,(a1,d,(d,(#))),9,(t,(X,Y,Z)))";
    g = CreateGL(str);
    printf("�����g:");DispGL(g);printf("\n");
    printf("�����g�ĳ���:%d\n", GLLength(g));
    printf("�����g�����:%d\n", GLDepth(g));
    printf("���ԭ��:%c\n", maxAtom(g));
    Destroy(g);
    return 0;
}