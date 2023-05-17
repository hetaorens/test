#include<stdio.h>
#include<stdlib.h>
int my_add(int x,int y)
{
    return x+y;
}

int main()
{
    printf("%d",my_add(0x10,0x20));
    return 0;
}