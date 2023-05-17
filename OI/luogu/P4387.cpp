#include <iostream>
#include <stack>
using namespace std;
stack<int> q;
int p, n;
int main()
{
    cin >> p;
    while (p--)
    {
        cin >> n;
        int a[n ], b[n ], sum = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            q.push(a[i]);
            while ((q.top()) == b[sum])
            {
                q.pop(), sum++;
                if (q.empty())
                    break;
            }
        }
        if (q.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        while (!q.empty())
            q.pop();
    }
    return 0;
}
