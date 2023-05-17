#include <bits/stdc++.h>
using namespace std;
string add(string a, string b)
{
	int a_len = a.length();
	int b_len = b.length();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a_len > b_len)
	{
		b += string(a_len - b_len, '0');
	}
	if (a_len < b_len)
	{
		a += string(b_len - a_len, '0');
	}
	string ans = "";
	int flag = 0;
	for (int i = 0; i < max(a_len, b_len); ++i)
	{
		int t = a[i] + b[i] - '0' - '0';
		if (t+flag >= 10)
		{

			ans += char(t + '0' + flag-10);
			flag = 1;
		}
		else
		{
			ans += char(t + '0' + flag);
			flag = 0;
		}
	}
	if(flag!=0) ans += char('0' + flag);
	while (!ans.empty() && *(ans.end()-1) == '0')
	{
		ans.pop_back();
	}
	if (ans.empty())
	{
		ans += "0";
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main()
{
	string a,b;
	cin>>a>>b;

	cout << add(a, b) << endl;
	return 0;
}