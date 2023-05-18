#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
struct node
{
    int x, y, e;
    bool operator<(const node &rhs) const
    {
        return e > rhs.e;
    }
} datas[maxN];

int n, T;
int par[maxN];
void init(int len)
{
    for (int i = 1; i <= len; i++)
        par[i] = i;
}
int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
void unite(int x, int y)
{
    if (!same(x, y))
        par[find(y)] = par[x];
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        vector<int> vec;
        bool flag = true;
        memset(datas, 0, sizeof(datas));
        memset(par, 0, sizeof(par));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &datas[i].x, &datas[i].y, &datas[i].e);
            vec.push_back(datas[i].x);
            vec.push_back(datas[i].y);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end()); // vector 的去重
        for (int i = 1; i <= n; i++)
        {
            datas[i].x = lower_bound(vec.begin(), vec.end(), datas[i].x) - vec.begin();
            datas[i].y = lower_bound(vec.begin(), vec.end(), datas[i].y) - vec.begin();
        }
        init(vec.end() - vec.begin()); // 这里用新的 vector 的长度来初始化并查集
        sort(datas + 1, datas + n + 1);
        for (int i = 1; i <= n; i++)
            if (datas[i].e)
                unite(datas[i].x, datas[i].y);
            else if (same(datas[i].x, datas[i].y))
                flag = false;
        printf("%s\n", flag ? "YES" : "NO");
    }
}