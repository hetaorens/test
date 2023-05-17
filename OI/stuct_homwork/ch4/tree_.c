#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
struct BTNode // 定义结点
{
    int element;                    //元素域
    struct BTNode *lchild, *rchild; //左孩子、右孩子指针
};
struct BTree //定义二叉树
{
    struct BTNode *root; //定义根节点指针
};
struct BTNode *NewNode(int x, struct BTNode *lc, struct BTNode *rc)
{                                                                      //该函数用于创建新节点，函数返回值为一个指针，指向新节点地址
    struct BTNode *p = (struct BTNode *)malloc(sizeof(struct BTNode)); //动态分配空间
    p->element = x;                                                    //该节点元素值为x
    p->lchild = lc;                                                    //该节点左孩子位于lc地址处
    p->rchild = rc;                                                    //该节点右孩子位于rc地址处
    return p;                                                          //返回该节点的地址
}
struct BTNode *BTreeCreateFromRoot()
{ //递归函数，从根开始创建二叉树结点，返回根节点的指针。
    int x;
    struct BTNode *t; //定义一个指针t和一个变量x
    scanf("%d", &x);  //输入新节点的值，-1表示空结点
    if (x == -1)
        return NULL;                   //若为-1返回一个空结点
    t = NewNode(x, NULL, NULL);        //若不是-1，则创建新节点，元素为x，暂时令左右孩子为空
    t->lchild = BTreeCreateFromRoot(); //创建左孩子节点
    t->rchild = BTreeCreateFromRoot(); //创建右孩子节点
    return t;
}
void BTreeCreate(struct BTree *tr) //创建新二叉树
{
    tr->root = BTreeCreateFromRoot(); //从根节点开始创建
}
struct BTNode *NewNode(int x, struct BTNode *lc, struct BTNode *rc)
{                                                                      //该函数用于创建新节点，函数返回值为一个指针，指向新节点地址
    struct BTNode *p = (struct BTNode *)malloc(sizeof(struct BTNode)); //动态分配空间
    p->element = x;                                                    //该节点元素值为x
    p->lchild = lc;                                                    //该节点左孩子位于lc地址处
    p->rchild = rc;                                                    //该节点右孩子位于rc地址处
    return p;                                                          //返回该节点的地址
}

struct BTNode *BTreeCreateFromRoot()
{ //递归函数，从根开始创建二叉树结点，返回根节点的指针。
    int x;
    struct BTNode *t; //定义一个指针t和一个变量x
    scanf("%d", &x);  //输入新节点的值，-1表示空结点
    if (x == -1)
        return NULL;                   //若为-1返回一个空结点
    t = NewNode(x, NULL, NULL);        //若不是-1，则创建新节点，元素为x，暂时令左右孩子为空
    t->lchild = BTreeCreateFromRoot(); //创建左孩子节点
    t->rchild = BTreeCreateFromRoot(); //创建右孩子节点
    return t;
}
void BTreeCreate(struct BTree *tr) //创建新二叉树
{
    tr->root = BTreeCreateFromRoot(); //从根节点开始创建
}

void PrintPreOrderFromRoot(struct BTNode *node)
{ //从根节点先序遍历，参数node为目前根节点
    if (node == NULL)
        return;                          //若为空树则返回
    printf("%d ", node->element);        //输出该节点的值
    PrintPreOrderFromRoot(node->lchild); //先序遍历左子树
    PrintPreOrderFromRoot(node->rchild); //先序遍历右子树
}
void PrintPreOrder(struct BTree tr)
{                                   //接口函数，对二叉树tr进行先序遍历。
    PrintPreOrderFromRoot(tr.root); //从根节点开始递归
    puts("");                       //输出一个回车
}
void PrintInOrderFromRoot(struct BTNode *node)
{ //从根节点中序遍历，参数node为根节点
    if (node == NULL)
        return;                         //若为空则返回
    PrintInOrderFromRoot(node->lchild); //中序遍历左子树
    printf("%d ", node->element);       //输出根节点值
    PrintInOrderFromRoot(node->rchild); //中序遍历右子树
}
void PrintInOrder(struct BTree tr)
{                                  //接口函数，对二叉树tr进行中序遍历。
    PrintInOrderFromRoot(tr.root); //从根节点开始递归
    void PrintPostOrderFromRoot(struct BTNode * node)
    { //从根节点后序遍历，参数node为根节点
        if (node == NULL)
            return;                           //若为空则返回
        PrintPostOrderFromRoot(node->lchild); //后序遍历左子树
        PrintPostOrderFromRoot(node->rchild); //后序遍历右子树
        printf("%d ", node->element);         //输出根节点的值
    }
}
void PrintPostOrder(struct BTree tr)
{                                    //接口函数，对二叉树tr进行后序遍历。
    PrintPostOrderFromRoot(tr.root); //从根节点开始递归
    puts("");                        //输出一个回车
}
int GetLeafNumbersFromRoot(struct BTNode *p) //递归函数，统计以p为根的子树上叶节点个数
{
    if (p == NULL)
        return 0;                                    //若为空返回0
    int lcount = GetLeafNumbersFromRoot(p->lchild);  //统计左子树上的叶节点个数
    int rcount = GetLeafNumbersFromRoot(p->rchild);  //统计右子树上的叶节点个数
    return lcount + rcount + (lcount + rcount == 0); //两者求和
}
int GetLeafNumbers(struct BTree tr)
{                                           //递归接口，统计整棵树上的叶节点个数
    return GetLeafNumbersFromRoot(tr.root); //直接返回从根统计的值
}
int GetNodeNumbersFromRoot(struct BTNode *p) //递归函数，统计以p为根的子树上节点个数
{
    if (p == NULL)
        return 0;                                   //若为空返回0
    int lcount = GetNodeNumbersFromRoot(p->lchild); //统计左子树上的节点个数
    int rcount = GetNodeNumbersFromRoot(p->rchild); //统计右子树上的节点个数
    return lcount + rcount + 1;                     //两者求和并加上自身节点为结果
}
int GetNodeNumbers(struct BTree tr)
{                                           //递归接口，统计整棵树上的节点个数
    return GetNodeNumbersFromRoot(tr.root); //直接返回从根统计的值
}
int GetDepthFromRoot(struct BTNode *p) //递归函数，统计以p为根的子树的高度
{
    if (p == NULL)
        return 0;                                //若为空返回0
    int lcount = GetDepthFromRoot(p->lchild);    //统计左子树的高度
    int rcount = GetDepthFromRoot(p->rchild);    //统计右子树的高度
    int res = lcount > rcount ? lcount : rcount; //取两个高度较大的一个值
    return res + 1;                              //最终高度为较大值+1（包含了根节点）
}
int GetDepth(struct BTree tr)
{                                     //递归接口，统计整棵树的高度
    return GetDepthFromRoot(tr.root); //直接返回从根统计的值
}
void SwapLRFromRoot(struct BTNode *p) //交换以p为根节点的左右子树
{
    if (!p)
        return;                     //若p为空直接返回
    struct BTNode *tmp = p->lchild; //交换左右子树
    p->lchild = p->rchild;
    p->rchild = tmp;
    SwapLRFromRoot(p->lchild); //以左子树为根交换左右子树
    SwapLRFromRoot(p->rchild); //以右子树为根交换左右子树
}
void SwapLR(struct BTree *tr)
{                             //递归接口
    SwapLRFromRoot(tr->root); //从根节点开始递归
}
int main()
{
    int i, j;
    struct BTree btr;
    BTreeCreate(&btr);
    puts("Preorder:");
    PrintPreOrder(btr);
    puts("InOrder:");
    PrintInOrder(btr);
    puts("Postorder:");
    PrintPostorder(btr);
    printf("LeafNumbers:%d\n", GetLeafNumbers(btr));
    printf("NodeNumbers:%d\n".GetNodeNumbers(btr));
    printf("Depth:%d\n".GetDepth(btr)) : SwapLR(&btr);
    puts("PreorderAfterSwapLR:");
    PrintPreorder(btr);
    puts("InOrderAfterSwapLR:");
    PrintInorder(btr);
    return 0;
}