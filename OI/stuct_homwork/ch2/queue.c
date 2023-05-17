/*
队列(Queue)是限定数据元素的插入在表的一端,数据元素的删除在另一端
的线性结构
FIFO


ADT Queue{
    data: n个元素的线性序列允许的最大长度为maxSIze 
    && 0<=n<maxSize


    func:
        Create(!,maxszie)
        Destroy(Q)
        is_empty(Q);
        is_full(Q);
        Front(Q,x);
        EnQueue(Q,x);
        DEQueue(Q);
        clear(Q);
}
front queue_head
rear queue_tail

*/
/*
循环队列
chick empty
front==rear;
chick full
(rear+1)%maxsize==front

rear=(rear+1)%maxsize
front=(front+1)%maxsize
*/


#include<stdio.h>
#include<stdlib.h>
// typedef struct queue
// {
//     int front;
//     int rear;
//     int maxsize;
//     ElemType *element;
// }Queue;
typedef struc{
    int front;
    int rear;
    int maxSize;
    ElemType *element;

}Queue;
void Destroy(Queue *Q)
{
    free(Q->element);
    Q->maxsize=-1;
    Q->front=Q->rear=-1;
}


void Clear(Queue *Q)
{
    Q->front=Q->rear=0;
}
int is_empty(Queue *Q)
{
    return Q->front=Q->rear;
}
int is_full(Queue *Q)
{
    return (Q->rear+1)%Q->maxsize==Q->front;
}
int Front(Queue *Q,Elemtype *x)
{
    if(is_empty)
    {return 0;}
    else{

        *x=Q->element[(Q->front+1)%Q->maxsize];
        return true;
    }
}

int enQueue(Queue *Q,ELemType *x)
{
    if(is_full(Q))
    {
        return FALSE;
    }
    else{
        Q->rear=(Q->rear+1)%Q->maxsize;
        Q->element[Q->rear]=x;
        return true;
    }
}
int deQueue(Queue *Q)
{
    if(is_empty(Q)) return FALSE;
    else{
        Q->front=(Q->front+1)%Q->maxsize;
        return true;
    }
}
