#include <cstdio>
#include <cstdlib>
#include "sqlist.h"

using namespace std;

int main (){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init_stack(s);

    char a[MAX_SIZE];
    scanf("%s", a);

    for(int i = 0; a[i]; i ++)
    {
        if(a[i] == '(')
            push(s, a[i]);
        else if(s->date[s->top] == '(')
            pop(s);
        else if(Stack_size(s) <= 0 || s->date[s->top] == ')')
        {
            puts("NO");
            return 0;
        }
    }
    if(Stack_size(s) == 0) puts("YES");
    else puts("NO");
    return 0;
}
