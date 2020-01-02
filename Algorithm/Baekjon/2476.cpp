#include<cstdio>
#include<algorithm>

int check(int arr[])
{
	//3개 같은경우
	if (arr[0] == arr[1]&& arr[1]== arr[2])
	{
		return 10000 + (arr[0] * 1000);
	}
	else if (arr[0] == arr[1]||arr[0]==arr[2])//2개가 같은 경우.
	{
		return 1000 + (arr[0] * 100);
	}
	else if (arr[1] == arr[2])
	{
		return 1000 + (arr[1] * 100);
	}
	else//셋다 아닌경우
	{
		std::sort(arr, arr + 3);
		return arr[2] * 100;
	}
}

int main()
{
	//max가 정답.
	int n,max=0;
	int temp;
	const int size = 3;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		int arr[size] = { 0,0,0 };
		for (int j = 0; j < size; ++j)
			scanf("%d", &arr[j]);
		getchar();
		temp=check(arr);
		if (temp > max)
			max = temp;
	}
	printf("%d", max);

	return 0;
}
