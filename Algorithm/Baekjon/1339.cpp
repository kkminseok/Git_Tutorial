#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>

int count = 0;
class alpha
{
public:
	int size;
	char eng;
	alpha()
	{
		size = 0;
		eng = 65 + count++;
	}
	bool operator<(alpha& b)
	{
		return this->size > b.size;
	}
};

bool sorted(std::string& a, std::string& b)
{
	return a.size() > b.size();
}
int main()
{
	using namespace std;
	alpha answer[26];
	int n;
	scanf("%d", &n);
	string* str = new string[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
	}
	sort(str, str + n, sorted);
	for (int i = 0; i < n; ++i)
	{
		
		for (size_t j = 0; j < str[i].size(); ++j)
		{
			answer[str[i][j] - 65].size += pow(10, str[i].size() - j - 1);
		}
	}
	sort(answer, answer + 26);
	int count = 9;
	int sum = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (answer[i].size == 0)
			break;
		sum += (count * answer[i].size);
		--count;
		
	}
	cout << sum;
}