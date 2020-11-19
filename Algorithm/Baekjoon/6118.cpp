#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int N, M;
vector<int>* vec;
bool* check;
int* counting;

void Input()
{
	cin >> N >> M;
	vec = new vector<int>[N + 1];
	check = new bool[N + 1];
	memset(check, false, sizeof(bool) * (N+1));
	counting = new int[N + 1];
	memset(counting, 0, sizeof(int) * (N+1));
	for (int i = 0; i < M; ++i)
	{
		int a_i, b_i;
		cin >> a_i >> b_i;
		vec[a_i].push_back(b_i);
		vec[b_i].push_back(a_i);
	}
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); ++i)
		{
			if (check[vec[x][i]] == false)
			{
				check[vec[x][i]] = true;
				q.push(vec[x][i]);
				counting[vec[x][i]] = counting[x] + 1;
			}
		}
	}
}

void Solve()
{
	//bfs수행
	bfs(1);
	int max = 0; 
	int index = 0;
	int distance = 0;
	int cloneindex = 0;;
	for (int i = 0; i < N + 1; ++i)
	{
		//먼저 제일 먼 인덱스를 찾음
		if (max < counting[i])
		{
			cloneindex = 0;
			index = i;
			max = counting[i];
			distance = counting[i];
		}
		if (max == counting[i])
		{
			cloneindex++;
		}
	}
	cout << index << " " << distance << " " << cloneindex;
}

void Solution()
{
	Input();
	Solve();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution();

	return 0;
}