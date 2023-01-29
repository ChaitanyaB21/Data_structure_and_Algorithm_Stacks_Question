#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st, int n)
{
    st->size = n;
    st->top = -1;
    st->s = (int *)malloc(n * sizeof(int));
}

void Display(struct Stack st)
{
    for (int i = 0; i <= st.top; i++)
    {
        printf("%d ", st.s[i]);
    }
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        // continue;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

void pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
    }
    else
    {
        x = st->s[st->top];
        st->top--;

    }
}

void tanks(struct Stack *st, int A[], int n)
{
    push(st, A[0]);
    for (int i = 1; i < n; i++)
    {
        
        if (A[i] > 0)
        {
            
            push(st, A[i]);
        }

        else
        {

            if (st->s[st->top] == abs(A[i]))
            {
                
            }
            else if (st->s[st->top] < 0)
            {
                
                push(st, A[i]);
            }
            else if (st->s[st->top] > abs(A[i]))
            {
                
                printf("\n\n");
            }
            else if (st->s[st->top] < abs(A[i]))
            {
                while (st->s[st->top] < abs(A[i]) && st->top != -1 && st->s[st->top] != abs(A[i]) && st->s[st->top] > 0)
                {
                    
                    pop(st);
                };
                if (st->s[st->top] == abs(A[i]))
                {
                    pop(st);
                }
                else if (st->top == -1)
                {
                    push(st, A[i]);
                }
                else if (st->s[st->top] > abs(A[i]))
                {
                }
                else if(st->s[st->top] < 0){
                    push(st , A[i]);
                }
                
            }
            
        }
    }
}

int main()
{
    int numTank;
    scanf("%d", &numTank);
    int tankLis[numTank];
    for (int i = 0; i < numTank; i++)
    {
        scanf("%d", &tankLis[i]);
    }
    struct Stack st;
    create(&st, numTank);
    tanks(&st, tankLis, numTank);
    Display(st);
    return 0;
}
