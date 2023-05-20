#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a, b;
    for (int i = 0; i < 1000; ++i)
    {
        a.push_back(i * 100);
        a.push_back(i * 100);
        b.push_back(i * 100);
        b.push_back(i * 100);

    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < b.size(); ++i)
    {
        b[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    }
    for(auto ph :b)
    {
        cout<< ph<<" ";
    }

    
    return 0;
}