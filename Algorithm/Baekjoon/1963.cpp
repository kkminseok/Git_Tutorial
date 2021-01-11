#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

const int MAX = 10001;

int T;
int first, second;
int tenes[MAX] = { 0, };
bool v[MAX] = { false };
int result = 0;

int cal(int one, int two, int three, int four)
{
	return one * 1000 + two * 100 + three * 10 + four;
}

int BFS()
{
	//첫번째는 first 두번째는 카운트값
	queue<pair<int, int>> q;
	q.push(make_pair(first, 0));
	v[first] = true;
	
	while (!q.empty())
	{
		int num = q.front().first;
		int count = q.front().second;
		if (num == second)
		{
			return count;
		}
		q.pop();
		
		int one = num / 1000;
		int two = (num % 1000) / 100;
		int three = (num % 100) / 10;
		int four = num % 10;
		for (int i = 0; i < 9; ++i)
		{
			
			one += 1;
			if (one > 9)
				one = 1;
			int result =  cal(one, two, three, four);
			if (v[result] == false && tenes[result] != 0)
			{
				q.push(make_pair(result, count + 1));
				v[result] = true;
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			//cout << "two : " << two << "\n";
			two += 1;
			if (two > 9)
				two = 0;
			int result = cal(one, two, three, four);
			if (v[result] == false && tenes[result] != 0)
			{
				q.push(make_pair(result, count + 1));
				v[result] = true;
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			//cout << "three : " << three << "\n";
			three += 1;
			if (three > 9)
				three = 0;
			int result = cal(one, two, three, four);
			if (v[result] == false && tenes[result] != 0)
			{
				q.push(make_pair(result, count + 1));
				v[result] = true;
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			four += 1;
			if (four > 9)
				four = 0;
			int result = cal(one, two, three, four);
			if (v[result] == false && tenes[result] != 0)
			{
				q.push(make_pair(result, count + 1));
				v[result] = true;
			}
		}
	}

	return -1;// 없음.
	
}
void Solve()
{
	
	//에라토스테네스의 체
	for (int i = 2; i < MAX; ++i)
	{
		tenes[i] = i;
	}
	for (int i = 2; i <= sqrt(MAX); ++i)
	{
		if (tenes[i] == 0)
			continue;
		for (int j = i + i; j < MAX; j += i)
			tenes[j] = 0;
	}
	
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		memset(v, false, sizeof(v));
		cin >> first >> second;
		result = BFS();
		if (result == -1)
			cout << "Impossible\n";
		else
			cout << result<<'\n';
		
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}