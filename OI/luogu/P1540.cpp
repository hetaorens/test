#include <bits/stdc++.h>
using namespace std;
vector<int> queues;
int main()
{
    int M, N, temp, flag = 0, ans = 0;
    cin >> M >> N;
    for (int i = 0; i < N; ++i)
    {
        flag = 0;
        cin >> temp;
        for (auto ph : queues)
        {
            if (ph == temp)
            {
                flag = 1;
            }
        }
        // cout<<flag<<"  ";
        if (flag == 0)
        {
            if (queues.size() < M)
            {
                queues.push_back(temp);
                ++ans;
            }
            else
            {
                queues.erase(queues.begin());
                queues.push_back(temp);
                ++ans;
            }
        }
    }
    cout<<ans;
    return 0;
}