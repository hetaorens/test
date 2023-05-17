// /*
// index(a[i]][j])={

// i(i+1)/2+j   if i>=j;

// j(j+i)/2+i if j>i

// }

// */
// /*
// sparseMatrix
// {
//     .data:
//         大多数元素一致的矩阵
//     .func:
//         CreateMatrix(M,row,cols)
//         Clear(M)
//         Transpose(M)

// }

// */

// #define maxSize 100
// typedef int ElemType;
// typedef struct term{
//     int  col,row;
//     ElemType value;

// }Term;
// typedef struct sparesmatrix{
//     int m,n,t;
//     Term table[maxSize];
// }SparseMatrix;
// /*
// 系数矩阵zuan'zhi'fa

// */

#include <stdio.h>
#include <stdlib.h>
typedef struct item
{
    int i, j, n;
} Item;
typedef struct t_matrix
{
    int lens;
    Item *table;
} T_matrix;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int cmp(const void *a, const void *b)
{
    if ((*(Item *)a).i == (*(Item *)b).i)
    {
        return ((*(Item *)a).j - (*(Item *)b).j);
    }
    else
    {
        return ((*(Item *)a).i - ((*(Item *)b)).i);
    }
}

int trs(T_matrix *T)
{
    for (int cur = 0; cur < T->lens; ++cur)
    {
        swap(&(T->table[cur].i), &(T->table[cur].j));
    }
    qsort(T->table,T->lens,sizeof(Item), cmp);
}
void out(T_matrix *T)
{
    for(int cur=0;cur<T->lens;++cur)
    {
        printf("<%d %d>:%d \n",T->table[cur].i,T->table[cur].j,T->table[cur].n);
    }
}
#include<mem.h>
#include<string.h>




// int main()
// {
//     Item list[7]={{0,1,2},{0,2,3},{1,2,3},{1,3,4},{0,1,2},{0,2,3},{1,2,3}};
//     T_matrix *T=(T_matrix*)malloc(sizeof(T_matrix));
//     T->lens=7;
    
//     T->table=list;
//     out(T);
//     printf("-------\n");
//     trs(T);
//     out(T);


//     return 0;
// }
 

 /*
快速T的work
.num数组求解;
for(int j=0;;j<n;++j) num[j]=0;
//OR memset(num,0,n);
for(int i=0;i<r;++i) ++num[A.table[i].col];
数组k中k[j]统计稀疏矩阵A中从0到j-1的非0元素的个数总和
K[j]吧表示A中j列第一个非零元素在转置稀疏矩阵B的行3元组中的下标
for(int j=0;j<n;++j)k[j]=0;
for(int j=1;j<n;++j)
k[j]=k[j-1]+num[j-1];


main_func:
快速转置的算法:
O(n+t)
for(int i=0;i<t;++t)
{
    int index=k[A.table[i].col]++;
    copy(B.table[index],A.table[i]);
}



 */

// int *num,*k;
// memset(num,0,len);
// memset(k,0,len);
// for(int i=0;i<len;++i) num[A.table[i].col]++;
// for(int i=1;i<len;++i) k[i]=k[i-1]+num[i-1]; 

// for(int i=0;i<len;++i)
// int index=k[table[i].col]++;
// copy(B.table[index],A.table[i]);



