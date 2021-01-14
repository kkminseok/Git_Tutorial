#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
vector<int> vec[2001];
bool v[2001] = { false, };
void Input()
{
	cin >> n >> m;
	int person1, person2;
	for (int i = 0; i < m; ++i)
	{
		cin >> person1 >> person2;
		vec[person1].push_back(person2);
		vec[person2].push_back(person1);
	}

}

void dfs(int start,int count)
{
	if (count == 4)
	{
		cout << 1 << '\n';
		exit(1);
	}
	for (int i = 0; i < vec[start].size(); ++i)
	{
		if (!v[vec[start][i]])
		{
			v[start] = 1;
			dfs(vec[start][i], count + 1);
			v[start] = 0;
		}
	}
}

void Solve()
{
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		memset(v, false, sizeof(v));
		dfs(i, 0);
	}
	cout << 0 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
	
}