#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> vec1;
	vector<int>result(1000001);
	int n;
	cin >> n;
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec1.push_back(make_pair(temp,i));
	}
	sort(vec1.begin(), vec1.end());
	//중복제거
	int count = 0;
	int val = vec1[0].first;
	result[vec1[0].second] = 0;
	for (int i = 1; i < n; ++i)
	{
		if (val == vec1[i].first)
			result[vec1[i].second] = count;
		else
		{
			result[vec1[i].second] = ++count;
			val = vec1[i].first;
		}
		
	}
	for (int i = 0; i < n; ++i)
	{
		cout << result[i] << ' ';
	}
	
	

	return 0;
}