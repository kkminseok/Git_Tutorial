#include<iostream>

int findsum(int arr);

int main()
{
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int arr[10];
		int max = -1;
		int min = 5555;
		for (int j = 0; j < 10; ++j)
		{
			std::cin >> arr[j];
			int sum=findsum(arr[j]);
			if (sum > max)
				max = sum;
			if (sum < min)
				min = sum;
		}
		

		std::cout << "#"<<i+1<<' '<< max <<' '<< min << std::endl;
	}

	
}
int findsum(int arr)
{
	int sum = 0;
	while (arr != 0)
	{
		sum += arr % 10;
		arr /= 10;
	}
	return sum;
}