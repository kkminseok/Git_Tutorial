#include<iostream>

using namespace std;

int partition(int num)
{
	int result = num;
	int size = 0;
	while (result != 0)
	{
		result /= 10;
		++size;
	}
	result = num;
	int temp = pow(10, size-1);
	for (int i = 0; i < size; ++i)
	{
		result += (num / temp);
		num = num % temp;
		temp /= 10;
	}

	return result;
}

void Solution()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int result = partition(i);
		if (result == n)
		{
			cout << i; return ;
		}
		
	}
	cout << "0" << '\n';

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}