#include<queue>
#include<iostream>

using namespace std;

long long A, B;
const long long MAX = 1000000000;

long long bfs(long long start)
{
	queue<pair<long long,int>> q;
	q.push(make_pair(start,1));
	while (!q.empty())
	{
		long long result = q.front().first;
		int count = q.front().second;
		q.pop();
		if (result > MAX || result>B)
		{
			continue;
		}
		else if(result == B)
		{
			return count;
		}
		else
		{
			q.push(make_pair(result * 2,count+1));
			q.push(make_pair(result * 10 + 1,count+1));
		}
	}
	return -1;
}

void Solution()
{
	cin >> A >> B;
	cout<<bfs(A);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}