#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    ElemType element;
    struct node*link;
}Node;
typedef struct stack{
    Node*top;
}Stack;

void Push(Stack *S,ElemType x)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->element=x;
    p->link=NULL;
    p=>link=S-top;
    S->top=p;

}
void pop(Stack*S)
{
    if(S-top==NULL)
    {
        return ;

    }
    Node *p=S->top;
    S->top=p->link;
    free(p);
}


int main()
{

    return 0;
}