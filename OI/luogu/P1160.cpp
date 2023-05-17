#include <bits/stdc++.h>
using namespace std;

typedef struct P1160
{
    /* data */
    pair<int, int> cur;
    int flag = 1;
    P1160(int x, int y) : cur({x, y}) {}
} P1160;

int main()
{
    vector<P1160> a;

    vector<int> ans;

    a.push_back({-1, -1});
    a.push_back({0, -1});
    int N;
    cin >> N;
    int fn, flag;
    int head = 1;
    for (int i = 2; i <= N; ++i)
    {
        cin >> fn >> flag;
        if (flag == 1)
        {

            a.push_back({fn, a[fn].cur.second});
            if (a[fn].cur.second != -1)
            {
                a[a[fn].cur.second].cur.first = i;
            }
            a[fn].cur.second = i;
        }
        else
        {

            a.push_back({a[fn].cur.first, fn});
            if (a[fn].cur.first != 0)
            {
                a[a[fn].cur.first].cur.second = i;
            }
            a[fn].cur.first = i;
        }
        if (a[i].cur.first == 0)
        {
            head = i;
        }
    }
    int M, temp;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> temp;
        a[temp].flag = 0;
    }
    if (a[head].flag == 1)
    {
        ans.push_back(head);
    }
    while (a[head].cur.second != -1)
    {
        if (a[a[head].cur.second].flag == 1)
        {
            ans.push_back(a[head].cur.second);
        }

        head = a[head].cur.second;
    }
    for (auto ph : ans)
    {
        cout << ph << " ";
    }

    return 0;
}