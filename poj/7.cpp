#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

typedef struct qnode /*定义结构体指针*/
{
    int value;
    char sign;
    char decor;
    struct qnode* next;
    struct qnode* prior;
}qnode;

typedef struct linkqueue /*定义双端队列*/
{
    qnode* front, * rear;
    int len;
}linkqueue;

qnode* makeqnode(int value, char sign, char decor)/*创建结点并赋值*/
{
    qnode* p;
    if (p = (qnode*)malloc(sizeof(qnode)))
    {
        p->value = value;
        p->decor = decor;
        p->sign = sign;
        p->next = NULL;
        p->prior = NULL;
        return p;
    }
    fprintf(stderr, "向量空间分配失败！");
}

linkqueue* makelinkqnode(void)/*构造空链队列*/
{
    linkqueue * Q = (linkqueue *)malloc(sizeof(linkqueue));
    if (Q && (Q->front = (qnode *)malloc(sizeof(qnode))))/*创建头结点*/
    {
        Q->front->next = Q->front->prior= NULL;
        Q->rear = Q->front;
        Q->len = 0;
        return Q;
    }
    fprintf(stderr, "向量空间分配失败！");
}

void inrear(linkqueue * Q, qnode* p)/*在尾结点入队*/
{
    if (p)
    {   
        Q->rear->next = p;
        p->prior = Q->rear;
        Q->rear = p;
        p->next = NULL;
        printf("在尾结点入队%c\n", p->sign);
    }
    Q->len++;

}

qnode* outrear(linkqueue* Q)/*在队尾出队*/
{
    qnode* q = Q->rear;
    if (Q->rear->prior)
    {
        q->prior->next = q->next;
        Q->rear = q->prior;
        printf("在队尾出队%c\n", q->sign);
    }
    else { 
        Q->front->next = Q->front->prior = NULL;
        Q->rear = Q->front;
        printf("在队尾出队%c\n", q->sign);
    }
    
    Q->len--;
    return q;
}

qnode* outfront(linkqueue* Q)/*在队首出队*/
{
    
    qnode* q = Q->front->next;
    if (Q->len==1)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        printf("在队首出队%c\n", q->sign);
    }
    else if(q && q->next)
    {
        Q->front->next = q->next;
        q->next->prior = Q->front;
        printf("在队首出队%c\n", q->sign);  
    }
    Q->len--;
    return q;
}

void SendCards(linkqueue* Q)/*随机函数最初发牌*/
{
    int i, k, tag[52] = { 0 };
    char str1[] = { '\003','\004','\005','\006'};
    char str2[] = { '2', '3','4','5','6','7','8','9','T','J','Q','K','A' };
    int value[] = { 2,3,4,5,6,7,8,9,10,10,10,10,1 };
    srand(time(NULL));
    printf("手上牌：");
    for (int k = 0; k < 52;)
    {
        i = rand() % 52;
        if (tag[i] == 1) //表示该牌已经发出
        {                        
            continue;
        }
        else
        {
            tag[i] = 1;
            qnode* p = makeqnode(value[i / 4], str2[i / 4], str1[i % 4]);
            inrear(Q, p);
            k++;
            //printf("%c%c \n", p->decor,p->sign);
        }
     
    }
    printf("\n");

}

int AAB(linkqueue* Q, linkqueue* Qall)/*判断队首俩个数加队尾一个数之和*/
{
    int a = Q->front->next->value;
    int b = Q->front->next->next->value;
    int c = Q->rear->value;
    if ((a + b + c) % 10 == 0)
    {
        printf("\n执行AAB\n");
        inrear(Qall, Q->front->next);
        inrear(Qall, Q->front->next->next);
        inrear(Qall, Q->rear);
        outfront(Q);
        outfront(Q);
        outrear(Q);
        return 1;

    }
    return 0;
}

int ABB(linkqueue* Q, linkqueue* Qall)/*判断队首加俩队尾*/
{
    int a = Q->front->next->value;
    int b = Q->rear->value;
    int c = Q->rear->prior->value;
    if ((a + b + c) % 10 == 0)
    {
        printf("\n执行ABB\n");
        inrear(Qall, Q->front->next);
        inrear(Qall, Q->rear);
        inrear(Qall, Q->rear->prior);
        outfront(Q);
        outrear(Q);
        outrear(Q);
        return 1;

    }
    return 0;
}
int BBB(linkqueue* Q, linkqueue* Qall)/*判断3个队尾之和*/
{
    int a = Q->rear->value;
    int b = Q->rear->prior->value;
    int c = Q->rear->prior->prior->value;
    if ((a + b + c) % 10 == 0)
    {
        printf("\n执行BBB\n");
        inrear(Qall, Q->rear);
        inrear(Qall, Q->rear->prior);
        inrear(Qall, Q->rear->prior->prior);
        outrear(Q);                                 
        outrear(Q);
        outrear(Q);
        return 1;

    }
    return 0;
}
int sendcard(linkqueue** Qall)/*手上牌给牌堆发牌并判断*/
{
    int a=0;
    for (int i = 0; i < 7; i++)
    {
        
        if (Qall[i] && Qall[7]->len != 0)
        {
            qnode* p = outfront(Qall[7]);
            inrear(Qall[i], p);
            if (Qall[i]->len >= 3)
            {
                if (AAB(Qall[i], Qall[7]));
                else if (ABB(Qall[i], Qall[7]));
                else if (BBB(Qall[i], Qall[7]));
            }
            printf("第%d堆长度是%d\n", i, Qall[i]->len);
            a = a + Qall[i]->len;
            if (Qall[i]->len == 0)
            {
                free(Qall[i]->front);/*指针free后将其赋值为NULL，避免重复释放或使用*/
                Qall[i]->front = NULL;
                free(Qall[i]);
                Qall[i] = NULL;
                printf("第%d个牌堆被消除\n", i);
            }
            else {
                qnode* p1 = Qall[i]->front->next;
                qnode* p2 = Qall[7]->front->next;
                printf("\n牌堆%d:", i);
                while (p1) {
                    printf("%c", p1->sign);
                    p1 = p1->next;
                };/*输出牌堆*/
                printf("\n总牌堆:");
                while (p2) {
                    printf("%c", p2->sign);
                    p2 = p2->next;
                }

                printf("\n");
            }
        }

    }
    return a;
}

int main()
{
    linkqueue* Qall[8] = { NULL };/*队列结构数组*/
    for (int i = 0; i <= 7; i++)
    {
        Qall[i] = makelinkqnode();
    }/*初始化空链表*/
    SendCards(Qall[7]);/*随机函数发牌给手上堆*/
    do
    {
        int a=sendcard(Qall);/*每循环一次给7个牌堆*/
        printf("-------------------------------------------手上牌还剩%d\n",Qall[7]->len);
        printf("-------------------------------------------总牌数为%d\n",a+Qall[7]->len);
    } while (Qall[7]->len != 0 && Qall[7]->len != 52);
    if (Qall[7]->len == 0)printf("loss");
    else if (Qall[7]->len == 52)printf("win");
    else  printf("draw");

}
