```c++
#include <string>
	#include <vector>
	#include<iostream>
	#include<algorithm>
	using namespace std;
	const int MAX = 10001;

	int arr[MAX] = { 1,2,3, };
	int arr2[MAX] = { 0, };
	int arr3[MAX] = { 0, };
	int temp[5] = { 3,1,2,4,5 };
	int temp2[4] = { 1,3,4,5 };	

	bool pred(pair<int, int>& a, pair<int, int>& b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second > b.second;
	}

	vector<int> solution(vector<int> answers) {
		vector<int> answer;

		int init = 0;
		int init2 = 0;
		int init3 = 0;
		vector<pair<int, int>> vec;
		vec.push_back(make_pair(1, 0));
		vec.push_back(make_pair(2, 0));
		vec.push_back(make_pair(3, 0));
	
		for (int i = 0; i < MAX; ++i)
		{
			arr[i] = init % 5+ 1;
			++init;
			if (i % 2 == 0)
			{
				arr2[i] = 2;
			}
			else
			{
				arr2[i] = temp2[init2];
				init2++;
				if (init2 > 3)
					init2 = 0;
			}
			arr3[i] = temp[init3];
			if (i % 2 == 1)
			{
				init3++;
				if (init3 > 4)
					init3 = 0;
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			cout << arr2[i] << " ";
		}


		for (size_t i = 0; i < answers.size(); ++i)
		{
			if (answers[i] == arr[i])
				vec[0].second++;
			if (answers[i] == arr2[i])
				vec[1].second++;
			if (answers[i] == arr3[i])
				vec[2].second++;
		}
		sort(vec.begin(), vec.end(),pred);
		if (!(vec[0].second == 0))
		{
			for (size_t i = 0; i < vec.size(); ++i)
			{
				answer.push_back(vec[i].first);
				if (i + 1 < vec.size() && vec[i].second == vec[i + 1].second)
					continue;
				else
					break;
			}
		}



		return answer;
	}
```
