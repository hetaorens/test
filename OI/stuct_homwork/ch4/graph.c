#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
typedef int ElemType;

typedef struct eNode //定义边结点
{
    int v, w;               // v表示边的终点，w表示边的权值
    struct eNode *nextnode; //通过链表实现，nextnode表示下一个指针域
} ENode;
typedef struct lGraph
{
    int n, e;  // n,e分别表示点的数量和边的数量
    ENode **a; //定义一个二级指针a，用于存放边。
} LGraph;

typedef struct mGraph
{
    int n, e, **a; // n,e,a分别表示点的个数、边的个数和矩阵的内容
} MGraph;
int InitGraph(MGraph *G, int capacity) // capacity为图的结点数
{                                      //该函数正常完成返回0，异常完成返回非0
    int i, j;
    G->a = (int **)malloc(4 * capacity); // a是个二级指针，对a分配一级指针空间，4等价于sizeof(int*)
    if (!G->a)
        return 1; //若分配失败返回1
    for (i = 0; i < capacity; i++)
        G->a[i] = (int *)malloc(4 * capacity); //对每个1级指针分配空间，4等价于sizeof(int)
    G->n = capacity;                           //将图的结点数置为n，边数置为0
    G->e = 0;
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
            G->a[i][j] = 999999999 * (i != j); //对i到j的距离赋最大值999999999，但i=j时，该结点赋值0。因此这里可以用(i!=j)逻辑表达式实现：不等时该值为1，a[i][j]结果为999999999*1=999999999，相等时该值为0，结果为999999999*0=0
    return 0;
}
int DestroyGraph(MGraph *G)
{                                               //该函数正常完成返回0，异常完成返回非0
    if (G->n <= 0 || G->e <= 0 || G->a == NULL) //如果是个空图直接返回1
        return 1;
    int i, j;
    for (i = 0; i < G->n; i++)
        free(G->a[i]); //释放每个一级指针的空间
    G->n = 0;
    G->e = 0;   //将图的结点数和边数置0
    free(G->a); //释放二级指针a指向的空间
    return 0;   //正常完成返回0
}
int IsExistEdge(MGraph *G, int u, int v)                    //判断u到v的边是否存在
{                                                           //该函数用于判断边是否存在，若不存在为0，存在为1
    if (u < 0 || v < 0 || u >= G->n || v >= G->n || u == v) //遇到非法输入，自动判定不存在
        return 0;
    if (G->a[u][v] == 999999999) //若两个点之间距离为最大值999999999，判定边不存在
        return 0;
    return 1; //其余情况判定边存在
}
int AddEdge(MGraph *G, int u, int v, int w) //在u和v之间增加一条长度为w的边
{                                           //该函数正常完成返回0，异常完成返回非0
    if (u < 0 || v < 0 || u >= G->n || v >= G->n || u == v || G->a[u][v] != 999999999)
        return 1;   //若输入数据非法，或者这一条边已经存在，返回1退出
    G->a[u][v] = w; //将该边的长度赋值为w
    ++G->e;         //注意边增加了一条
    return 0;       //正常退出 ，返回0
}
int DeleteEdge(MGraph *G, int u, int v)                     //在图G中删除从u到v的单向边
{                                                           //该函数正常完成返回0，异常完成返回非0
    if (u < 0 || v < 0 || u >= G->n || v >= G->n || u == v) //非法输入返回1
        return 1;
    if (G->a[u][v] == 999999999) //边不存在返回1
        return 1;
    G->a[u][v] = 999999999; //将边的数量置为最大值999999999
    --G->e;                 //边减少一条
    return 0;
}
int PrintGraph(MGraph *G)
{                                  //该函数正常完成返回0，异常完成返回非0
    if (G->n <= 0 || G->a == NULL) //若图没有初始化，返回1并退出
        return 1;
    int i, j;
    printf("N=%d E=%d\n", G->n, G->e); //输出图中顶点个数和边个数
    for (i = 0; i < G->n; i++)
    {
        for (j = 0; j < G->n; j++)
            printf("%9d ", G->a[i][j]); //输出点i到点j的距离
        puts("");                       // j循环每完成一次，打一个回车
    }
    puts(""); //所有输出结束后，打一个回车
    return 0;
}
int InitGraph(LGraph *G, int capacity) //建立一个有capacity个顶点的图
{                                      //该函数正常完成返回0，异常完成返回非0
    int i, j;
    G->a = (ENode **)malloc(4 * capacity); //分配一级指针域，4等价于sizeof(ENode*)
    if (!G->a)
        return 1;                  //如果分配空间失败，返回1退出
    for (i = 0; i < capacity; i++) //置空所有指针域
        G->a[i] = NULL;
    G->n = capacity; //将图的点数设为capacity，边数设为0
    G->e = 0;
    return 0; //正常退出返回0
}
int DestroyGraph(LGraph *G)
{ //该函数正常完成返回0，异常完成返回非0
    if (G->n <= 0 || G->a == NULL)
        return 1; //如果图已经是空，返回1退出
    int i, j;
    ENode *p, *q;
    for (i = 0; i < G->n; i++)
    {
        p = G->a[i]; //对指针数组a中的每个指针域进行操作
        q = p;
        while (p) //由于a中存放了n个链表，因此该操作与删除链表中的所有元素完全一致
        {
            p = p->nextnode;
            free(q);
            q = p;
        }
    }
    free(G->a);
    G->e = G->n = 0; //最后释放指针域a，并将n和e清零
    return 0;
}
int IsExistEdge(LGraph *G, int u, int v)
{                                                           //判断u和v之间是否存在边，若存在返回1，不存在返回0
    if (u < 0 || v < 0 || u >= G->n || v >= G->n || u == v) //若输入越界或u和v相等，返回0
        return 0;
    ENode *p = G->a[u]; //起点u确定后，从遍历链表a[u]，在里面寻找终点为v的边结点
    while (p)
    {
        if (p->v == v)
            return 1; //若找到了返回1，否则查询下一个结点
        p = p->nextnode;
    }
    return 0; //若没有找到，返回0表示该边不存在
}
int AddEdge(LGraph *G, int u, int v, int w)
{ //该函数正常完成返回0，异常完成返回非0
    int i, j;
    if (u < 0 || v < 0 || u >= G->n || v >= G->n || u == v)
        return 1; //若输入非法，返回1
    if (IsExistEdge(G, u, v))
        return 1;                              //若边已经存在，返回1
    ENode *p = (ENode *)malloc(sizeof(ENode)); //建立一个新的边结点
    p->v = v;
    p->w = w;              //对新节点的终点和权值赋值
    p->nextnode = G->a[u]; //在单链表a[u]的最前面插入新节点
    G->a[u] = p;
    ++G->e; //注意边的数量要+1
    return 0;
}
int DeleteEdge(LGraph *G, int u, int v)
{ //该函数正常完成返回0，异常完成返回非0
    int i, j;
    if (u < 0 || v < 0 || u >= G->n || v >= G->n)
        return 1; //若输入非法返回1
    if (!IsExistEdge(G, u, v))
        return 1; //若边不存在返回1
    ENode *p = G->a[u], *q = NULL;
    while (p && p->v != v) //在单链表a[u]中删除对应元素
    {
        q = p;
        p = p->nextnode;
    }
    if (!p)
        return 1; //若未查找到该边返回1表示删除失败
    if (q)
        q->nextnode = p->nextnode; //若找到了则删除该边结点
    else
        G->a[u] = p->nextnode; ///需要判断被删除结点是否在链表表头
    free(p);                   //释放被删除的结点，图的边数减少1
    --G->e;
    return 0;
}
int PrintGraph(LGraph *G)
{
    if (G->a == NULL || G->n <= 0)
        return 1;
    int i, j;
    printf("N = %d , E = %d\n", G->n, G->e); //输出图的点数和边数
    for (i = 0; i < G->n; i++)
    {
        ENode *p = G->a[i];
        printf("%d: ", i);
        while (p) //通过单链表遍历的方法，每一行输出结点i可到达的结点，顺便输出权值。
        {
            printf("%d(w=%d)   ", p->v, p->w);
            p = p->nextnode;
        }
        puts(""); //每遍历完一个结点，输出1个回车
    }
    puts(""); //整张图输出结束后，再输出一个回车
}
int DFS(LGraph *G, int v, int *visited) // v为目前所在结点，visited为传过来的数组
{
    int i, j;
    printf("%d ", v);   //输出该节点
    visited[v] = 1;     //对该节点进行标记
    ENode *p = G->a[v]; //以该节点为起点遍历，寻找尚未被访问过的点
    while (p)
    {
        if (!visited[p->v]) //若找到没有被访问过的点，递归地进行调用
        {
            visited[p->v] = 1;
            DFS(G, p->v, visited);
        }
        p = p->nextnode; //寻找下一个可以访问的点
    }
    return 0;
}
int BFS(LGraph *G, int vs, int *visited) // vs表示搜索起点
{
    int *que = (int *)malloc(4 * G->n + 8), l = -1, r = -1; //建立队列，最大为n
    int i, j;
    visited[vs] = 1; //将起点标记并入队
    que[++r] = vs;
    while (l < r)
    {
        ENode *p = G->a[l + 1]; //取队头元素，开始遍历可到达的的点
        while (p)
        {
            if (!visited[p->v]) //若找到未被遍历的点，将其入队并标记
            {
                que[++r] = p->v;
                visited[p->v] = 1;
            }
            p = p->nextnode; //寻找下一个结点
        }
        printf("%d ", que[++l]); //输出当前节点，并将该节点出队
    }
    return 0;
}
// int main()
// {
//     int i, j, n, m;
//     scanf("%d%d", &n, &m);
//     MGraph Gr;
//     InitGraph(&Gr, n);
//     for (i = 0; i < mji++)
//     {
//         int x, y, z;
//         scanf("%d%d%d", &x, &y, &z);
//         AddEdge(&Gr, x, y, z);
//     }
//     PrintGraph(&Gr);
//     int T;
//     scanf("%d", &T);
//     while (T--)
//     {
//         int x, y;
//         scanf("%d%d", &x, &y);
//         DeleteEdge(&Gr, x, y);
//     }
//     PrintGraph(&Gr);
//     DestroyGraph(&Gr);
//     return 0;
// }
int main()
{
    int i, j, n, m;
    LGraph Gr;
    scanf("%d%d", &n, &m);
    InitGraph(&Gr, n);
    for (i = 0; i < m; i++)
    {
        int x, y, Z;
        scanf("%d%d%d", &x, &y);
        AddEdge(&Gr, x, y, z);
    }
    PrintGraph(&Gr);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        DeleteEdge(&Gr, x, y);
    }
    PrintGraph(&Gr);
    DFSGraph(&Gr);
    BFSGraph(&Gr);
    DestroyGraph(&Gr);
    return 0;
}
