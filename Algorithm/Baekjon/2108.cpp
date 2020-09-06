#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
class arred
{
public:
	int count = 0;
	int index = 9999;

};

bool compareindex(arred& a, arred& b)
{
	return a.index < b.index;
}
bool comparecount(arred& a, arred& b)
{
	if (a.count == b.count)
		return a.index < b.index;
	return a.count > b.count;
}

int main()
{
	using namespace std;
	int n;
	arred arr[9000];
	scanf("%d", &n);
	int temp;
	double avg = 0;
	int max = -4001;
	int min = 9999;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		arr[temp + 4000].count++;
		arr[temp + 4000].index = temp;
		avg += temp;
		if (max < temp)
			max = temp;
		if (min > temp)
			min = temp;
	}
	avg /= n;
	int mid = 0;
	sort(arr, arr + 8001, compareindex);
	mid = arr[0].index;
	int result = 0;
	if (n != 1)
	{
		for (int i = 0; i < 8001; ++i)
		{
			result += arr[i].count;
			if (result >= (n / 2)+1)
			{
				mid = arr[i].index;
				break;
			}
		}
	}
	int countindex;
	sort(arr, arr + 8001, comparecount);
	if (arr[0].count == arr[1].count&& n!=1)
	{
		countindex = arr[1].index;
	}
	else
		countindex = arr[0].index;
	int sub = max - min;

	if (avg<1 && avg>-1)
		avg = 0;
	printf("%.0lf\n%d\n%d\n%d\n", avg, mid, countindex, sub);


}