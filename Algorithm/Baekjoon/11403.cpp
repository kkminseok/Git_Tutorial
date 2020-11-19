#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int arr[101][101] = { 0, };
int result[101][101] = { 0, };
bool v[101] = { 0, };
vector<int>* vec;
int N;
const int INF = 1000;
void Input()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
			
		}
	}


	//vec = new vector<int>[N + 1];
	//int temp;
	//for (int i = 0; i < N; ++i)
	//{
	//	for (int j = 0; j < N; ++j)
	//	{
	//		cin >> temp;
	//		if (temp == 1)
	//		{
	//			vec[i].push_back(j);
	//			vec[j].push_back(i);
	//		}
	//	}
	//}
}
void Floyd()
{
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (arr[i][k] ==1&& arr[k][j]== 1)
				{
					arr[i][j] =1;
				}
			}
		}
	}
}
//void bfs(int start)
//{
//	queue<int> q;
//	q.push(start);
//	while (!q.empty())
//	{
//		int x = q.front();
//		q.pop();
//		for (int i = 0; i < vec[x].size(); ++i)
//		{
//			cout << vec[x][i] << '\n';
//			if (v[vec[x][i]] == false)
//			{
//				v[vec[x][i]] = true;
//				q.push(vec[x][i]);
//			}
//		}
//	}
//}

void Solution()
{
	Input();
	Floyd();

	/*for (int i = 0; i < N; ++i)
	{
		memset(v, false, sizeof(v));
		bfs(i);
		for (int j = 0; j < N; ++j)
		{
			if (v[j] == true)
			{
				cout << i << " " << j;
				result[i][j] = 1;
			}
		}
	}*/
	//for (int i = 0; i < N; ++i)
	//{
	//	for (int j = 0; j < N; ++j)
	//		cout << result[i][j] << " ";
	//	cout << '\n';
	//}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}