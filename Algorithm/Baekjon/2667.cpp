#include<queue>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int result = 0;
string arr[25];
bool v[25][25] = { false, };
vector<int> vec;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int c = 0;

bool compare(int a, int b)
{
	if (a == 0 || b == 0)
		return false;
	return a < b;
}

bool bfs(int i, int j)
{
	int count = 0;
	if (arr[i][j] == '0')
		return false;
	if (v[i][j] == true)
		return false;
	v[i][j] = true;
	queue < pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newY = y + dy[k];
			int newX = x + dx[k];
			if (0 <= newX && newX < n && 0 <= newY && newY < n &&arr[newY][newX] == '1' && v[newY][newX] == false)
			{
				++count;
				v[newY][newX] = true;
				q.push(make_pair(newY, newX));
			}
		}
	}
	vec.push_back(count+1);
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bfs(i, j) == true ? ++result : result;
		}
	}
	cout << result<<'\n';
	int k = 0;
	sort(vec.begin(), vec.end(), compare);
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); ++it)
		cout << *it << '\n';
}