#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int top;
    int maxSize;
    ElemType *element;
}Stack;
void DeStroy(Stack *S)
{
    S->maxSize=-1;
    free(S->element);
    S->top=-1;
}
void Clear(Stack *S)
{
    S->top=-1;
}
void Creat(Stack *S,int msize)
{
    S->maxSize=msize;
    S->element=(ElemType*)malloc(sizeof(ElemType)*msize);
    S->top=-1;
}
int is_full(Stack *S)
{
    return S->top==S->maxSize-1;
}
int is_empty(Stack*S)
{
    return S->top==-1;


}
int get_top(Stack *s ,ElemType *x)
{
    if(is_empty(S))
    {
        return FALES;
    }
    *x=S->element[S->top];
    return true;
}
int Push(Stack*s,ElemType x)
{
    if(is_full(S))
    {
        return 0;
    }
    else{
        S->top++;
        S->element[S->top]=x;
        return true;
    }
}

int pop(Stack*S)
{
    if(is_empty(S))

    {
        return 0;
    }
    else{

        S->top--;
        return True;
    }
}
