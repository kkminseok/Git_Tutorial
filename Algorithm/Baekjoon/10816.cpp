#include<iostream>
#include<algorithm>

using namespace std;

void Solution()
{
	int n, m;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int temp = 0;
		cin >> temp;
		int result = upper_bound(arr, arr + n, temp) - lower_bound(arr, arr + n, temp);
		cout << result << " ";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}