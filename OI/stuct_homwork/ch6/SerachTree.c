 /*
 The define of BinarySerachTree
 any value1 !=value2
 (1).左子树不空则左子树上的节点的关键字均小于根节点的关键字
 (2).右子树为~(1)
 (3).左右子树也是二叉搜索树
 */
typedef int KeyType;
typedef struct entry
{
    KeyType Key;
    DataType Data;

}Entry;
typedef Entry T;
typedef struct btnode{
    T Element;
    struct btnode*LChild,*RChild;

}BTNode;
typedef struct btree{
    BTNode*Root;

}BTree;

//(1)若二叉树为空 return Find fail
//若节点小于value,Search LChild
//if node_value>value Search RChild
//if == return value

BOOL BtSearch(BTree Bt,KeyType k,T,*x)
{
    BTNode *p=Find(Bt.Root,k);
    if(p)
    {
        *x=p->Element;
        return TRUE;
    }
    return FALSE;
}

BOOL BtSearch(Btree Bt,KeyType k,T *x)
{
    BTNode *p=Bt.Root;
    while(p)
    {
        if(k<p->Element.key) p=p->LChild;
        else if(k>p->Element) p=p->RChild;
        else{
            *x=p->element;
            return TRUE;
        }
    }
    return FALSE;
}
BOOL Insert(Btree *Bt,T x)
{
    BTNode *p=Bt->Root,*q,*r;
    KeyType k =x.Key;
    while(p)
    {
        q=p;
        if(k<p->Element.Key)p=p->LChild;
        else if(k>p->Element.Key)p=p->RChild;
        else return FALSE;
        r=
    }
}
BTNode *Find(BTNode *p,keyType k)
{
    if(!p)
    return NULL;
    if(k==p->element.key)
        return p;
        if(k<p->elemenet.key)
            return Find(p->lChild,k);
    return Find(p->Rchild);
}
BOOL BtSearch(BTree Bt,Keytype k ,T*x)
{
    BTree *p=Find(Bt.root,k);
    if(p)
    {
        *x=p->element;
        return TRUE;

    }
    return FALSE;

}


/*
二叉搜索树删除元素的节点节点的左右孩子都为NULL
即叶子节点

直接del


del_item->root->child=NULL;
free(del_item)


*/

/*
(have only one Child )
func:
    del del_item->root->Child=del_item->child
    free(del_item)


*/

/*
(have two Child)
func.
    after del node ,choice one node to recover root
    and keep two guidelines
    1.keep Tree is orderly
    2.eazy to del

*/



/*
B树的定义 是m叉树或者空树
1.根节点至少有两个孩子根节点可以只有一个元素
2.出root Node elsenode at less have ceil(m/2)child
fail node at same layer



