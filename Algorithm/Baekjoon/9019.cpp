#include<iostream>
#include<string>
#include<cstring>
#include<queue>

using namespace std;



int DoubleN(int x)
{
	x *= 2;
	if (x >= 10000)
		x %= 10000;
	return x;
}
int Single(int x)
{
	if (x != 0)
		return x - 1;
	else
		return 9999;
}

int Left(int x)
{
	return ((x*10)%10000) + (x/1000);
}

int Right(int x)
{
	return ((x%10)*1000) + (x/10);
}

//a->b
string bfs(int a, int b)
{
	bool v[10001];
	memset(v, false, sizeof(v));
	queue<pair<int, string>> q;
	q.push(make_pair(a, ""));
	v[a] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		string logic = q.front().second;
		q.pop();
		//cout << x << '\n';
		if (x == b)
			return logic;
		//4가지 경우
		//1. Double
		int case1 = DoubleN(x);
		if (v[case1] == false)
		{
			v[case1] = true;
			q.push(make_pair(case1, logic + "D"));
		}

		//2. Single
		int case2 = Single(x);
		if (v[case2] == false)
		{
			v[case2] = true;
			q.push(make_pair(case2, logic + "S"));
		}

		//3. Left
		int case3 = Left(x);
		if (v[case3] == false)
		{
			v[case3] = true;
			q.push(make_pair(case3, logic + "L"));
		}

		//4. right
		int case4 = Right(x);
		if (v[case4] == false)
		{
			v[case4] = true;
			q.push(make_pair(case4, logic + "R"));
		}
			
		
	}

	return "";

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	int a, b;
	for (int i = 0; i < t; ++i)
	{
		cin >> a >> b;
		string result = bfs(a, b);
		cout << result<<'\n';
	}


	return 0;
}