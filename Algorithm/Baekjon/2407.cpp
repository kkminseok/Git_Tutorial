#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string dp[102][102];

string addnum(const string a, const string b)
{
	long long sum = 0;
	string copy1(a), copy2(b);
	string ret;
	while (!copy1.empty() || !copy2.empty() || sum)
	{
		if (!copy1.empty())
		{
			sum += copy1.back() - '0';
			copy1.pop_back();
		}
		if (!copy2.empty())
		{
			sum += copy2.back() - '0';
			copy2.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string ncm(int n, int r)
{
	string& ret = dp[n][r];
	if (ret != "")
		return ret;
	else if (n == r || r == 0)
		return ret = '1';
	else
	{
		return ret = addnum(ncm(n - 1, r - 1) , ncm(n - 1, r));
	}
}

void solution()
{
	int n, r;
	cin >> n>>r;
	cout << ncm(n, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}