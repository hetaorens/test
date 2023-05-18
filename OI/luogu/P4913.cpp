#include <iostream>
#define _for(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

const int MAXN = 1e6 + 10;

struct node
{
    int left, right;
};
node tree[MAXN];

int n, ans;

void dfs(int id, int deep)
{
    if (id == 0)
        return;
    ans = max(ans, deep);
    dfs(tree[id].left, deep + 1);
    dfs(tree[id].right, deep + 1);
}

int main()
{
    cin >> n;
    _for(i, 1, n) cin >> tree[i].left >> tree[i].right;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
