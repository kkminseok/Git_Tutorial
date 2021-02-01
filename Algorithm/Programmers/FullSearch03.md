```c++
#include <string>
#include <vector>
#include<iostream>

using namespace std;

bool checking(int tempbrown, int tempyellow, int brown, int yellow)
{
	for (int i = yellow; i > 0; --i)
	{
		if (yellow%i == 0)
		{
			if (tempbrown > i && tempyellow - 1 > (yellow / i))
			{
				cout << tempbrown << " " << tempyellow << " " << i << " " << yellow << '\n';
				return true;
			}
		}
	}
	return false;
}

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	vector<int> sosu;
	int sum = brown + yellow;
	sosu.push_back(1);
	for (int i = 2; i <= yellow / 2; ++i)
	{
		if (yellow%i == 0)
		{
			sosu.push_back(i);
			cout << i<<" ";
		}
	}

	for (size_t i =0 ; i<sosu.size();++i)
	{
		int div = yellow / sosu[i];
		int result = (div + sosu[i] + 2) * 2;
		if (result == brown)
		{
			answer.push_back(div + 2);
			answer.push_back(sosu[i] + 2);
			break;
		}
	}
	return answer;
}
```
