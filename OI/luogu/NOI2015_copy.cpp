#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
struct node
{
    int x, y, e;
    bool operator<(const node &rhs) const
    {
        return e > rhs.e;
    }
} datas[MAX_N];
int n, T;
int par[MAX_N];
void init(int len)
{
    for (int i = 1; i <= len; ++i)
    {
        par[i] = i;
    }
}
int find(int x)
{
    if (par[x] != x)
    {
        return par[x] = find(par[x]);
    }
    return x;
}
bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y)
{
    if (!same(x, y))
    {
        par[find(y)] = par[x];
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<int> vec;
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            cin >> datas[i].x >> datas[i].y >> datas[i].e;
            vec.push_back(datas[i].x);
            vec.push_back(datas[i].y);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        for (int i = 1; i <= n; ++i)
        {
            datas[i].x = lower_bound(vec.begin(), vec.end(), datas[i].x) - vec.begin();
            datas[i].y = lower_bound(vec.begin(), vec.end(), datas[i].y) - vec.begin();
        }
        init(vec.size());
        sort(datas + 1, datas + n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (datas[i].e)
            {
                unite(datas[i].x, datas[i].y);
            }
            else if (same(datas[i].x, datas[i].y))
            {
                /* code */
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
