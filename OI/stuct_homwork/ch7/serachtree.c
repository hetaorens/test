
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
typedef char ElemType;
typedef struct btnode {                 //二叉树结点结构体
	 ElemType element;
	 struct btnode* lChild;
	 struct btnode* rChild;
}BTNode;
typedef struct binarytree {             //二叉树结构体
	BTNode* root;
}BinaryTree;
void Create(BinaryTree* bt) {
	bt->root = NULL;
}
BTNode* NewNode(ElemType x, BTNode* ln, BTNode* rn) {         //创建一个新节点，ln、rn为新节点的左右孩子
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	p->element = x;
	p->lChild = ln;
	p->rChild = rn;
	return p;
}
int Root(BinaryTree* bt, ElemType* x) {                       //查找二叉树的根节点
	if (bt->root) {
		x = &bt->root->element;
		return true;
	}
	else
		return false;
}
void MakeTree(BinaryTree* bt, ElemType e, BinaryTree* left, BinaryTree* right) {
	if (bt->root || left == right)
		return;
	bt->root = NewNode(e, left->root, right->root);
	left->root = right->root = NULL;
}
void PreOrderTree(BinaryTree* bt);
void PreOrder(BTNode* t);
void InOrderTree(BinaryTree* bt);
void InOrder(BTNode* t);
void PostOrderTree(BinaryTree* bt);
void PostOrder(BTNode* t);
void TreeClear(BinaryTree* bt);
/*----------------二叉树的结点个数---------------*/
int Size(BTNode* t) {
	if (!t)
		return 0;
	else
		return Size(t->lChild) + Size(t->rChild) + 1;
}
int TreeSize(BinaryTree* bt) {            
	return Size(bt->root);
}
/*---------------二叉树的叶节点个数-----------------*/
int Leaf(BTNode* t) {
	if (!t)
		return 0;
	else if (t->lChild == NULL && t->rChild == NULL) {
		return 1;
	}
	else
		return Leaf(t->lChild) + Leaf(t->rChild);
}
int TreeLeaf(BinaryTree* bt) {
	return Leaf(bt->root);
}
/*--------------二叉树结点的高度--------------------*/
int Height(BTNode* t) {
	int lheight, rheight;
	if (!t)
		return 0;
	else {
		lheight = Height(t->lChild);
		rheight = Height(t->rChild);
	}
	return max(lheight, rheight) + 1;
}
int Height(BinaryTree* bt) {
	return Height(bt->root);
}
/*--------------------二叉树的左右子树交换---------------------*/
void ExchangeTree(BTNode* t) {
	if (!t)
		return;
	else {
		BTNode* temp;
		temp = t->lChild;
		t->lChild = t->rChild;
		t->rChild = temp;
		ExchangeTree(t->lChild);
		ExchangeTree(t->rChild);
	}
}
void ExchangeTree(BinaryTree* bt) {
	ExchangeTree(bt->root);
}
void Clear(BTNode* t);
int main() {
	BinaryTree a, b, x, y, z;
	Create(&a);
	Create(&b);
	Create(&x);
	Create(&y);
	Create(&z);
	MakeTree(&y, 'E', &a, &b);
	MakeTree(&z, 'F', &a, &b);
	MakeTree(&x, 'C', &y, &z);
	MakeTree(&y, 'D', &a, &b);
	MakeTree(&z, 'B', &y, &x);
	printf("先序遍历：");
	PreOrderTree(&z);
	printf("\n");
	printf("中序遍历：");
	InOrderTree(&z);
	printf("\n");
	printf("后序遍历：");
	PostOrderTree(&z);
	cout << endl;
	cout << "二叉树结点个数:" << TreeSize(&z) << endl;
	cout << "叶节点个数：" << TreeLeaf(&z) << endl;
	cout << "二叉树的高度：" << Height(&z) << endl;
	cout << "----------左右子树交换---------" << endl;
	printf("交换前：先序遍历：");
	PreOrderTree(&z);
	cout << endl;
	ExchangeTree(&z);
	printf("交换后：先序遍历：");
	PreOrderTree(&z);
	cout << endl;
	TreeClear(&z);
	return 0;
}
void PreOrderTree(BinaryTree* bt) {                 //先序遍历
	PreOrder(bt->root);
}
void PreOrder(BTNode* t) {
	if (!t) {
		return;
	}
	printf("%c", t->element);                       //访问根结点
	PreOrder(t->lChild);                            //先序遍历左子树
	PreOrder(t->rChild);                            //先序遍历右子树
}
void InOrderTree(BinaryTree* bt) {                  //中序遍历
	InOrder(bt->root);
}
void InOrder(BTNode* t) {
	if (!t) {
		return;
	}
	InOrder(t->lChild);                             //中序遍历左子树
	printf("%c", t->element);                       //访问根结点
	InOrder(t->rChild);                             //中序遍历右子树
}
void PostOrderTree(BinaryTree* bt) {                //后序遍历
	PostOrder(bt->root);
}
void PostOrder(BTNode* t) {
	if (!t) {
		return;
	}
	PostOrder(t->lChild);                           //后序遍历左子树
	PostOrder(t->rChild);                           //后序遍历右子树
	printf("%c", t->element);                       //访问根结点
}
void TreeClear(BinaryTree* bt) {                    //清空二叉树
	Clear(bt->root);
}
void Clear(BTNode* t) {
	if (!t)
		return;
	Clear(t->lChild);
	Clear(t->rChild);
	free(t);
}

