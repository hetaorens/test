#include <bits/stdc++.h>
using namespace std;

struct P4913_copy
{
    int left;
    int right;
    /* data */
} P4913[100000 + 5];

int n, ans;

void dfs(int id, int steps)
{
    if (id == 0)
        return;
    ans = max(steps, ans);
    dfs(P4913[id].left, steps + 1);
    dfs(P4913[id].right, steps + 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> P4913[i].left >> P4913[i].right;
    dfs(1, 1);
    cout << ans;
    return 0;
}