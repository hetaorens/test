typedef struc node{
    ElemType element;
    struct node *link;
}Node;

type struct queue{
    Node *front;
    Node *rear;
}Queue;
void EnQueue(Queue *Q,ElemType)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->element=x;
    p->link=NULL;
    Q->rear->link=p;
    Q->rear=p;
}
void DeQueue(Queue *Q)
{
    if(Q->front==NULL)
    {
        return;
    }
    Node*p=Q->front;
    Q->front=p->link;
    free(p);
    if(Q->front==NULL)
    {
        Q->rear=NULL;
    }
}