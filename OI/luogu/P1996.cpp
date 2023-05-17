#include<bits/stdc++.h>
 
using namespace std;

int main()
{
    int m,n;
    cin>>n>>m;
    queue<int> a;
    for(int i=1;i<=n;++i) a.push(i);
    
    while(a.size()!=0)
    {   
        for(int i=0;i<m;++i)
        {
            if(i==m-1)
            {
                cout<<a.front()<<" ";
                a.pop();
            }  
            else{
                a.push(a.front());
                a.pop();
            }
        }    
    }    


    return 0;
}