#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
int main()
{
	using namespace std;
	int n;// n개만큼의 로프
	int count = 1;
	scanf("%d", &n);
	int* rope = new int[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &rope[i]);

	sort(rope, rope + n);
	int result = rope[n - 1];
	int temp = n;

	if (n != 1)
	{
		while (temp != 0)
		{
			if (result < rope[n - count - 1] * (count + 1))
			{
				result = rope[n - count - 1] * (count + 1);
				//cout << result << endl;
				++count;
				--temp;
			}
			else
			{
				--temp;
				++count;
			}
		}
	}
	cout << result;
}