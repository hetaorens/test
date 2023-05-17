/*
一维数组的存贮方式
Loc(a[i])=Loc(a[0])+i*k




*/


/*
ADT Array
{
    .data:
    The subscript:<i,value>
        
    .func:
    CreateArray(A,data);
    DestoryArray(A);
    RetrieveArray(A,index_);
    StoreArrayItem(A,index,x);
    Copy(A,B);

}


*/
typedef struct tdarray
{
    int m1,m2,m3;
    int*array;

}TDArray;
Status CreateArray(TDArray *tdarray,int m1,int m2,int m3)

{
    tdarray->m1=m1;
    tdarray->m2=m2;
    tdarray->m3=m3;
    tdattay->array=(int*)malloc(m1*m2*m3*sizeof(int));
    if(!d=tdarray->array) return Error;
    return True;
}

Status RetrieveArray(TDArray tdarray,int i1,int i2,int i3,int *x)
{
    if(!tdarray) return NotPresent;
    if(i1<0||i2<0||i3<0||i1>=tdarray.m1||i2>=tdarray.m2||i3>=tdarray.m2)
        return IllegalIndex;
    {
        *x=*(tdarray.array+i1*m2*m3+i2*m3+i3);
        return OK;
    }
}

Status StoreArrayItem(TDArray tdarray,int i1,int i2,int i3,int *x)
{
    if(!tdarray) return NotPresent;
    if(i1<0||i2<0||i3<0||i1>=tdarray.m1||i2>=tdarray.m2||i3>=tdarray.m2)
        return IllegalIndex;
    {
        *(tdarray.array+i1*m2*m3+i2*m3+i3)=x;
        return OK;
    }
}


