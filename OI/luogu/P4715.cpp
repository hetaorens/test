#include <bits/stdc++.h>
using namespace std;
int maps[128];
int main()
{
    int n, a1, a2;
    cin >> n;
    for (int i = 0; i < (1 << n); ++i)
    {
        cin >> maps[i];
    }
    a1 = maps[0];
    a2 = maps[1 << n - 1];
    for (int i = 0; i < (1 << n - 1); ++i)
        a1 = max(a1, maps[i]);
    for (int i = (1 << n - 1); i < (1 << n); ++i)
        a2 = max(a2, maps[i]);
    // cout << min(a1, a2) << endl;
    int index = min(a1, a2);
    for (int i = 0; i < (1 << n); ++i)
    {
        if (maps[i] == index)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}