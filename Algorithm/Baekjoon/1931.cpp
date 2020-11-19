#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
class temp
{
public:
	int start;
	int end;
};

bool compare1(temp& a, temp& b)
{
	if (a.end == b.end)
	{
		if (a.start == b.start)
			return a.start < b.start;
		return a.start < b.start;
	}
	else
		return a.end < b.end;
}
bool compare2(temp& a, temp& b)
{
	if (a.start == b.start)
	{
		if (a.end < b.end)
			return true;
		return (a.end - a.start) < (b.end - b.start);
	}
	else
	{
		return a.end < b.end;
	}
}
int main()
{
	using namespace std;

	int n;//회의 수e
	int result = 0;// 최종 카운트 값
	int now = 0;// 현재시각
	scanf("%d", &n);
	getchar();
	temp* meet = new temp[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> meet[i].start >> meet[i].end;
	}
	sort(meet, meet + n, compare1);

	now = meet[0].end;// 가장 빨리 끝나는게 처음으로 나와야함.
	++result;

	sort(meet + 1, meet + n, compare2);
	/*for (int i = 0; i < n; ++i)
	{
		cout << meet[i].start << " " << meet[i].end << endl;
	}*/
	for (int i = 1; i < n; ++i)
	{
		if (now > meet[i].start)
			continue;
		else
		{
			now = meet[i].end;
			++result;
		}
	}
	cout << result;



}