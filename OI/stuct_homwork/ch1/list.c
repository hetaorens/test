#include<stdio.h>


int arr[100]={1,2,3,4};

void index_find(int index,int *ret)
{
    if(index<0||index>100){}
    else{
        *ret= arr[index];
    }
    return;
}


int main()
{

    for(int i=0;i<100;++i)
    {
        int ans;
        index_find(i,&ans);
        printf("%d\n",ans);
    }

    return 0;
}


BOOL SeqSearch(LinkedList *list,KeyType key)
{
    SNode *p=list->first;
    while(!p)
    {
        if(p->key==key) return TRUE;
        else if(p->key>key) return FALSE;
        p=p->link;
    }
    return FALSE;
}