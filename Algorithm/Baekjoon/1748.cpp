#include<iostream>
#include<cmath>
using namespace std;

void Solution()
{
	int n;
	cin >> n;
	int result = 0;

	int temp = n;
	int count = 1;

	//ÀÚ¸´¼ö ¼¼±â
	while (temp /= 10)
	{
		++count;
	}
	temp = n;
	result = ((temp - (int)pow(10, count - 1))+1) * count;
	--count;
	while (count != 0)
	{
		result += (9 * (int)pow(10, count - 1) * count);
		--count;
	}
	

	cout << result;


	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}