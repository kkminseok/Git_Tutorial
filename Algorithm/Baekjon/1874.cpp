#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;

void Solution()
{
	int n;
	cin >> n;
	stack<int> s;
	queue<char> q;
	bool* check = new bool[n + 1];
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		if (s.empty())
		{
			for (int j = 1; j <= input; ++j)
			{
				if (j == input && check[j] == true )
				{
					cout << "No";
					return;
				}
				else if (check[j] == true)
					continue;
				
				s.push(j);//처음들어온 값까지 push
				check[j] = true;
				q.push('+');
			}
			s.pop();
			q.push('-');
		}
		else
		{

			if (s.top() < input)
			{
				if (check[input] == true)
				{
					cout << "No" << '\n';
					return;
				}
				for (int j = s.top() + 1; j <= input; ++j)
				{
					if (check[j] == true)
						continue;
					s.push(j);
					check[j] = true;
					q.push('+');
				}
				s.pop();
				q.push('-');
			}
			else
			{
				for (int j = s.top(); j >= input; --j)
				{
					if (!s.empty())
					{
						s.pop();
						q.push('-');
					}
				}
			}
		}
	}
	int qsize = q.size();
	for (int i = 0; i < qsize; ++i)
	{
		cout << q.front() << '\n';
		q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution();
}