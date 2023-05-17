/*
ADT set{
    .data:Elements and the length of data is maxlength


    .func:
        Crate();
        Destroy();
        is_empty();
        is_full();
        Search(k);
        inserct(x);
        Remove(k);

}



*/

typedef struct
{
    int n;
    int maxlength;
    ElemType *element;
}ListSet;
int SeqSearch(List L,ElemType x)
{
    int i;
    for(i=0;i<l.n;++i)
    {
        if(L.element[i]==x)
        {
            return i;
        }
        
    }
    return NOFind;
}
int SeqSerch_1(List L,ElemType x)
{
    int i;
    for(i=0;i<l.n;++i)
    {
        if(L.element[i]==x)
        {
            return i;  
        }
        else if(L.element[i]>x){
            return NOFind;

        }
        
    }
    return NOFind;
}


int SeqSerch_2(List L,ElemType x)
{
    int i;
    L.element[L.n]=MaxNum;
    for(i=0;L.element[i]<x;++i)
    {
        if(L.element[i]==x)
        {
            return i;
        }
        
    }
    return NOFind; 
}

/*
二分serch有序表
if len<=0 return ;
if len>0 get item and chick compare

if a.key=x.key return Y
if a.key>x.key Serch(0,m-1)
if a.key<x.key Serch(m+1,n-1)

a(low+high)/2
same as bserch
(0,(low+high)/2-1)
(low+high)/2+1,n-1


*/ 


// int BinSerch(List L,ElemType x)
// {
//     int i=BinSearch(L,x,0,n-1)
//     return i;
// }

// int BinSerach(List,ElemType x,int low,int high)

// {
//     if(low<=high)
//     {
//         int m=(high+low)/2;
//         if(x<L.element[m]) return BinSerach(L,x,low,m-1);
//         else if(x>L.element[m]) return BinSerach(L,x,m+1,high);
//         else
//         return m;
//     }
//     return -1;



// }