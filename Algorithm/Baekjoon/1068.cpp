#include<iostream>
#include<vector>
using namespace std;
vector<int> v[51];
int removenode = 0;
int result = 0;
void DFS(int now)
{
	if (removenode == now)
		return;
	if (v[now].size() == 0)
	{
		++result;
		return;
	}
	else if (v[now].size() == 1)
	{
		if (v[now][0] == removenode)
		{
			++result;
		}
	}
	for (int i = 0; i < v[now].size(); ++i)
		DFS(v[now][i]);
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	int node = 0;
	int temp = 0;
	int remove = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp != -1)
		{
			v[temp].push_back(i);
		}
		else
			node = i;
	}
	cin >> removenode;
	DFS(node);
	cout << result;
	
	
}