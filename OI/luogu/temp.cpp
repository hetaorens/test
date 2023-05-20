#include <iostream>
#include <vector>
using namespace std;
int getmaxgold(int n, int m, int k, const vector<string> &vec, const vector<vector<int>> &gold)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxgold = 0;
    dp[0][0] = 0;
    if (n > 1)
        dp[1][0] = gold[1][0] - (vec[0][0] == vec[1][0] ? 0 : k);
    if (m > 1)
        dp[0][1] = gold[0][1] - (vec[0][0] == vec[0][1] ? 0 : k);

    for (int j = 1; j < m; j++)
    {
        dp[0][j] = gold[0][j] + dp[0][j - 1] - (vec[0][j] == vec[0][j - 1] ? 0 : k);
        maxgold = max(maxgold, dp[0][j]);
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = gold[i][0] + dp[i - 1][0] - (vec[i][0] == vec[i - 1][0] ? 0 : k);
        maxgold = max(maxgold, dp[i][0]);

        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(dp[i][j - 1] - (vec[i][j] == vec[i][j - 1] ? 0 : k),
                           dp[i - 1][j] - (vec[i][j] == vec[i - 1][j] ? 0 : k)) +
                       gold[i][j];
            maxgold = max(maxgold, dp[i][j]);
        }
    }

    return maxgold;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    vector<vector<int>> gold(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> gold[i][j];
        }
    }

    cout << getmaxgold(n, m, k, vec, gold);

    return 0;
}