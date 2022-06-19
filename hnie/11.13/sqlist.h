#define MAX_SIZE 110
typedef char Elemtype;
typedef struct
{
    Elemtype date[MAX_SIZE];
    int top;
}Stack;

void init_stack(Stack *&s)
{
    s->top = -1;
}

void push(Stack *&s, Elemtype e)
{
    s->date[++s->top] = e;
}

void pop(Stack *&s)
{
    s->top--;
}

int Stack_size(Stack *s)
{
    return s->top + 1;
}